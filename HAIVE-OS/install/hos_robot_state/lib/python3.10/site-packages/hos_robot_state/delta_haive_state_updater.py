import time
import json

import rclpy
from rclpy.node import Node

from hos_device_layer.topics import (DEVICE_CONNECTED, DEVICE_TIMEOUT, DEVICE_RECONNECTED, DEVICE_DISCONNECTED, DEVICE_API_CALL_RESULT_TOPIC)
from hos_robot_state.constants import std_msg_dict
from hos_interfaces.msg import *

from hos_device_layer.hos_device_api import DeviceAPIClass
DeviceAPI = DeviceAPIClass()
import hos_utils.airtable as Airtable
from hos_device_layer.db import Database
from hos_robot_state.parking_haive_state_updater import (ParkingHAIVEStateNode)

HOS_DEBUG = True

class DeltaHAIVEStateNode(ParkingHAIVEStateNode):
  """
  StateUpdater for Container

  Inherith from ParkingHAIVEStateNode, all method here will override or add new feature for a DeltaHAIVEState
  """
  def __init__(self, db, device_id, msg_reference = DeltaHaiveState, node_name="delta_updater_node", device_type = "DeltaHaive", share_callback_group=None):
    super().__init__(db, device_id, msg_reference = msg_reference, node_name= node_name, device_type = device_type, share_callback_group=share_callback_group)
