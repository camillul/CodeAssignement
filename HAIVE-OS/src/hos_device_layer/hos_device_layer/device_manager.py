from typing import (Any, List)
import time
import sys
import argparse
import json

import rclpy
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from rclpy.subscription import Subscription
from rclpy.callback_groups import (MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup)
from rclpy.client import (Future, Client)
from std_msgs.msg import UInt32
from ament_index_python.packages import get_package_share_directory

from hos_device_layer.services import (CONNECT_DEVICE_SERVICE, DEVICE_API_CALL_SERVICE, DEVICE_COMMAND_SERVICE, 
                                       SERIALIZED_DEVICE_COMMAND_SERVICE, DEVICE_CONNECTION_INFOS_SERVICE, GET_STATE_API_CALL_SERVICE, SET_STATE_API_CALL_SERVICE)
from hos_device_layer.topics import (DEVICE_API_CALL_RESULT_TOPIC, DEVICE_PING_TOPIC, DEVICE_CMD_RESULT_TOPIC, DEVICE_STREAM_TOPIC,
                                     DEVICE_CONNECTED, DEVICE_TIMEOUT, DEVICE_RECONNECTED, DEVICE_DISCONNECTED)
from hos_device_layer.serializer import (CommandSerializer, CommandSerializerInfo)
from hos_interfaces.msg import (DeviceCommandResult, DeviceAPICallResult, TypedField, DeviceStream, ConnectionInfo)
from hos_interfaces.srv import (ConnectDevice, DeviceCommand, SerializedDeviceCommand, DeviceAPICall, DeviceConnectionInfos, GetStateAPICall)
from hos_device_layer.db import (Database, cast_db_type)
from hos_utils.counter import Counter
import hos_utils.airtable as Airtable
import hos_utils.file as FileUtils
from hos_utils.API import StateAPICallInfo, DeviceAPICallInfo, DeviceAPIArg
import hos_utils.hos as Hos
from hos_robot_state.constants import StateType
import hos_device_layer.hos_device_lib as DeviceLib

DEVICE_TIMEOUT_S = 20.0  # Time in seconds without receiving a device ping before declaring a device as timed out
DEVICE_CONNECTION_CHECK_INTERVAL_S = 5.0  # Interval time in seconds to invoke callback `_check_device_connections` for checking device timeouts
DISCONNECT_ON_TIMEOUT_COUNT = 3  # Number of `_check_device_connections` calls before declaring a timed out device as disconnected; disconnect time can be calculated as DISCONNECT_ON_TIMEOUT_COUNT * DEVICE_CONNECTION_CHECK_INTERVAL_S


node_name = 'device_manager'


