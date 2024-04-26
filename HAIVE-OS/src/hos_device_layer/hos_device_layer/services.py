CONNECT_DEVICE_SERVICE = '/haive_os/device/connect'       # Requests device connection to HAIVE OS
def DEVICE_COMMAND_SERVICE(uid: int) -> str:             # Serves device command interface to HAIVE OS using ROS style data
  return f'/haive_os/device/uid{uid}/command'
def SERIALIZED_DEVICE_COMMAND_SERVICE(uid: int) -> str:  # Serves device command interface to HAIVE OS using serialized data (e.g. used for L1)
  return f'/haive_os/device/uid{uid}/serialized_command'
DEVICE_API_CALL_SERVICE = '/haive_os/device/api_call'     # Serves device api from HAIVE OS upwards
DEVICE_CONNECTION_INFOS_SERVICE = '/haive_os/connected_devices'     # Serves device connection infoss from HAIVE OS upwards
GET_STATE_API_CALL_SERVICE = '/haive_os/device/get_state_api_call' 
SET_STATE_API_CALL_SERVICE = '/haive_os/device/set_state_api_call'  