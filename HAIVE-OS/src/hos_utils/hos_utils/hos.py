from typing import (Any, List)
import time
import sys
import argparse
from dataclasses import dataclass
import json
from std_msgs.msg import Int8
from std_msgs.msg import UInt32
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import (MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup)
from hos_device_layer.services import (CONNECT_DEVICE_SERVICE, DEVICE_API_CALL_SERVICE, DEVICE_COMMAND_SERVICE, 
                                       SERIALIZED_DEVICE_COMMAND_SERVICE, DEVICE_CONNECTION_INFOS_SERVICE, GET_STATE_API_CALL_SERVICE, SET_STATE_API_CALL_SERVICE)
from hos_device_layer.topics import (DEVICE_API_CALL_RESULT_TOPIC, DEVICE_PING_TOPIC, DEVICE_CMD_RESULT_TOPIC, DEVICE_STREAM_TOPIC,
                                     DEVICE_CONNECTED, DEVICE_TIMEOUT, DEVICE_RECONNECTED, DEVICE_DISCONNECTED)

from hos_interfaces.msg import (DeviceCommandResult, DeviceAPICallResult, TypedField, DeviceStream, ConnectionInfo)
from hos_interfaces.srv import (ConnectDevice, DeviceCommand, SerializedDeviceCommand, DeviceAPICall, DeviceConnectionInfos, GetStateAPICall, SetStateAPICall)

from rclpy.client import (Future, Client)
from hos_robot_state.constants import std_msg_dict, StateType
from hos_interfaces.srv import (GetStateAPICall, SetStateAPICall)
from hos_device_layer.device_manager import (DeviceAPIArg, StateAPICallInfo)

import json
import time

maximal_client_try = 10

def set_state(node, device_id, state_type, dictionnary, callback_group=None) -> StateAPICallInfo:
  """
  Return StateAPICallInfo

  Create a ROS request for state_manager to change arg in the robot state. this is facilitation to use a stateAPI
  """
  #TODO:Check if args are good maybe check in state_manager since state manager has the db 
  if not dictionnary:
    node.get_logger().warning("Can't update state with an empty dictionnary")
  
  state_client = node.create_client(SetStateAPICall, SET_STATE_API_CALL_SERVICE, callback_group=callback_group)
  request = SetStateAPICall.Request()
  request.device_id = device_id
  request.state_type =  state_type
  request.input_jsons = json.dumps(dictionnary)
  i = 0
  while not state_client.wait_for_service(timeout_sec=1.0):
    node.get_logger().info('Waiting for setstate layer api service ...')
    i += 1
    if i > maximal_client_try : 
      error = f"maximum try reached, hos.set_state failed to create client for {device_id}, check if target device is connected or service"
      node.get_logger().error(error)
      call_time = time.time()
      future = None
      client = None
      return StateAPICallInfo(call_time, future, state_client, error)

  call_time = time.time()
  future = state_client.call_async(request)
  node.get_logger().info('hos_utils:SetState sended')
  return StateAPICallInfo(call_time, future, state_client)

     
  #TODO:publish each args to topics according to state_type
  #TODO:Should we allow dynamics creation of args/attributes
  
def get_state(node, device_id, state_type, callback_group=None) ->  StateAPICallInfo:
  '''
  Return StateAPICallInfo

  Create a ROS request for state_manager to get a ros_msg helding all the attributes of the device. this is facilitation to use a stateAPI
  '''
  # we create a client to the StateManager service
  state_client = node.create_client(GetStateAPICall, GET_STATE_API_CALL_SERVICE, callback_group=callback_group)
  #We create the request with all the information
  request = GetStateAPICall.Request()
  request.device_id = device_id
  request.state_type = state_type
  i = 0
  #waiting for the client-service to be ready
  while not state_client.wait_for_service(timeout_sec=1.0):
    node.get_logger().info('Waiting for get_state layer api service ...')
    i += 1
    if i > maximal_client_try : 
      error = f"maximum try reached, hos.get_state failed to create client for {device_id}, check if target device is connected or service"
      node.get_logger().error(error)
      call_time = time.time()
      future = None
      client = None
      return StateAPICallInfo(call_time, future, state_client, error)
  #return here a StateAPICallInfo with the future, time and client info
  call_time = time.time()
  future = state_client.call_async(request)
  node.get_logger().info('hos_utils:GetState sended')
  return StateAPICallInfo(call_time, future, state_client)


def wait_for_apis(node, api_cmd_list, timeout_sec :int = 0) -> (bool, str):
  """
  Return bool, string

  This allow to wait for a list of apis call to be finish and return a concatenation of all errors. error handling should be external

  Parameters
  ----------
  node : reference of the node calling this function
  api_cmd_list (List[DeviceAPICallInfo]) : All the DevceAPICall created waiting for result.
  timeout_sec (int) : timeout limit in seconds.
  """
  finished = True
  err =  ""
  if timeout_sec == 0:
    #waiting for all API call to be done
    for api in api_cmd_list:
      while not api.future.done():
        pass
  else :
    # here we take into account a timeout
    start_time = time.time()
    for api in api_cmd_list:
      while (not api.future.done()) or time.time()-start_time <= timeout_sec:
        pass
  for i in range(len(api_cmd_list)):
    if not api_cmd_list[i].future.done():
      #TODO:Ricky:Should be able to tell which_one.
      finished &= False
      err += f"[API {i}, is not done yet, please check callback function]"
    else:
      err += api_cmd_list[i].future.result().error
  return finished, err
        

def wait_for_apis_by_result(node, api_cmd_list, api_result_list ,timeout_sec :int = 0) -> (bool, str):
  """
  Return bool, string

  This allow to wait for a list of apis call to be finish considering an api_result_list and return a concatenation of all errors. error message should be external (from the device)

  Parameters
  ----------
  node : reference of the node calling this function
  api_cmd_list (List[DeviceAPICallInfo]) : All the DevceAPICall created waiting for result.
  api_result_list (List[DeviceAPIResult]) : All the DeviceAPIResult received 
  """

  finished = True
  err =  ""
  all_done = False
  for api in api_cmd_list:
    node.get_logger().warning(f"type :  {type(api.future.result())} value : {api.future.result()}")

  if timeout_sec == 0:
    while all_done:
      task_id_list = [cmd.future.result().task_id for cmd in api_cmd_list]
      api_done_list = [ api for api in api_done_list if(api.future.result().task_id in task_id_list) ]

  else :
    start_time = time.time()
    while all_done or time.time()-start_time <= timeout_sec:
      task_id_list = [cmd.future.result().task_id for cmd in api_cmd_list]
      api_done_list = [ api for api in api_done_list if(api.future.result().task_id in task_id_list) ]
      
  #TODO:Ricky:Not using yet api_result_list
  for i in range(len(api_cmd_list)):
    if not api_cmd_list[i].future.done():
      #TODO:Ricky:Should be able to tell which_one.
      finished &= False
      err += f"[API {i}, is not done yet, please check callback function]"
    else:
      err += api_cmd_list[i].future.result().error
  return finished, err
        