class DeviceManager(Node):
  """
  Device manager is node that will subscribe and answer any service call from device, the hos_client allow the ESP/Device to directly send thos ROS events
  it handle also :
  - connection timeout
  - API command
  - ...
  """
  def __init__(self, fleet_name: str, load_db_from_file: bool = False):
    super().__init__(node_name)
    self._device_cmd_futures = []
    # Setup device db
    if load_db_from_file:
      error, db_data = Airtable.load_db_from_file(fleet_name)
      if error:
        raise ValueError(error)
    else:
      #here we get online database information, starting first by getting the authentification information
      auth_path = f"{get_package_share_directory('hos_utils')}/auth/airtable.json"

      auth_data, error = FileUtils.load_json(auth_path)
      if error:
        raise ValueError(error)

      error, db_data = Airtable.load_db(auth_data['ACCESS_TOKEN'], auth_data['BASE_ID'], fleet_name)
      if error:
        raise ValueError(error)
    #database infomation, please check db.py so more informatioj about Database class
    self._db = Database(db_data)

    # Setup device api serializers for current fleet
    fleet_ids = [f.device_id for f in self._db.get_fleet()]
    fleet_api_lists = []
    for device_id in fleet_ids:
      api_list = self._db.get_device_functions(device_id)
      if api_list == None:
        raise ValueError(f"Unable to load device functions from db for device `{device_id}`. Please check integrity of databse!")
      fleet_api_lists.append(api_list)
    fleet_api_serializers = []
    for api in [api for api_list in fleet_api_lists for api in api_list]:
       if api.api_serializer_id != None:
        serializer = self._db.get_api_serializer(api.function_name)
        if serializer == None:
          raise ValueError(f"Serializer databse id was found ({api.api_serializer_id}), but no serializer could be obtained from the table. Please check integrity of databse!")
        fleet_api_serializers.append(
          (api.function_name, serializer)
        )

    serializer_infos = []
    for f_name, se_record in fleet_api_serializers:
      serializer = se_record.serializer.split('$')
      # TODO: This is hacky... it doesn't work if someone decides to create a serializer of the form A$B$C because C will be cut off. Fix it!
      if len(serializer) > 1:
        serializer = serializer[:-1]
      serializer_infos.append(CommandSerializerInfo(f_name, serializer))
    #CommandSerializer as method that will allow to create serialized string only from function_name and args
    # this objecxt do all the $ parsing and insert args inside the api_serializer
    self._command_serializer = CommandSerializer(serializer_infos)

    # Node state
    self._cmd_id_counter = Counter()
    self._task_id_counter = Counter()
    self._new_device_counter = Counter()
    self._device_connection_info = {}
    self._device_api_requests = {}

    # Node interface
    self.declare_parameter('device_timeout_s', DEVICE_TIMEOUT_S)
    self.declare_parameter('device_connection_check_interval_s', DEVICE_CONNECTION_CHECK_INTERVAL_S)
    self.declare_parameter('disconnect_on_timeout_count', DISCONNECT_ON_TIMEOUT_COUNT)
    #Create a service for connection service
    self.create_service(ConnectDevice, CONNECT_DEVICE_SERVICE, self._on_device_connect, callback_group = ReentrantCallbackGroup())
    #Create a subscriber for device_ping (any device on firmware leveel should ping the haive-os if they are connected)
    self.create_subscription(UInt32, DEVICE_PING_TOPIC, self._on_device_ping, 10)
    connect_check_group = MutuallyExclusiveCallbackGroup()
    #create a timer that check if devices are still connected, a timeout attribute should be able to be changed
    self.create_timer(DEVICE_CONNECTION_CHECK_INTERVAL_S, self._check_device_connections, callback_group=ReentrantCallbackGroup())

    #Those 3 service, publisher and subcription allow the whole pipeline for the DeviceAPI
    #DEVICE_CMD_RESULT_TOPIC is a subcriber that receive directly from device and trigger a callback that identify and cast value according to result information in Airtable database "V...V....V..." format is received here
    #DEVICE_API_CALL_RESULT_TOPIC publish the treated cmd_result information (as a json string)
    self.api_call_service = self.create_service(DeviceAPICall, DEVICE_API_CALL_SERVICE, self._on_device_api_call, callback_group=ReentrantCallbackGroup())
    self._device_api_call_result = self.create_publisher(DeviceAPICallResult, DEVICE_API_CALL_RESULT_TOPIC, 10)
    self.create_subscription(DeviceCommandResult, DEVICE_CMD_RESULT_TOPIC, self._on_device_cmd_result, 10, callback_group=ReentrantCallbackGroup())

    self.create_service(DeviceConnectionInfos, DEVICE_CONNECTION_INFOS_SERVICE, self._on_device_connection_infos_call)
    #Those allow to send event such as connection event, reconnection or disconnection for other node
    self._device_connected = self.create_publisher(ConnectionInfo, DEVICE_CONNECTED, 10)
    self._device_timeout = self.create_publisher(ConnectionInfo, DEVICE_TIMEOUT, 10)
    self._device_reconnected = self.create_publisher(ConnectionInfo, DEVICE_RECONNECTED, 10)
    self._device_disconnected = self.create_publisher(ConnectionInfo, DEVICE_DISCONNECTED, 10)

    self._internal_api_retry = 5

  def _on_device_connect(self, request, response) -> Any:
    """
    Return ConnectDevice_Response 

    Service answer called from a device (please hcekc hos_client)
    """
    print("Device connection callback from device manager")
    device_uid = request.uid
    device_id = self._db.get_device_id(device_uid)
    #Checking if there is a device_id information otherwise create an "Unknown" device_id/name by default
    if device_id == None:
      id_number = self._new_device_counter.get()
      device_id = "Unknown" + str(id_number)
      response.error = f"No device uid could be found for `{device_id}`. Please check your device database. Giving name : {device_id}"
      self.get_logger().warning(response.error)

    device_functions = self._db.get_device_functions(device_id)
    #checking that api_function are well defined
    if device_functions == None:
      error = f"Unable to get device functions for connected device `{device_id}`. Please check integrity of database!"
      self.get_logger().error(error)
      response.error += error
      device_functions = []
    if len(device_functions) == 0:
      api_client = None
    else:
      api_client, error = self._setup_device_api(device_uid)
      if error:
        self.get_logger().error(error)
        response.error += error
    #checking stream information
    streams, error = self._setup_device_streams(device_uid)
    if error and device_type != "Unknown":
      self.get_logger().error(error)
      response.success = False
      response.error += error
    
    #ConnectionInfo ros_message publication for connection (publisher) not a service here !
    msg = ConnectionInfo()
    msg.device_id = device_id
    msg.device_uid = device_uid
    device_info = self._db.get_device_info(device_id)
    print("Device info")
    if device_info == None:
      error = f"Unable to get device info for connected device `{device_id}` . Please check integrity of database!"
      self.get_logger().error(error)
      response.success = True
      response.error = error
      msg.device_type = "Unknown"
    else :
      msg.device_type = device_info.device_type
    msg.event_time_s = time.time()

    #if device_uid is already in device_connection_info it means it was already once_connected so it's a reconnection
    if device_uid in self._device_connection_info:
      self.get_logger().info(f"Device {device_id} reconnected: uid={device_uid}")
      self._device_connection_info[device_uid]['timeout'] = False
      self._device_connection_info[device_uid]['last_ping'] = time.time()
      self._device_connection_info[device_uid]['disconnect_counter'] = 0
      args = {"is_reconnected" : True}
      state_api_call_info = Hos.set_state(device_id, StateType.EXPECTED, args)
      while not state_api_call_info.future.done():
        pass

      self._device_reconnected.publish(msg)

    else:
      self.get_logger().info(f"New device connected: id={device_id} ,uid={device_uid}")
      # TODO: Clean this entry up on rosbrdige disconnect!
      # TODO: We should use the entry to handle a reconnect, no?
      # here we add for the first time device_uid information in self._device_connection_info as a first connection
      self._device_connection_info[device_uid] = {
        'device_id': device_id,
        'device_uid': device_uid,
        'timeout': False,
        'last_ping': time.time(),
        'api_client': api_client,
        'streams': streams,
        'disconnect_counter': 0,
      }
      #publish connectionInfo (publisher)
      args = {"is_connected" : True}
      state_api_call_info = Hos.set_state(device_id, StateType.EXPECTED, args)
      while not state_api_call_info.future.done():
        pass
      self._device_connected.publish(msg)
    response.success = True
    response.error += ''
    #here we return the service response
    return response

  def _setup_device_api(self, device_uid: int) -> (Client, str):
    """
    Return Client, error

    API Command are based on ros_service and basically each device as it's service topic created by this SERIALIZED_DEVICE_COMMAND_SERVICE(device_uid) == f'/haive_os/device/uid{uid}/serialized_command'
    without this you cannot send DevceAPI calls

    Parameters
    ----------
    device_uid (int) : unique uid from the chip (ESP, or MCU)
    """
    # TODO: Lookup db to check if service is serialized or not!!
    device_api_service = SERIALIZED_DEVICE_COMMAND_SERVICE(device_uid)

    # TODO: Lookup db to check if service is serialized or not!!
    serialized_cb_group = MutuallyExclusiveCallbackGroup()
    api_client = self.create_client(SerializedDeviceCommand, device_api_service, callback_group=serialized_cb_group)

    service_client_success = False
    for _ in range(5):
      if api_client.wait_for_service(timeout_sec=1.0):
        service_client_success = True
        break
      self.get_logger().info('Waiting for device api service ...')

    if not api_client.service_is_ready() or not service_client_success:
      return None, f"Allocation of device api service timed out. Make sure to create a service called '{device_api_service}'."

    self.get_logger().info(f'device-{device_uid}: device api service registered.')
    return api_client, ""

  def _setup_device_streams(self, device_uid: int) -> (List[Subscription], str):
    """
    Return List[streams], error

    Create all supbscription to streams created by the device (information are given by Airtable knowing the deivce_uid)

    Parameters
    ----------
    device_uid (int) : unique uid from the chip (ESP, or MCU)
    """
    # TODO: We don't really have to do this in the device manager... instead anyone can subscribe to a device stream?
    #  For that we should create a device_manager service that allows querrying the topic name by providing a device_id+stream_name
    # Setup device streams
    streams = []
    device_stream_group = MutuallyExclusiveCallbackGroup()
    #from device_uid we get the device_id
    device_id = self._db.get_device_id(device_uid)
    if device_id == None:
      #if we have nothing, it means that either the device_uid is not refered in the database, or the local information of the database are not updated
      self.get_logger().error(f"Unable to get device id for connected device (uid={device_uid}). Please check integrity of database!")
      return None, None
    #Here we subscribe to every stream topic
    #TODO:Maybe need to fix DEVICE_STREAM_TOPIC(device_uid, s.stream) if the same type of stream is given twice or more.
    for s in self._db.get_device_streams(device_id):
      stream = self.create_subscription(DeviceStream, DEVICE_STREAM_TOPIC(device_uid, s.stream), lambda msg, stream_name=s.stream: self._on_device_stream(stream_name, msg), qos_profile=10, callback_group=device_stream_group)
      streams.append(stream)
    #print number of streams
    self.get_logger().info(f'device-{device_uid} #streams: {len(streams)}.')

    return streams, ""

  def _on_device_ping(self, msg) -> None:
    """
    Return None

    Callback triggered when DeviceManager listen to a ping. All device publish there ping in the same topic: /haive_os/device/ping
    this function will then understand if it's a new device or not ,...

    Parameters
    ----------
    msg: a regular UInt32 Std_msg sended from the Device (holding the uid of the device)
    """
    #retrieving uid, msg is a Int std msg from ros so msg.data give the uid information sended by the device
    device_uid = msg.data
    #if statement to check if device_uid is known by the haive-os, if not registered in the fleet it will print an error
    if device_uid not in self._device_connection_info:
      self.get_logger().error(f"Received device ping from unregistered device (uid-{device_uid}). Please reboot the device and check the connection handshake is performed correctly.")
      return
    #Now we update device_uid to self._device_connection_info (already created and holding every device_uid of the fleet)
    device_connection_info = self._device_connection_info[device_uid]
    device_connection_info['last_ping'] = time.time()
    device_connection_info['disconnect_counter'] = 0

  def _on_device_api_call(self, request, response) -> Any:
    """
    Return Response

    Return a ros reponse from a DeviceAPI call
    """
    #get DeviceAPI request information
    device_id = request.device_id
    function_name = request.function_name
    args = request.args
    device_fleet_info = self._db.get_fleet_device(device_id)
    device_connection_type = device_fleet_info.communication_target
    device_uid = self._db.get_device_uid(device_id)
    device_record_info = self._db.get_device_info(device_id)

    if device_fleet_info.communication_target == "rosbridge_wifi" :
      #get device_uid from device_id
      
      if device_uid == None:
        response.is_valid = False
        response.error = f"No device uid could be found for `{device_id}`. Please check your device database."
        self.get_logger().error(response.error)
        return response
      #check if the device has been connected at least once
      if device_uid not in self._device_connection_info.keys():
        response.is_valid = False
        response.error = f"Device uid {device_uid} not found. Please check if the device is powered on."
        self.get_logger().error(response.error)
        return response
      #check if this device is still connected
      device_info = self._device_connection_info[device_uid]
      if device_info['timeout']:
        response.is_valid = False
        response.error = f"Device with uid {device_uid} has timed out. Please try to reconnect the device by restarting it."

        self.get_logger().error(response.error)

        return response

    # TODO: Do we really need to separate these two?
    task_id = self._task_id_counter.get()
    cmd_id = self._cmd_id_counter.get()

    self.get_logger().info(f"Received api call: task_id={task_id} | device_id={device_id} | function_name={function_name} | args={args}")
    #checking duplicate task_id for the DeviceAPI call
    if str(cmd_id) in self._device_api_requests.keys():
      response.is_valid = False
      response.error = 'CRITICAL_ERROR: Duplicate command id fround in current device api requests!'
      self.get_logger().error(response.error)
      return response

    # TODO: How to store api request meta data?
    self._device_api_requests[str(cmd_id)] = {
      'task_id': task_id,
      'device_uid': device_uid,
      'status': 'processing',
      'time_s': time.time(),
      'function_name': function_name,
    }

    


    # TODO: Depending on db entry for device we either generate DeviceCommand OR SerializedDeviceCommand!!
    #Here we create the serilized string with the $ replaced with actual inputs from the API_call information

    #Here happen a big crossroad depending on devices_communication_target
    #Here we check first if it's a serializedAPI before checking if it's wifi, can or serial
    device_communication_target = device_fleet_info.communication_target
    if device_record_info.serialized_api: 
      match device_communication_target:
        case "rosbridge_wifi" :
          api_client = device_info['api_client']
          serialized_command, error = self._command_serializer.serialize_command(function_name, args)
          if error:
            response.is_valid = False
            response.error = f"CRITICAL_ERROR: {error}"
            self.get_logger().error(response.error)
            return response
          self.get_logger().info(f"Serialized command >> {serialized_command}")
          #Here we create a service inside the api_call service, that sends the serialized command to the device, and the device will answer if he received or not
          req = SerializedDeviceCommand.Request()
          req.cmd_id = cmd_id
          req.serialized_command = serialized_command
          req.function_name = function_name
          future = api_client.call_async(req)
          self._device_cmd_futures.append({'task_id': task_id, 'future': future})
          # waiting for device to respond from this client_call
          #TODO:Ricky:Should add a timeout
          while not future.done():
            pass
          #Internal retry (it could also retry from an outside perspective but only if you need to wait for a long time)
          i = 0
          while not future.result().is_valid:
            future = api_client.call_async(req)
            i += 1
            while not future.done():
              pass
            if i > self._internal_api_retry:
              self.get_logger().warning(f"internal reattempt failed")
              pass
          self.get_logger().info(f"future SerializedAPI value : {future.result()}")
          self.get_logger().info(f"api call success")
          # Give all information about the DeviceAPI status from device information
          response.is_valid = future.result().is_valid
          response.error = future.result().error
          response.task_id = task_id
          self.get_logger().info(f"return response")
          return response
        #Sending command throught can communication, we will need probably to get information thanks to FleetRecord informmation
        case "can" :
          if device_info['serialized_api']:
            serialized_command, error = self._command_serializer.can_command(function_name, args)
          if error:
            response.is_valid = False
            response.error = f"CRITICAL_ERROR: {error}"
            self.get_logger().error(response.error)
            return response
          target_port = device_fleet_info.can_info
          baud_rate = device_fleet_info.baud_rate
          self.get_logger().info(f"CAN Serialized command >> {serialized_command} at {target_port} baud_rate : {baud_rate}")        
          

         #Sending command throught serial communication, we will need probably to get information thanks to FleetRecord informmation
        case "serial":

          pass
        case _:
          response.is_valid = False
          response.error = f"Device communication_target not found. Please check the device database info."
          self.get_logger().error(response.error)
          return response
            
    #Else statement for non-serialized API, meaning that we need to use some libraries
    else:
      #TODO:Ricky:If it's not serialized, we need to search for a function with exact same name in hos_device_lib
      # Changing args dict into a list called device_lib_args
      device_lib_arg = [self]
      for arg in args:
        device_lib_arg.append(arg.data)
      try:
        #Executing function from hos_device_lib.py with same function name
        getattr(DeviceLib, function_name)(*device_lib_arg)
      except:
        response.is_valid = False
        response.error = f"DeviceAPI not implemented yet in hos_device_lib"
        self.get_logger().error(response.error)
        return response
      pass

    # Give all information about the DeviceAPI status from device information
    response.is_valid = True
    response.error = ""
    response.task_id = task_id
    self.get_logger().info(f"api return response")

    return response

  def _on_device_cmd_result(self, message: object) -> None:
    """
    Return None

    Callback triggered when we received a DeviceAPICallResult from a device
    """
    #Unpack cmd_result information
    device_uid = message.uid
    cmd_id = message.cmd_id
    success = message.success
    error = message.error
    result_str = message.result_str
    #We check if there is a DeviceAPI call that is waiting for a device result information, if there is no matching task_id, system should be restart propably
    if str(cmd_id) not in self._device_api_requests.keys():
      self.get_logger().error(f"CRITICAL_ERROR: Received device command status for command id {cmd_id}, but id could not be found. System restart necessary.")
      return
    # TODO:Ricky:maybe a way to not this expensive method. still need to be confirm that it is expensive just assuming here
    # get deivce_id from device_uid
    device_id = self._db.get_device_id(device_uid)
    self.get_logger().info(f"Received device command result: device_id = {device_id} device_uid={device_uid} | cmd_id={cmd_id} | success={success} | error={error} | result_str={result_str}")
    # Since the DeviceAPI call is done, we remove it from the pending api_request_info
    api_request_info = self._device_api_requests.pop(str(cmd_id))
    
    # TODO: Do additional check if command requires results, and if there were passed any
    # Everything here is about to change result_str "V.....V.....V..." format information to a json format and then send again those information on the 
    result_json = {}
    if len(result_str) > 0:
      device_id = self._db.get_device_id(device_uid)
      if device_id == None:
        self.get_logger().error(f"Unable to get device id for connected device (uid={device_uid}). Please check integrity of database!")
        return
      api_info = self._db.get_device_function_info(device_id, api_request_info['function_name'])
      if api_info == None:
        self.get_logger().error(f"Unable to get device function info for connected device `{device_id}`. Please check integrity of database!")
        return
      #IMPORTANT:Here happen the string parsing
      result_values = [val for val in result_str.split('V')[1:]]
      #if there is more output/result than expect, the firmware or the Airtable should be checked
      if len(result_values) != len(api_info.results):
          self.get_logger().error(f"CRITICAL_ERROR: Illegal length of result values. Expected {len(api_info.results)} but got {len(result_values)}.")
          return
      
      for i, arg_info in enumerate([f_arg.split(':') for f_arg in api_info.results]):
        arg_name, arg_type = arg_info

        value, error = cast_db_type(arg_type, result_values[i])
        if error:
          self.get_logger().error(f"CRITICAL_ERROR: Error when casting db type > {error}")
          return

        result_json[arg_name] = value
    # Finishing and creating ros_message to send at DEVICE_API_CALL_RESULT_TOPIC
    msg = DeviceAPICallResult()
    msg.task_id = api_request_info['task_id']
    msg.success = success
    msg.error = error
    #we dumps the dictionnary again to a string but this time instead of "V..V..V.." we have a json string
    msg.result_jsons = json.dumps(result_json)
    msg.request_time_s = api_request_info['time_s']
    msg.response_time_s = time.time()

    # for cmd in self._device_cmd_futures:
    #   if cmd["task_id"] == msg.task_id:
    #     self.get_logger().info(f"Set result for {msg.task_id}")
    #     msg = DeviceAPICall.Response()
    #     msg.task_id = api_request_info['task_id']
    #     msg.error = error
    #     cmd["future"].set_result(msg)
    #     self.get_logger().info(f"task if test result{cmd['future'].result().task_id}")

    self._device_api_call_result.publish(msg)

  def _on_device_stream(self, stream_name: str, message: object) -> None:
    """
    Return None

    Callback when the device manager receive a stream information from devices
    """
    device_uid = message.uid
    data = message.data
    self.get_logger().warning(f"THIS IS A DEBUG MSG: stream event >> {stream_name}:{device_uid}:{data}")


  def _check_device_connections(self) -> None:
    """
    Return None

    This function is called at a timer callback and check if the device is already connected or not
    """
    current_time = time.time()
    #we check if the last ping from devices was more than the timeout threshold
    for k in list(self._device_connection_info.keys()):
      device_connection_info = self._device_connection_info[k]
      elapsed = current_time - device_connection_info['last_ping']
      
      if elapsed >= DEVICE_TIMEOUT_S:
        device_connection_info['timeout'] = True
        device_connection_info['disconnect_counter'] += 1

        msg = ConnectionInfo()
        msg.device_id = device_connection_info['device_id']
        msg.device_uid = device_connection_info['device_uid']
        device_info = self._db.get_device_info(device_connection_info['device_id'])
        if device_info == None:
          self.get_logger().error(f"Unable to get device info for connected device `{device_connection_info['device_id']}`. Please check integrity of database!")
          msg.device_type = "Unknown"
        else:
          msg.device_type = device_info.device_type
        msg.event_time_s = time.time()
        self._device_timeout.publish(msg)

        self.get_logger().warning(f"Device timed out: {device_connection_info['device_uid']}")

      if device_connection_info['disconnect_counter'] >= DISCONNECT_ON_TIMEOUT_COUNT:
        del self._device_connection_info[k]

        msg = ConnectionInfo()
        msg.device_id = device_connection_info['device_id']
        msg.device_uid = device_connection_info['device_uid']
        device_info = self._db.get_device_info(device_connection_info['device_id'])
        if device_info == None:
          self.get_logger().error(f"Unable to get device info for connected device `{device_connection_info['device_id']}`. Please check integrity of database!")
          return
        msg.device_type = device_info.device_type
        msg.event_time_s = time.time()
        args = {"is_connected" : False}
        state_api_call_info = Hos.set_state(device_id, StateType.EXPECTED, args)
        while not state_api_call_info.future.done():
          pass
        self._device_disconnected.publish(msg)

        self.get_logger().info(f"Device {msg.device_id} disconnected: {device_connection_info['device_uid']}")

  def _on_device_connection_infos_call(self, request, response) -> Any:
    """
    Return DeviceConnectionInfos_Response

    This is service answer from a client, giving a list of all the ConnectionInfo in a list (DeviceConnectionInfos_Response.connection_infos)
    """

    infos = []
    for info in self._device_connection_info.values():
      device_info = self._db.get_device_info(info['device_id'])
      if device_info == None:
        self.get_logger().error(f"Unable to get device info for connected device `{info['device_id']}`. Please check integrity of database!")
        return
      connection_info = ConnectionInfo()
      connection_info.device_id = info['device_id']
      connection_info.device_uid = info['device_uid']
      connection_info.device_type = device_info.device_type
      connection_info.event_time_s = info['last_ping']

      infos.append(connection_info)

    response.device_infos = infos
    return response

  # TODO: We should make this work with arbitrary future results. Should we?
  def spin_once(self, executor=None):
    if not executor:
      rclpy.spin_once(self)
    else:
      executor.spin_once()
      
    incomplete_futures = []

    for future_info in self._device_cmd_futures:
      f = future_info['future']
      task_id = future_info['task_id']

      if f.done():
        res = f.result()
        # TODO: Should we do sth else here? E.g. DeviceManager state?
        if not res.is_valid:
          self.get_logger().error(f"DeviceAPICall failed: {res.error}")
          msg = DeviceAPICallResult()
          msg.task_id = task_id
          msg.success = False
          msg.error = res.error
          self._device_api_call_result.publish(msg)

      else:
        incomplete_futures.append({'task_id': task_id, 'future': f})

    self._device_cmd_futures = incomplete_futures

  def spin(self, executor =None):
    while rclpy.ok():
      self.spin_once(executor)

def main(args=None):
  rclpy.init(args=args)

  # Parse arguments
  parser = argparse.ArgumentParser()
  parser.add_argument('-f', '--fleet')
  parser.add_argument('--local-db', action=argparse.BooleanOptionalAction, default=False)
  parsed_args = parser.parse_args(sys.argv[1:-3])

  node = DeviceManager(parsed_args.fleet, parsed_args.local_db)

  node.get_logger().info(f"Running {node_name}")

  # TODO: Do a test if MultiThreadedExecutor is really needed here
  executor = MultiThreadedExecutor()
  executor.add_node(node)
  executor.spin()

  node.destroy_node()
  rclpy.shutdown()

if __name__ == '__main__':
  main()
