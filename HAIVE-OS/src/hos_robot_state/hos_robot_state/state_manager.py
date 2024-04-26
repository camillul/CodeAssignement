from typing import (Any, List)
import time
import sys
import argparse
import json
from threading import Thread

import rclpy
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from rclpy.subscription import Subscription
from rclpy.callback_groups import (MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup)
from rclpy.client import (Future, Client)
from std_msgs.msg import UInt32
from hos_device_layer.topics import (DEVICE_PING_TOPIC, DEVICE_CONNECTED, DEVICE_TIMEOUT, DEVICE_RECONNECTED, DEVICE_DISCONNECTED, DEVICE_API_CALL_RESULT_TOPIC)
from hos_device_layer.services import (GET_STATE_API_CALL_SERVICE, SET_STATE_API_CALL_SERVICE)
from hos_interfaces.msg import *
from hos_interfaces.srv import (GetStateAPICall, SetStateAPICall)
from hos_robot_state import (delta_haive_state_updater, container_state_updater, parking_haive_state_updater, device_state_updater, tube_state_updater)

from ament_index_python.packages import get_package_share_directory

import hos_utils.airtable as Airtable
import hos_utils.file as FileUtils
import hos_utils.msg as MsgUtils
from hos_utils.API import StateAPICallInfo, DeviceAPIArg
from hos_device_layer.db import Database
from hos_robot_state.constants import std_msg_dict, StateType
from hos_device_layer.device_manager import StateAPICallInfo
from hos_utils.airtable import (AT_KEY_ID, AT_KEY_CREATED, AT_KEY_FIELDS)

node_name = 'state_manager_node'

