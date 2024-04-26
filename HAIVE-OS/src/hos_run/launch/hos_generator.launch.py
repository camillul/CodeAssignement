import os

from launch import LaunchDescription
from launch.actions import LogInfo

from hos_generator.hos_device_layer import generate_api_file
from hos_generator.hos_robot_state import (generate_state_api_file, generate_state_msg_files)

def generate_launch_description():
  package = 'hos_device_layer'
  package2 = 'hos_interfaces'
  cwd = os.getcwd()
  destination_directory_api = f'{cwd}/src/{package}/{package}/'
  destination_directory_msg = f'{cwd}/src/{package2}/'

  fleet_name = 'shinkawasaki'

  error = generate_api_file(fleet_name, destination_directory_api)
  if error:
    print("ERROR1 :" + error)
    raise ValueError("ERROR1 :" + error)
  # same for stateAPI
  generator_msg = f"Source file generation for DeviceAPI`{package}` successfull!"

  error2 = generate_state_api_file(fleet_name, destination_directory_api)
  if error2:
    print("ERROR2 :" + error2)
    raise ValueError("ERROR2:" + error2)

  generator_msg_2 = f"Source file generation for StateAPI at `{package} successfull!"


  error3 = generate_state_msg_files(fleet_name, destination_directory_msg)
  if error3:
    print("ERROR3 :" + error3)
    raise ValueError("ERROR3 :" + error3)

  generator_msg_3 = f"Source file generation for StateAPI messages at `{package2} successfull!"

  return LaunchDescription([
    LogInfo(msg=generator_msg),
    LogInfo(msg=generator_msg_2),
    LogInfo(msg=generator_msg_3),
  ])
