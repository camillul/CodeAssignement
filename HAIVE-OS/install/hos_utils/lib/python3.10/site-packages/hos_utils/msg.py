import hos_interfaces

def msg_class_from_device_type(node, db, device_type): 
  """
  Return ros_msg_object

  allow from a device_type, to generate the corresponding object instance of a ros_msg, using information from the database (robot_state table)
  """
  #If device type is Unkmown we give DeviceState message class by default
  if device_type == "Unknown" :
    return getattr(hos_interfaces.msg, "DeviceState")
  msg_class_name = ''
  print(f"searching for {device_type}")
  for r in db._robot_state.values():
    print(r.device_type)
    if device_type in r.device_type:
      msg_class_name = r.ros_state_msg
  if msg_class_name:
    try:
      print(f"Message found : {msg_class_name}")
      return getattr(hos_interfaces.msg, msg_class_name)
    except:
      node.get_logger().warning(f"message found for this message name : {msg_class_name}, but can't create class, please check hos_interfaces build")
      return getattr(hos_interfaces.msg, "DeviceState")
  else:
    node.get_logger().warning(f"No message found for this device_type : {device_type} : {msg_class_name}, please check Airtable database")
    return getattr(hos_interfaces.msg, "DeviceState")