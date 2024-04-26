import time
import json
from typing import (List, Union)

import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from rclpy.subscription import Subscription
from rclpy.callback_groups import (MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup)
from hos_device_layer.services import (CONNECT_DEVICE_SERVICE, DEVICE_API_CALL_SERVICE, DEVICE_COMMAND_SERVICE, 
                                       SERIALIZED_DEVICE_COMMAND_SERVICE, DEVICE_CONNECTION_INFOS_SERVICE, GET_STATE_API_CALL_SERVICE, SET_STATE_API_CALL_SERVICE)
from hos_device_layer.topics import (DEVICE_API_CALL_RESULT_TOPIC, DEVICE_PING_TOPIC, DEVICE_CMD_RESULT_TOPIC, DEVICE_STREAM_TOPIC,
                                     DEVICE_CONNECTED, DEVICE_TIMEOUT, DEVICE_RECONNECTED, DEVICE_DISCONNECTED, DEVICE_API_CALL_RESULT_TOPIC)
from hos_interfaces.msg import *
from hos_interfaces.srv import (GetStateAPICall, SetStateAPICall)

from hos_device_layer.hos_device_api import DeviceAPIClass
DeviceAPI = DeviceAPIClass()
import hos_utils.airtable as Airtable
import hos_interfaces
from hos_device_layer.db import Database
from hos_robot_state.constants import std_msg_dict
from hos_utils.counter import Counter
from hos_robot_state.sensors_callback import rfid_info_callback

HOS_DEBUG = True

