DEVICE_PING_TOPIC = 'haive_os/device/ping'                        # Pings HAIVE OS from device
DEVICE_CMD_RESULT_TOPIC = 'haive_os/device/command_result'        # Sends result of command call from device to HAIVE OS
def DEVICE_STREAM_TOPIC(uid: int, stream_name: str) -> str:       # Streaming data from device to HAIVE OS
  return f'haive_os/device/uid{uid}/stream/{stream_name}'
DEVICE_API_CALL_RESULT_TOPIC = 'haive_os/device/api_call_result'  # Sends result of device api call from HAIVE OS upwards
DEVICE_CONNECTED = 'haive_os/device/connected'
DEVICE_TIMEOUT = 'haive_os/device/timeout'
DEVICE_RECONNECTED = 'haive_os/device/reconnected'
DEVICE_DISCONNECTED = 'haive_os/device/disconnected'

