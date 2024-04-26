#This file is the DeviceAPI objectif any function need to be overriden can be done here
#But this should be done here 
#a possible case would be if we want to implement a compound function in DeviceAPI
#TODO:Ricky:Then i would need an airtable update where a boolean tell if it's a compound function or not

from typing import (Any, List)
import inspect
import time

from rclpy.node import Node
from hos_utils.API import StateAPICallInfo, DeviceAPICallInfo, DeviceAPIArg
from hos_device_layer.hos_device_api_raw import DeviceAPIGen
import hos_robot_state.constants 
from hos_device_layer.hos_state_api import StateAPIClass

StateAPI = StateAPIClass()

class DeviceAPIClass(DeviceAPIGen):
  def __init__(self):
    pass