class RobotStateNode(Node):
  """
  This node is a state_manager, receiving first all the stateAPI command and then actually call a service to the concerned State_updater
  It will also create those state_updater either when the first StateAPI for this device is created or when the real device is connecting to the HAIVE-OS

  In the end the is the heart of the estimator and observer system for the robot along with the state_updaters
  """
  def __init__(self, fleet_name: str, load_db_from_file: bool = False, share_callback_group=None):
    super().__init__(node_name)
    auth_path = f"{get_package_share_directory('hos_utils')}/auth/airtable.json"
    auth_data, error = FileUtils.load_json(auth_path)
    if load_db_from_file:
      error, db_data = Airtable.load_db_from_file(fleet_name)
      if error:
        raise ValueError(error)
    else:
      auth_path = f"{get_package_share_directory('hos_utils')}/auth/airtable.json"

      auth_data, error = FileUtils.load_json(auth_path)
      if error:
        raise ValueError(error)
      error, db_data = Airtable.load_db(auth_data['ACCESS_TOKEN'], auth_data['BASE_ID'], fleet_name)
      if error:
        raise ValueError(error)
    self._db = Database(db_data)

    if share_callback_group:
      self.cb_group = share_callback_group
    else:
      self.cb_group = MutuallyExclusiveCallbackGroup()
    self.cb_group2 = MutuallyExclusiveCallbackGroup()
    self._db = Database(db_data)
    self._state_api_call_infos = []
    self._pending_tasks = {}
    self._device_state_client_dict = {}
    self._child_state_updater_list = []
    self._client_list = []
    self.current_device_updater = []
    self.external_resource_memory = []
    self.create_subscription(ConnectionInfo, DEVICE_CONNECTED, self._on_device_connected_callback, 10, callback_group= ReentrantCallbackGroup())
    self.create_subscription(ConnectionInfo, DEVICE_TIMEOUT, self._on_device_timeout_callback, 10, callback_group= ReentrantCallbackGroup())
    self.create_subscription(ConnectionInfo, DEVICE_RECONNECTED, self._on_device_reconnected_callback, 10, callback_group= ReentrantCallbackGroup())
    self.create_subscription(ConnectionInfo, DEVICE_DISCONNECTED, self._on_device_disconnected_callback, 10, callback_group= ReentrantCallbackGroup())
    service_cb_group = ReentrantCallbackGroup()
    self.user_set_state_api_server = self.create_service(SetStateAPICall, SET_STATE_API_CALL_SERVICE, self._on_set_state_api_callback, callback_group=service_cb_group)
    self.user_get_state_api_server = self.create_service(GetStateAPICall, GET_STATE_API_CALL_SERVICE, self._on_get_state_api_callback, callback_group=service_cb_group)

    self.maximal_client_try = 5
        
  def _on_get_state_api_callback(self, request, response):
    """
    Return response

    This callback is triggered after a client requesting to get robot state from a Device

    Parameters
    ----------
    request: GetStateAPICall_Request object helding device_id and the type of data wanted, 
    response: GetStateAPICall_Response object giving baack all information wanted originally about the device

    """
    print("on_get_state_api_callback")
    target_device_type = ""
    for d in self._db._fleet.values():
      if d.device_id == request.device_id:
        target_device_type = d.device_type_id
    if not target_device_type:
      target_device_type = "Unknown"
      error = f"No device_type found for {request.device_id}, considering 'Unknown' type"
      self.get_logger().warning(error)
      response.error = error
    
    state_client1 = None
    req = GetStateAPICall.Request()
    if request.state_type == StateType.EXPECTED.value:
      state_client1 = self.create_client(GetStateAPICall, f'{request.device_id}/{request.device_id}_get_expected_state_service', callback_group=ReentrantCallbackGroup())
    if request.state_type == StateType.CURRENT.value:
      state_client1 = self.create_client(GetStateAPICall, f'{request.device_id}/{request.device_id}_get_current_state_service', callback_group=ReentrantCallbackGroup())
    if request.state_type == StateType.BOTH.value:
      self.get_logger().error(f"Can't get BOTH state, please enquire both status separatly")
      res = client_response.result()
      error = "ERROR: can't use BOTH state_type for GetStateAPI"
      response.result_jsons = res.result_jsons
      response.error = error
      response.is_valid = True
      return response
    if state_client1:
      self._client_list.append(state_client1)
      i = 0
      while not state_client1.wait_for_service(timeout_sec=2.0):
        self.get_logger().info('state_api_callback service not available, waiting again...')
        i += 1
        if i > self.maximal_client_try : 
          error = f"Target device :{request.device_id} is not connected, can't use GetStateAPI"
          self.get_logger().error(f"Issue at creating internal state client for device, check state_type or state_manager" + error)
          response.error = error
          response.is_valid = False
          return response

    req.device_id = request.device_id
    req.state_type = request.state_type
    client_response = state_client1.call_async(req)
    self._state_api_call_infos.append(client_response)
    while not client_response.done():
      pass
    res = client_response.result()
    response.result_jsons = res.result_jsons
    response.error = res.error
    response.is_valid = True
    print("finish get state")
    return response

  def _on_set_state_api_callback(self, request, response):
    """
    Return response

    This callback is triggered after a client requesting to set a state for a Device

    Parameters
    ----------
    request: SetStateAPICall_Request object helding device_id and the args we want to update
    response: SetStateAPICall_Response object giving back done status

    """
    print("on_set_state_api_callback")

    target_device_type = ""
    match request.device_id[0]:
      case 'T': # THis mean we have an external resource here (tube, plate, ...),
        target_device_type = "Tube" 
        if not (request.device_id in self.external_resource_memory):
          self.get_logger().warning(f"Creating a resource of type : {target_device_type}")
          self._on_device_connection(request.device_id, time.time(), target_device_type)
          self.external_resource_memory.append(request.device_id)
          time.sleep(2)

      case _:
        for d in self._db._fleet.values():
          if d.device_id == request.device_id:
            self.get_logger().warning(d.device_id)
            self.get_logger().warning(d.device_type_id)
            self.get_logger().warning(self._db._devices[d.device_type_id].device_type)
            target_device_type = self._db._devices[d.device_type_id].device_type
        if not target_device_type:
          target_device_type = "Unknown"
          error = f"No device_type found for {request.device_id}, considering 'Unknown' type"
          self.get_logger().warning(error)
          response.error = error
        # We check if device_state_manager is already here or not
        if not (request.device_id in self._device_state_client_dict.keys()):
          self.get_logger().warning(f"Known device :{request.device_id} is not connected, creating a {target_device_type} device_state_updater ")
          self._on_device_connection(request.device_id, time.time(), target_device_type)
          time.sleep(2)

    req = SetStateAPICall.Request()
    req.input_jsons = request.input_jsons
    print(request.input_jsons)
    client_response1 = None
    client_response2 = None
    state_client1 = None 
    state_client2 = None 
    error = ""
    if request.state_type == StateType.EXPECTED.value:
      state_client1 = self.create_client(SetStateAPICall, f'{request.device_id}/{request.device_id}_set_expected_state_service', callback_group=ReentrantCallbackGroup()) 
      state_type1 = request.state_type
    if request.state_type == StateType.CURRENT.value:
      state_client1 = self.create_client(SetStateAPICall, f'{request.device_id}/{request.device_id}_set_current_state_service', callback_group=ReentrantCallbackGroup())
      state_type1 = request.state_type
    if request.state_type == StateType.BOTH.value:
      state_client1 = self.create_client(SetStateAPICall, f'{request.device_id}/{request.device_id}_set_expected_state_service', callback_group=ReentrantCallbackGroup()) 
      state_client2 = self.create_client(SetStateAPICall, f'{request.device_id}/{request.device_id}_set_current_state_service', callback_group=ReentrantCallbackGroup())
      state_type1 = StateType.EXPECTED.value
      state_type2 = StateType.CURRENT.value
    if state_client1:
      print("client 1 start")
      i = 0
      self._client_list.append(state_client1)
      while (not state_client1.wait_for_service(timeout_sec=2.0)):
        self.get_logger().info('state_api_callback service not available, waiting again...')
        i += 1
        if i > self.maximal_client_try :
          error = f"Target device :{request.device_id} is not connected, can't use SetStateAPI"
          self.get_logger().error(f"Issue at creating internal state client for device, check state_type or state_manager. " + error)
          response.error = error
          response.is_valid = False
          return response
      req.device_id = request.device_id
      req.state_type = state_type1
      client_response1 = state_client1.call_async(req)
      self._state_api_call_infos.append(client_response1)
      while (not client_response1.done()):
        pass
      res1 = client_response1.result()
      error += res1.error
      response.error += res1.error
      print("client 1 done")
    if state_client2:
      print("client 2 start")
      i = 0
      self._client_list.append(state_client2)
      while (not state_client2.wait_for_service(timeout_sec=2.0)):
        self.get_logger().info('state_api_callback service not available, waiting again...')
        i += 1
        if i > self.maximal_client_try :
          error = f"Target device :{request.device_id} is not connected, can't use SetStateAPI"
          self.get_logger().error(f"Issue at creating internal state client for device, check state_type or state_manager. " + error)
          response.error = error
          response.is_valid = False
          return response
      req.device_id = request.device_id
      req.state_type = state_type2
      client_response2 = state_client2.call_async(req)
      self._state_api_call_infos.append(client_response2)
      while (not client_response2.done()):
        pass
      print("client 2 done")
      res2 = client_response2.result()
      error += res2.error
      response.error += res2.error
    response.is_valid = True
    print("finish set state")
    return response

  def _on_device_connected_callback(self, msg: ConnectionInfo):
    """
    Return None

    Directly triggered as a caalback on device connection
    Parameters
    ----------
    msg: ConnectionInfo ros_msg, helding all the device informations, this message sended is created by the DeviceManagerNode whenvever he heard for the first an UID ping
    """
    self._on_device_connection(msg.device_id, msg.event_time_s, msg.device_type)

  def _on_device_connection(self, device_id, event_time_s, device_type):
    """
    Return None

    Callback triggered on a device connection, it will create a state_upadater node accord to it'S type
    the state updater node will then be able to properly handle the robot state
    

    Parameters
    ----------
    device_id (str): name of the device connecting
    event_time_s (float) : when the device tried to connect
    device_type (str) : give the type of the device according to Airtable

    """
    if device_id in self._device_state_client_dict.keys() :
      self.get_logger().warning(f"Device state already created")
      return
    s = time.gmtime(event_time_s)
    self.get_logger().info(f"on_connection State-space callback")
    print("_on_device_connection")
    msg_class = MsgUtils.msg_class_from_device_type(self,self._db,device_type)
    if not msg_class:
      self.get_logger().error(f"No corresponding ros_msg_state found for {device_id}, device_type : {device_type}")
    msg = msg_class()
    self.get_logger().info(f"message created")
    executor = MultiThreadedExecutor()
    device_state_node = None
    match device_type:
      case "DeltaHaive":
        device_state_node = delta_haive_state_updater.DeltaHAIVEStateNode(self._db, device_id, msg_reference = msg_class, device_type = device_type, node_name = "delta_state_node")
        executor.add_node(device_state_node)
        self._device_state_client_dict[device_id] = self.create_client(GetStateAPICall, f"{device_id}_state_service",callback_group=self.cb_group)
        self.get_logger().info(f"State-space for : {device_id} type :{device_type} created")   
      case "Microplate":
        device_state_node = container_state_updater.ContainerStateNode(self._db, device_id, msg_reference = msg_class, device_type = device_type, node_name = "microplate_state_node")
        executor.add_node(device_state_node)
        self._device_state_client_dict[device_id] = self.create_client(GetStateAPICall, f"{device_id}_state_service", callback_group=self.cb_group)
        self.get_logger().info(f"Container State-space for : {device_id} type :{device_type}")   
      case "Magnet":
        device_state_node = container_state_updater.ContainerStateNode(self._db, device_id, msg_reference = msg_class)
        executor.add_node(device_state_node)
        self._device_state_client_dict[device_id] = self.create_client(GetStateAPICall, f"{device_id}_state_service", callback_group=self.cb_group)
        self.get_logger().info(f"Magnet Container State-space for : {device_id} type :{device_type}")   
      case "Falcon Tube":
        device_state_node = container_state_updater.ContainerStateNode(self._db, device_id, msg_reference = msg_class)
        self.executor.add_node(device_state_node)
        self._device_state_client_dict[device_id] = self.create_client(GetStateAPICall, f"{device_id}_state_service", callback_group=self.cb_group)
        self.get_logger().info(f"Falcon Container State-space for : {device_id} type :{device_type}")
      case "1.5mL Tube":
        device_state_node = container_state_updater.ContainerStateNode(self._db, device_id, msg_reference = msg_class)
        executor.add_node(device_state_node)
        self._device_state_client_dict[device_id] = self.create_client(GetStateAPICall, f"{device_id}_state_service", callback_group=self.cb_group)
        self.get_logger().info(f"Falcon Container State-space for : {device_id} type :{device_type}")   
      case "Tube":
        device_state_node = tube_state_updater.TubeStateNode(self._db, device_id, msg_reference = msg_class)
        executor.add_node(device_state_node)
        self._device_state_client_dict[device_id] = self.create_client(GetStateAPICall, f"{device_id}_state_service", callback_group=self.cb_group)
        self.get_logger().info(f"External_resource State-space for : {device_id} type :{device_type}")   
      case "Unknown":
        device_state_node = device_state_updater.DeviceStateNode(self._db, device_id, msg_reference = msg_class)
        executor.add_node(device_state_node)
        self._device_state_client_dict[device_id] = self.create_client(GetStateAPICall, f"{device_id}_state_service", callback_group=self.cb_group)
        self.get_logger().info(f"Default State-space for : {device_id} type :{device_type} created")
      case _: 
        device_state_node = device_state_updater.DeviceStateNode(self._db, device_id, msg_reference = msg_class, node_name = "default_state_node")
        executor.add_node(device_state_node)
        self._device_state_client_dict[device_id] = self.create_client(GetStateAPICall, f"{device_id}_state_service", callback_group=self.cb_group)
        self.get_logger().warning(f"device_type:{device_type} is not recognized giving instead default state-space : {device_id} created")
    if device_state_node:
      state_thread = Thread(target=executor.spin, daemon=True)
      state_thread.start()
    self.current_device_updater.append(device_id)

    #TODO:Ricky:Call init function here ?


  def _on_device_timeout_callback(self, msg: ConnectionInfo):
    """
    Return None

    When we don't receive a ping from a device for a long time this event is triggered
    """
    pass

  def _on_device_reconnected_callback(self, msg: ConnectionInfo):
    """
    Return None

    Triggered when a device is reconnected
    """
    pass

  def _on_device_disconnected_callback(self, msg: ConnectionInfo):
    """
    Return None

    Triggered when a device is considered disconnected
    """
    pass

  def spin(self, executor =None):
    while rclpy.ok():
      self.spin_once(executor)


  def spin_once(self, executor =None):
    
    state_call_infos = []

    for state_call_info in self._state_api_call_infos:
      future = state_call_info

      if future.done():
        res = future.result()
        if res.is_valid:
          self.get_logger().info(f"StateAPICall sucess: task_id={res.task_id}")
        else:
          self.get_logger().error(f"StateAPICall failed: {res.error}")

      else:
        state_call_infos.append(state_call_info)

    self._state_api_call_infos = state_call_infos

    if not executor:
      rclpy.spin_once(self)
    else:
      executor.spin_once()

def main(args=None):
  rclpy.init(args=args)

  # Parse arguments
  parser = argparse.ArgumentParser()
  parser.add_argument('-f', '--fleet')
  parser.add_argument('--local-db', action=argparse.BooleanOptionalAction, default=False)
  parsed_args = parser.parse_args(sys.argv[1:-3])


  node = RobotStateNode(parsed_args.fleet, parsed_args.local_db)
  node.get_logger().info(f"Running {node_name}")
  executor = MultiThreadedExecutor()
  executor.add_node(node)
  executor.spin()

  node.destroy_node()
  rclpy.shutdown()

if __name__ == '__main__':
  main()
