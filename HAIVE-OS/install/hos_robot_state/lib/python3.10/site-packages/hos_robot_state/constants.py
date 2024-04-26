from enum import Enum
import std_msgs

#Should be in hos_interface but then need to compile for both python and CMake

std_msg_dict = {  
  "string" : std_msgs.msg.String,
  "bool" : std_msgs.msg.Bool,
  "uint8" : std_msgs.msg.UInt8,
  "uint16" : std_msgs.msg.UInt16,
  "uint32" : std_msgs.msg.UInt32,
  "uint64" : std_msgs.msg.UInt64,
  "int8" : std_msgs.msg.Int8,
  "int16" : std_msgs.msg.Int16,
  "int32" : std_msgs.msg.Int32,
  "int64" : std_msgs.msg.Int64,
  "float32" : std_msgs.msg.Float32,
  "float64" : std_msgs.msg.Float64,
  }

#enum for State API data_type
class StateType(Enum):
  CURRENT = 0
  EXPECTED = 1
  BOTH = 2
  INTERPOLATION = 3
  LAST_SAVE = 4
