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
from hos_interfaces.srv import (ConnectDevice, DeviceCommand, SerializedDeviceCommand, DeviceAPICall, DeviceConnectionInfos, GetStateAPICall, SetStateAPICall,RobotStateInit )
from rclpy.client import (Future, Client)

from hos_device_layer.hos_device_api import DeviceAPIClass
DeviceAPI = DeviceAPIClass()
from hos_device_layer.device_manager import DeviceManager
from hos_robot_state.constants import std_msg_dict, StateType
import hos_utils.hos as Hos

import json
import time
import sys
import pytest

node_name = "initialization_node_service"

class RobotStateInitService(Node):
  """
  This is the server receiving the RobotStateInitClient request and create all the StateAPI calls
  """
  def __init__(self):
    super().__init__(node_name)
    self.srv = self.create_service(RobotStateInit, 'robot_state_initilization', self._robot_state_initilization_callback)
    self._api_calls = []

  def _robot_state_initilization_callback(self, request, response):
    """
    Return Response

    initilize robot_state information for every device referred in the file.
    """
    #Open the file
    file_info = {}
    with open(request.file_name) as f:
      lines = f.readlines()
      self.get_logger().info(str(lines[0]))
      try:
        file_info = json.loads(str(lines[0]))
      except:
        raise Exception("Cant read file, please check JSON format")

    #TODO:Ricky:Create StateAPI functions for every device according to the dict
    for d in file_info["devices_to_update"]:
      #sending an SetStateAPI call for every devices referred in the file
      update_api = Hos.set_state(self,d["device_id"],StateType.EXPECTED.value, d["args"], ReentrantCallbackGroup())
      self._api_calls.append(update_api)
    #Waiting for all the SetStateAPi call to finish
    for api in self._api_calls:
      while (not api.future.done()):
        rclpy.spin_once(self)
    response.is_valid = True
    response.error = ""
    return response


def main(args=None):
  rclpy.init(args=args)
  node = RobotStateInitService()
  node.get_logger().info(f"Running {node_name}")
  rclpy.spin(node)
  node.destroy_node()
  rclpy.shutdown()
if __name__ == '__main__':
  main()