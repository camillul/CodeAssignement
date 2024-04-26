
#TODO:Ricky:MAybe automate test with Airtable for each DeviceAPI call related to each device role.
from threading import Thread
from ament_index_python.packages import get_package_share_directory
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int8
from std_msgs.msg import UInt32
from rclpy.executors import MultiThreadedExecutor,SingleThreadedExecutor
from rclpy.callback_groups import (MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup)
from hos_device_layer.services import (CONNECT_DEVICE_SERVICE, DEVICE_API_CALL_SERVICE, DEVICE_COMMAND_SERVICE, 
                                       SERIALIZED_DEVICE_COMMAND_SERVICE, DEVICE_CONNECTION_INFOS_SERVICE, GET_STATE_API_CALL_SERVICE, SET_STATE_API_CALL_SERVICE)
from hos_device_layer.topics import (DEVICE_API_CALL_RESULT_TOPIC, DEVICE_PING_TOPIC, DEVICE_CMD_RESULT_TOPIC, DEVICE_STREAM_TOPIC,
                                     DEVICE_CONNECTED, DEVICE_TIMEOUT, DEVICE_RECONNECTED, DEVICE_DISCONNECTED)

from hos_interfaces.msg import (DeviceCommandResult, DeviceAPICallResult, TypedField, DeviceStream, ConnectionInfo)
from hos_interfaces.srv import (ConnectDevice, DeviceCommand, SerializedDeviceCommand, DeviceAPICall, DeviceConnectionInfos, GetStateAPICall, SetStateAPICall )
from rclpy.client import (Future, Client)

from hos_device_layer.hos_device_api import DeviceAPIClass
DeviceAPI = DeviceAPIClass()
from hos_device_layer.device_manager import DeviceManager
from hos_robot_state.state_manager import RobotStateNode
from hos_robot_state.constants import std_msg_dict, StateType
from hos_interfaces.srv import (GetStateAPICall, SetStateAPICall)
import hos_utils.hos as Hos

import json
import time
import sys
import pytest

node_name = "Test_Device_and_State_API_HAIVE"
spin_rate = 0

