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
from hos_interfaces.srv import (ConnectDevice, DeviceCommand, SerializedDeviceCommand, DeviceAPICall, DeviceConnectionInfos, GetStateAPICall, SetStateAPICall, RobotStateInit )
from rclpy.client import (Future, Client)

from hos_device_layer.hos_device_api import DeviceAPIClass
DeviceAPI = DeviceAPIClass()
from hos_device_layer.device_manager import DeviceManager
from hos_robot_state.state_manager import RobotStateNode
from hos_robot_state.constants import std_msg_dict, StateType
from hos_interfaces.srv import (GetStateAPICall, SetStateAPICall)
import hos_interfaces.srv
import hos_utils.hos as Hos

import json
import time
import sys
import os

node_name = "initialization_node_client"


class RobotStateInitClient(Node):
  """
  This node is client to update from a JSON file, all the DeviceState
  """
  def __init__(self):
    super().__init__(node_name)
    self.cli = self.create_client(hos_interfaces.srv.RobotStateInit, 'robot_state_initilization', callback_group = ReentrantCallbackGroup())
    while not self.cli.wait_for_service(timeout_sec=1.0):
        self.get_logger().info('service not available, waiting again...')
    self.req = hos_interfaces.srv.RobotStateInit.Request()

  def send_request(self, init_input):
    self.req.file_name = init_input

    self.write_dict_at_file(init_input)

    self.future = self.cli.call_async(self.req)
    rclpy.spin_until_future_complete(self, self.future)
    return self.future.result()

  def write_dict_at_file(self,file_name):
    #TODO:THis was a test, service is working but poper file reading should be done here
    f = open(file_name, "w")
    haive_dict = {"meta_data":"day_version_haive", "devices_to_update":[{"device_id": "C4001", "args": {"slot_position": 5, "is_connected":False}}, {"device_id": "C4003", "args": {"slot_position": 7, "is_connected":False}}]}
    text_dict = json.dumps(haive_dict)
    print(text_dict)
    json.loads(text_dict)
    f.write(text_dict)
    f.close()

def main(args=None):
  rclpy.init(args=args)
  cwd = os.getcwd()
  minimal_client = RobotStateInitClient()
  #TODO:Ricky:GEt arg from terminale so that developper can do it without build everything again
  response = minimal_client.send_request(f'{cwd}/HAIVE4_robot_state_init.txt')
  minimal_client.get_logger().info('Robot state initalization done')
  minimal_client.destroy_node()
  rclpy.shutdown()

if __name__ == '__main__':
  main()