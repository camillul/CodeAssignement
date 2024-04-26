import time
import json

import rclpy
from rclpy.node import Node
from rclpy.callback_groups import (MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup)

from hos_device_layer.topics import (DEVICE_CONNECTED, DEVICE_TIMEOUT, DEVICE_RECONNECTED, DEVICE_DISCONNECTED, DEVICE_API_CALL_RESULT_TOPIC)
from hos_interfaces.msg import *

from hos_device_layer.hos_device_api import DeviceAPIClass
DeviceAPI = DeviceAPIClass()
import hos_utils.airtable as Airtable
import hos_utils.hos as Hos
from hos_device_layer.db import Database
from hos_robot_state.device_state_updater import DeviceStateNode


class ParkingHAIVEStateNode(DeviceStateNode):
  """
  StateUpdater for ParkingHAIVE

  Inherith from DeviceStateNode, all method here will override or add new feature for a ParkingHAIVEStateNode
  """
  def __init__(self,db,device_id, msg_reference = BaseHAIVEState, node_name="parking_updater_node", device_type = "BaseHaive", share_callback_group=None):
    super().__init__(db,device_id, msg_reference = msg_reference, node_name= node_name, device_type = device_type, share_callback_group=share_callback_group)
    self._device_api_call_result_result = []
    self.on_haive_connection()

  #TODO:Ricky:TO DO Only on connection callback

  def _on_device_api_call_result(self,msg):
    self._device_api_call_result_result.append(msg)

  def on_haive_connection(self):
    """
    Return None

    This is method called at the end of the init of the Parking HAIVE and here send commands to switch on all the slots
    """
    self.get_logger().info("on_haive_connection callback")
    slots = [1,3,5,7,9,11] #will change for HAIVE-Cube for instance
    self._device_api_info_list = []
    #here we iterate throught the slots value
    for s in slots :
      self.get_logger().info(f"try send slot_power {s}")
      #sending a DeviceAPI call to turn on the slots
      haive_api = DeviceAPI.set_slot_power(self, self.device_id, s, "1")
      #no necessary but we add this to a list so that we can keep track of all api call inside the script (DeviceAPICallInfo with future, client and time)
      self._device_api_info_list.append(haive_api)
      #Waiting for the API call to be done here
      while not haive_api.future.done():
        rclpy.spin_once(self)
        pass
    #then we ensure that everything went ok here.
    finished = True
    err =  ""
    api_cmd_list = self._device_api_info_list
    for i in range(len(api_cmd_list)):
      if not api_cmd_list[i].future.done():
        #TODO:Ricky:Should be able to tell which_one.
        finished &= False
        err += f"[API {i}, is not done yet, please check callback function]"
      else:
        err += api_cmd_list[i].future.result().error
    for api in api_cmd_list:
      self.get_logger().info(f" api task_id info : {api.future.result().task_id}")
    finished, err = Hos.wait_for_apis(self, self._device_api_info_list, 10)
    self.get_logger().info(f"Done waiting for apis")
    if err:
      self.get_logger().warning(f"{err}")
    self.get_logger().info("on_connection callback done")


