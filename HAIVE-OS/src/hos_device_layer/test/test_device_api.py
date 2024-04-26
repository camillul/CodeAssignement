import rclpy
from threading import Thread
from rclpy.node import Node
from std_msgs.msg import Int8
from std_msgs.msg import UInt32
from rclpy.executors import MultiThreadedExecutor
from hos_device_layer.services import (CONNECT_DEVICE_SERVICE, DEVICE_API_CALL_SERVICE, DEVICE_COMMAND_SERVICE, 
                                       SERIALIZED_DEVICE_COMMAND_SERVICE, DEVICE_CONNECTION_INFOS_SERVICE, GET_STATE_API_CALL_SERVICE, SET_STATE_API_CALL_SERVICE)
from hos_device_layer.topics import (DEVICE_API_CALL_RESULT_TOPIC, DEVICE_PING_TOPIC, DEVICE_CMD_RESULT_TOPIC, DEVICE_STREAM_TOPIC,
                                     DEVICE_CONNECTED, DEVICE_TIMEOUT, DEVICE_RECONNECTED, DEVICE_DISCONNECTED)

from hos_interfaces.msg import (DeviceCommandResult, DeviceAPICallResult, TypedField, DeviceStream, ConnectionInfo)
from hos_interfaces.srv import (ConnectDevice, DeviceCommand, SerializedDeviceCommand, DeviceAPICall, DeviceConnectionInfos, GetStateAPICall, SetStateAPICall )
from rclpy.client import (Future, Client)

from rclpy.callback_groups import (MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup)
from hos_device_layer.hos_device_api import DeviceAPIClass
DeviceAPI = DeviceAPIClass()
from hos_device_layer.device_manager import DeviceManager
from hos_robot_state.state_manager import RobotStateNode
from hos_robot_state.constants import std_msg_dict, StateType
from hos_interfaces.srv import (GetStateAPICall)
import hos_utils.hos as Hos
from hos_utils.API import StateAPICallInfo, DeviceAPICallInfo, DeviceAPIArg

import json
import time
import pytest


node_name = "Test_Device_and_State_API_HAIVE"
spin_rate = 0

class APITestNode(Node):
  def __init__(self, node_name):
    super().__init__(node_name)

  def non_serialized_api_test(self) -> None:
    """
    Return None

    This method ensure we can send a non_serialized api (which means using a library)
    """
    api_call = DeviceAPI.pcr_run(self, "PCR5001", "haive/config_file.txt")
    
    assert api_call.future.result().is_valid

  def serialized_api_test(self) -> None:
    """
    Return None

    This function ensure we can send a serialized api so using mainly the device_manager
    """
    api_call = DeviceAPI.delta_arm_move_home(self, "H4001")
    while not api_call.future.done():
      rclpy.spin_once(self, timeout_sec= 1.0)
    
    assert api_call.future.result().is_valid
def test_init():
  """
  Return None

  THis test is just here to ensure the ROS initialization is done properly
  """
  #this is the minimum workbase for HAIVE-OS
  rclpy.init()
  APITestNodeObject = APITestNode(node_name)
  DeviceManagerObject = DeviceManager('shinkawasaki', True)
  RobotStateNodeObject = RobotStateNode('shinkawasaki', True)
  RobotStateNodeObject.get_logger().info(f"Running test Robot_state")
  APITestNodeObject.get_logger().info(f"Running test {node_name}")
  executor1 = MultiThreadedExecutor()
  executor2 = MultiThreadedExecutor()
  executor3 = MultiThreadedExecutor()
  executor1.add_node(DeviceManagerObject)
  executor2.add_node(RobotStateNodeObject)
  executor3.add_node(APITestNodeObject)
  state_thread = Thread(target=executor1.spin, daemon=True)
  device_thread = Thread(target=executor2.spin, daemon=True)
  state_thread.start()
  device_thread.start()


  rclpy.shutdown()
  time.sleep(0.5) # this ensure we finish first to close ros properly
  assert True



def test_get_state():
  """
  Return None

  This function test the get_state service capabilty, ensure that we can see the robot status

  output expected : knowing initial value when creating the device we should find the same values with get_state
  """
  #this is the minimum workbase for HAIVE-OS
  rclpy.init()
  executor = MultiThreadedExecutor()
  DeviceManagerObject = DeviceManager('shinkawasaki', True)
  DeviceManagerObject.get_logger().info(f"Running test Device manager")
  RobotStateNodeObject = RobotStateNode('shinkawasaki', True)
  RobotStateNodeObject.get_logger().info(f"Running test Robot_state")
  executor1 = MultiThreadedExecutor()
  executor2 = MultiThreadedExecutor()
  executor3 = MultiThreadedExecutor()
  executor1.add_node(DeviceManagerObject)
  executor2.add_node(RobotStateNodeObject)
  state_thread = Thread(target=executor1.spin, daemon=True)
  device_thread = Thread(target=executor2.spin, daemon=True)
  state_thread.start()
  device_thread.start()

  #Now we initialize our APITestNode
  APITestNodeObject = APITestNode(node_name)
  APITestNodeObject.get_logger().info(f"Running test {node_name}")
  executor3.add_node(APITestNodeObject)

  #Testing a non serialized api the assert is inside this method
  APITestNodeObject.non_serialized_api_test()

  state_thread = None
  device_thread = None
  APITestNodeObject.destroy_node()
  DeviceManagerObject.destroy_node()
  rclpy.shutdown()
  time.sleep(0.5) # this ensure we finish first to close ros properly
  assert True