class DeviceStateNode(Node):
  """
  This node is the base of every state_updater, allowing to do all basic and fundamental interaction expected from a state_manager (set and get state, ...)
  Other class will inherit from this class and then if you can add features or override some current behavior.
  """
  def __init__(self,db,device_id,msg_reference = DeviceState, node_name="default_updater_node", device_type="Unknown", device_namespace = "", share_callback_group=None):
    super().__init__(node_name, namespace = device_namespace + device_id, use_global_arguments = False)
    self.device_id = device_id #this can reffer to fleet and other subclasse inside the fleet if necesarry
    self.node_name = node_name #This is the name of the module and should be given by airtable by identifying the device_uid
    #here we are trying to cast
    if type(msg_reference) == str:
      self.msg_reference = getattr(hos_interfaces.msg, msg_reference) #TIPS:For some reason even if i give a msg_object it becomes a string
    else :
      self.msg_reference = msg_reference
    #should be used for external resource information such as tube,...
    self.external_resource_memory = []

    #dict of publisher for each type of data 
    self.current_publisher_dict = {}
    self.expected_publisher_dict = {}
    self.interpolated_publisher_dict = {}
    self.subscription_current_attribute_dict = {}
    self.subscription_expected_attribute_dict = {}
    self._task_id_counter = Counter()
    self._db = db
    try:
      self.current_state_msg = self.msg_reference()
      self.expected_state_msg = self.msg_reference()
      self.interpolated_state_msg = self.msg_reference()
    except:
      #if we can't generate the robot_state_msg we generate at least a default one : DeviceState 
      self.get_logger().warning(f"DeviceState creation, given_msg_reference failed !")
      self.current_state_msg = DeviceState()
      self.expected_state_msg = DeviceState()
      self.interpolated_state_msg = DeviceState()
    self.device_type = device_type
    self.current_attributes_values_dict= {}
    self.expected_attributes_values_dict= {}
    self.interpolated_attributes_values_dict= {}
    if share_callback_group:
      self.cb_group = share_callback_group
    else:
      self.cb_group = ReentrantCallbackGroup()
    self._setup_args_topics()
    #call an internal method to subcribe to all stream from device and child device
    stream_subscriptions, error = self._setup_device_streams()
    if error != "":
      self.get_logger().error(f"Can't setup stream, {error}")
      raise Exception(error)
    #Handle all necessary publisher, subcriber and service
    self.current_state_pub = self.create_publisher(msg_reference, str(self.device_id+"_current_state"), 10, callback_group=ReentrantCallbackGroup())
    self.expected_state_pub = self.create_publisher(msg_reference, str(self.device_id+"_expected_state"), 10, callback_group=ReentrantCallbackGroup())

    self.get_expected_state_server = self.create_service(GetStateAPICall, f'{self.device_id}_get_expected_state_service', self._get_expected_state_server_callback, callback_group=ReentrantCallbackGroup())
    self.get_current_state_server = self.create_service(GetStateAPICall, f'{self.device_id}_get_current_state_service', self._get_current_state_server_callback, callback_group=ReentrantCallbackGroup())

    self.set_expected_state_server = self.create_service(SetStateAPICall, f'{self.device_id}_set_expected_state_service', self._set_expected_state_server_callback, callback_group=ReentrantCallbackGroup())
    self.set_current_state_server = self.create_service(SetStateAPICall, f'{self.device_id}_set_current_state_service', self._set_current_state_server_callback, callback_group=ReentrantCallbackGroup())
    self.get_logger().info(f"Initialization done for {self.node_name}")


  def _setup_args_topics(self):
    """
    Return None

    Should create all current and expected individual topic for each attributes (should probably also give initial value)
    """
    attributes= [r.attributes for r in self._db._robot_state.values() if (self.device_type in r.device_type)][0]
    for a in attributes:
      self.subscription_current_attribute_dict[a.arg_name] = {"attribute_sub" : self.create_subscription(std_msg_dict[a.arg_type], str(a.arg_name), self._current_state_update_callback,10,callback_group=ReentrantCallbackGroup()), "arg_object" : a}
      self.expected_publisher_dict[a.arg_name] = {"attribute_pub" : self.create_publisher(std_msg_dict[a.arg_type], str(a.arg_name + "_expected"), 10,callback_group=ReentrantCallbackGroup()), "arg_object" : a}
      self.current_publisher_dict[a.arg_name] = {"attribute_pub" : self.create_publisher(std_msg_dict[a.arg_type], str(a.arg_name), 10,callback_group=ReentrantCallbackGroup()), "arg_object" : a}
      self.subscription_expected_attribute_dict[a.arg_name] = {"attribute_sub" : self.create_subscription(std_msg_dict[a.arg_type],str(a.arg_name + "_expected"), self._expected_state_update_callback,10,callback_group=ReentrantCallbackGroup()), "arg_object" : a}
      if a.arg_type == "string":
        self.current_attributes_values_dict[a.arg_name] = "Undefined" #TODO:Default value should be given here
        self.expected_attributes_values_dict[a.arg_name] = "Undefined" #TODO:Default value should be given here
      elif "int" in a.arg_type:
        self.current_attributes_values_dict[a.arg_name] = 0 #TODO:Default value should be given here
        self.expected_attributes_values_dict[a.arg_name] = 0 #TODO:Default value should be given here   
      elif a.arg_type == "bool":
        self.current_attributes_values_dict[a.arg_name] = False #TODO:Default value should be given here
        self.expected_attributes_values_dict[a.arg_name] = False #TODO:Default value should be given here  
      elif "float" in a.arg_type:
        self.current_attributes_values_dict[a.arg_name] = 0.0 #TODO:Default value should be given here
        self.expected_attributes_values_dict[a.arg_name] = 0.0 #TODO:Default value should be given here  
      else:
        self.current_attributes_values_dict[a.arg_name] = None #TODO:Default value should be given here
        self.expected_attributes_values_dict[a.arg_name] = None #TODO:Default value should be given here
      if HOS_DEBUG:
        self.get_logger().info(f"{a.arg_name} topics has been created")

  def _setup_device_streams(self) -> (List[Subscription], str):
    """
    setup_device_stream subcription, stream that can came from the Device or one of the child. For every stream subscriber for now we have the same callback all the time : _on_device_stream
    """
    streams = []
    device_stream_group = MutuallyExclusiveCallbackGroup()
    self.get_logger().info(f"stream debug 1")
    #get fleetRecord from deivce_id
    if not self._db.get_fleet_device(self.device_id):
      return None, ""
    #get children fleetRecord
    child_devices = self._db.get_fleet_device(self.device_id).child_device
    #Now for each child device we subscribe to their steams too, that's why we needed the fleetRecord holding streams informations
    for child_device_id in child_devices:
      self.get_logger().info(f"{child_device_id}")
      child_streams = self._db.get_device_streams(child_device_id)
      d =self._db.get_fleet_device(child_device_id)
      self.get_logger().info(f"{len(child_streams)}")
      for s in child_streams:
        self.get_logger().info(f"{d.device_uid} , {s.stream}")
        stream = self.create_subscription(DeviceStream, "/"+DEVICE_STREAM_TOPIC(d.device_uid, s.stream), lambda msg, stream_name=s.stream: self._on_device_stream(stream_name, msg), qos_profile=10, callback_group=device_stream_group)
        self.get_logger().info(f"subscribe to {DEVICE_STREAM_TOPIC(d.device_uid, s.stream)}")
        streams.append(stream)
    self.get_logger().info(f'State Space device-{self.device_id} #streams subscription: {len(streams)}.')
    return streams, ""

  def _on_device_stream(self, stream_name: str, message: object) -> None:
    """
    Return None

    This callback for stream subscrition allow with a match statement, to have different callback according to the sensor type/id, ...
    """
    #Unpack message information
    device_uid = message.uid
    data = message.data
    self.get_logger().warning(f"THIS IS A DEBUG MSG: stream event from {self.node_name}>> {stream_name}:{device_uid}:{data}")
    #trying to get the type of stream because when we unpack the data we don't have any information about the stream type that we need to udnerstand which callback we need to use after
    sensor_device_id = self._db.get_device_id(device_uid)
    stream = self._db.get_device_streams(sensor_device_id)
    for s in stream:
      self.get_logger().info(s.stream)
    #This swtich case allow to select the callback needed according to the stream type, _on_device_stream method should be ovveride if you want different callback on devices streams
    match s.stream:
      case "hall_sensor":
        pass
      case "rfid_info":
        rfid_info_callback(self, data)
      case _:
        self.get_logger().warning(f"No callback found for this stream type : {s.stream}")
    
  def _get_interpolated_state_server_callback(self, request, response):
    '''
    Return Future
    Callback that return a future holding the whole interpolated_state_msg related to this device (all attributes are here) 
    '''
    print("get_interpolated_callback")
    res_dict = self.interpolated_attributes_values_dict
    response.result_jsons = json.dumps(res_dict)
    #TODO:Ricky to a real check if data is valid maybe ?
    response.is_valid = True
    response.error = ""
    response.task_id = self._task_id_counter.get()
    print(response.result_jsons )
    return response


  def _get_expected_state_server_callback(self, request, response):
    '''
    Return Future
    Callback that return a future holding the whole expected_state_msg related to this device (all attributes are here) 
    '''
    print("get_expected_callback")
    res_dict = self.expected_attributes_values_dict
    response.result_jsons = json.dumps(res_dict)
    #TODO:Ricky to a real check if data is valid maybe ?
    response.is_valid = True
    response.error = ""
    response.task_id = self._task_id_counter.get()
    print(response.result_jsons )
    return response

  def _get_current_state_server_callback(self, request, response):
    '''
    Return Future
    Callback that return a future holding the whole current_state_msg related to this device (all attributes are here) 
    '''
    print("get_current_callback")
    res_dict = self.current_attributes_values_dict
    response.result_jsons = json.dumps(res_dict)
    response.is_valid = True
    response.error = ""
    response.task_id = self._task_id_counter.get()
    return response

  def _set_interpolated_state_server_callback(self, request, response):
    '''
    Return Future
    Callback that return a future just a validation that args have been properly published into topics
    '''
    print("set_interpolated_callback")
    args_to_update_dict = {}
    try:
      args_to_update_dict = json.loads(request.input_jsons)
    except e:
      error = f"Wrong dictionarry format :{e}"
      response.is_valid = False
      response.error = error
      response.task_id = self._task_id_counter.get()
      return response
    for key, value in args_to_update_dict.items():
      try :
        if key in self.interpolated_attributes_values_dict.keys():
          update_msg = std_msg_dict[self.interpolated_publisher_dict[key]["arg_object"].arg_type]()
          update_msg.data = value
          self.interpolated_attributes_values_dict[key] = value
        else:
          error = f"Can't update because {key} is not an attribute own by the device or can't create message"
          self.get_logger().info(error)
          response.is_valid = False
          response.error = error
          response.task_id = self._task_id_counter.get()
          return response
        self.interpolated_publisher_dict[key]["attribute_pub"].publish(update_msg)
      except :
        raise Exception(f"Can't publish, check publisher")
    response.is_valid = True
    response.error = ""
    response.task_id = self._task_id_counter.get()
    print("Device_state responding")
    return response


  def _set_expected_state_server_callback(self, request, response):
    '''
    Return Future
    Callback that return a future just a validation that args have been properly published into topics
    '''
    print("set_expected_callback")
    args_to_update_dict = {}
    try:
      args_to_update_dict = json.loads(request.input_jsons)
    except e:
      error = f"Wrong dictionarry format :{e}"
      response.is_valid = False
      response.error = error
      response.task_id = self._task_id_counter.get()
      return response
    for key, value in args_to_update_dict.items():
      try :
        if key in self.expected_attributes_values_dict.keys():
          update_msg = std_msg_dict[self.expected_publisher_dict[key]["arg_object"].arg_type]()
          update_msg.data = value
          self.expected_attributes_values_dict[key] = value
        else:
          error = f"Can't update because {key} is not an attribute own by the device or can't create message"
          self.get_logger().info(error)
          response.is_valid = False
          response.error = error
          response.task_id = self._task_id_counter.get()
          return response
        self.expected_publisher_dict[key]["attribute_pub"].publish(update_msg)
      except :
        raise Exception(f"Can't publish, check publisher")
    response.is_valid = True
    response.error = ""
    response.task_id = self._task_id_counter.get()
    print("Device_state responding")
    return response


  def _set_current_state_server_callback(self, request, response):
    print("set_current_callback")
    return response

  def _expected_state_update_callback(self, msg):
    """
    This callback will update the state_space of the device whenever one of attribute is changed
    """
    #TODO:Ricky if updating implies to update another this is where it should be called

    self._publish_my_expected_state()
    return

  def _current_state_update_callback(self, msg):
    #TODO:Ricky:Create a test where we use 2 StateAPI updating the same value, and should if we have good check order or good QoS
    #TODO:Ricky if updating implies to update another this is where it should be called
    self._publish_my_current_state()
    return

  def _publish_my_current_state(self):
    """
    Should be call to update entire state message (should be overwritten by any class inherating this class)
    """
    for key, value in self.current_attributes_values_dict.items():
      setattr(self.current_state_msg, str(key), value)

    self.expected_state_pub.publish(self.current_state_msg)

  def _publish_my_expected_state(self):
    """
    Should be call to update entire state message (should be overwritten by any class inherating this class)
    """
    for key, value in self.expected_attributes_values_dict.items():
      setattr(self.expected_state_msg, str(key), value)

    self.expected_state_pub.publish(self.expected_state_msg)

  def _publish_my_interpolated_state(self):
    """
    Should be call to update entire state message (should be overwritten by any class inherating this class)
    """
    for key, value in self.interpolated_attributes_values_dict.items():
      setattr(self.interpolated_state_msg, str(key), value)

    self.interpolated_state_pub.publish(self.interpolated_state_msg)

  def spin(self):
    while rclpy.ok():
      self.spin_once()


  def spin_once(self):
    rclpy.spin_once(self)


  def start(self, executor=None):
    self.get_logger().info(f"Running {self.node_name}")
    rclpy.spin(self)
    self.destroy_node()
    rclpy.shutdown()

def main(args=None):
  rclpy.init(args=args)

  auth_path = f"{get_package_share_directory('hos_utils')}/auth/airtable.json"
  auth_data, error = FileUtils.load_json(auth_path)
  if error:
    raise ValueError(error)
  error, db_data = Airtable.load_db(auth_data['ACCESS_TOKEN'], auth_data['BASE_ID'], fleet_name)
  if error:
    raise ValueError(error)
    db = Database(db_data)

  node = DeviceStateNode(db, "H4001")
  node.get_logger().info(f"Running {node_name}")
  executor = MultiThreadedExecutor()
  executor.add_node(node)
  executor.spin()

  node.destroy_node()
  rclpy.shutdown()

if __name__ == '__main__':
  main()