from dataclasses import dataclass
from rclpy.client import (Future, Client)

@dataclass
class DeviceAPICallInfo:
  call_time: float
  future: Future
  client: Client
  error: str = ""

@dataclass
class StateAPICallInfo:
  call_time: float
  future: Future
  client: Client
  error: str = ""

@dataclass
class DeviceAPIArg:
  arg_name: str
  arg_type: str
  arg_data: str