class TestNode(Node):
  def __init__(self, node_name: str, device_manager_node = None, state_manager_node = None, share_callback_group = None):
    super().__init__(node_name)
    if share_callback_group:
      self.cb_group = share_callback_group
    else:
      self.cb_group = ReentrantCallbackGroup()

    self._state_api_call_infos = []
    self._api_call_infos  = []
    self.device_publisher = self.create_publisher(UInt32, DEVICE_PING_TOPIC, 10, callback_group= ReentrantCallbackGroup())
    self.device_manager_node = device_manager_node
    self.state_manager_node = state_manager_node
    self.fake_ping_timer = []


  def fake_device_connection(self, device_id = "H4001", device_uid = 13212713):
    """
    Return None

    create a device connection msg, simulating the connection of a device.
    """
    TEST_DEVICE_CMD_SERVICE ="haive_os/device/uid"+str(device_uid)+"/serialized_command"
    self.cmd_device_service = self.create_service(SerializedDeviceCommand, TEST_DEVICE_CMD_SERVICE, self.fake_cmd_callback, callback_group = ReentrantCallbackGroup())
    self.connection_client = self.create_client(ConnectDevice, CONNECT_DEVICE_SERVICE, callback_group = ReentrantCallbackGroup())
    req = ConnectDevice.Request()
    req.uid = device_uid
    if self.connection_client:
      while not self.connection_client.wait_for_service(timeout_sec=5.0):
        self.get_logger().info('service not available, waiting again...')
    else:
      raise Exception("issue at creating client for device, check device_manager")
    print("connection request sended")
    self.connection_response = self.connection_client.call_async(req)
    while not self.connection_response.done():
      print("spinning for connection")
      rclpy.spin_once(self)
      time.sleep(spin_rate)
    print(f'response : {self.connection_response.result().success}')
    print("timer created")
    timer_period = 2


  def fake_cmd_callback(self, request, response):
    """
    Return Future

    create a fake response, in that case the cmd is always a sucess
    """
    response.succes = True
    return response

  def fake_device_connection_callback(self):
    """
    Return None

    Create fake ping, this function should be called inside a ros timer
    """
    ping_msg =  UInt32()
    ping_msg.data = self.test_device_uid
    self.device_publisher.publish(ping_msg)
    self.get_logger().info(f'Publishing: ping uid : {ping_msg.data}')

  def test_delta_api(self):
    """
    Return Future
    Create an exemple of DeviceAPICall with some default parameter
    """
    return DeviceAPI.delta_arm_move_r(self, "H4001", 40, 40, 150, 3)

  def _fake_protocol_creator_DeltaHAIVE(self, device1, device2, data_type = StateType.EXPECTED.value): 
    Device1State = Hos.get_state(self, device1, data_type, callback_group = self.cb_group)
    self._state_api_call_infos.append(Device1State.future)
    Device2State = Hos.get_state(self, device2, data_type, callback_group = self.cb_group)
    self._state_api_call_infos.append(Device2State.future)
    print("state_api_call_added")
    while not Device1State.future.done() or not Device2State.future.done() :
      print("spinning test get")
      rclpy.spin_once(self)
      time.sleep(spin_rate)


    print(f"Device 1{Device1State.future.done()} Device 2 {Device2State.future.done()}")
    fake_api_result = []
    if json.loads(Device1State.result().result_jsons)["turntable_slot"] != 1:
      fake_api_result.append("turn device1's turnatable to slot 1 ")

    if json.loads(Device2State.result().result_jsons)["turntable_slot"] != 1:
      fake_api_result.append("turn device2's turnatable to slot 1 ")

    return fake_api_result

  def _test_get_state(self, target = "H4001", data_type = StateType.EXPECTED.value):
    """
    Return None

    test method to test get_state
    """
    H4001State0 = Hos.get_state(self, target, data_type)
    self._state_api_call_infos.append(H4001State0.future)
    print("state_api_call_added")
    while not H4001State0.future.done():
      rclpy.spin_once(self, timeout_sec= 1.0)
      print("timeouted")


    for key, value in json.loads(H4001State0.future.result().result_jsons).items():
       self.get_logger().info(f"key {key}, value {value}")
    print("Done")
      
  def _test_set_state(self, target = "H4001", data_type = StateType.EXPECTED.value, arg_to_update_dict = {"turntable_slot":5, "x_position":2}):
    """
    Return None

    test method to test set_state
    """
    state_api_info = Hos.set_state(self, target, data_type, arg_to_update_dict, callback_group= ReentrantCallbackGroup())
    self._state_api_call_infos.append(state_api_info)
    while not state_api_info.future.done():
      rclpy.spin_once(self, timeout_sec= 1.0)
      print("timeouted")
    print(f"SetStateAPICall returned : {state_api_info.future.result().is_valid}")
    self._state_api_call_infos = []

    state_api_info.client.remove_pending_request(state_api_info.future)

    H4001State  = Hos.get_state(self, target, data_type, callback_group= ReentrantCallbackGroup())
    print("add to list")
    self._state_api_call_infos.append(H4001State)
    
    time.sleep(2)
    print("spinning until here")
    while not H4001State.future.done():
      rclpy.spin_once(self, timeout_sec= 1.0)
      print("ros.spin_until again")
    msg_dict = json.loads(H4001State.future.result().result_jsons)
    for key, value in msg_dict.items():
       self.get_logger().info(f"key {key}, value {value}")
    if msg_dict["turntable_slot"] == 5:
      print("arg have been properly updated")
      assert True
    else:
      print("arg have been not properly updated")
      assert False

      
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

    if not self.executor:
      rclpy.spin_once(self)
    else:
      rclpy.spin_once(self)
      # executor.spin_once()

def main(args=None):
  rclpy.init(args=args)

  node_name = "Test_Device_and_State_API_HAIVE"

  node = TestNode(node_name)
  node.get_logger().info(f"Running {node_name}")
  executor = MultiThreadedExecutor()
  executor.add_node(node)
  node.fake_device_connection()
  time.sleep(2)
  node._test_get_state()
  node._test_set_state()

  time.sleep(0.1)

  node.destroy_node()
  rclpy.shutdown()

if __name__ == '__main__':
  main()
