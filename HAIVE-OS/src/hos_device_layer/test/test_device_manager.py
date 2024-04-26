# TODO: Clean this up
# from typing import Union
# import pytest
# import os
# import launch
# import launch_ros
# import launch_testing
# import unittest
# import rclpy

# from hos_device_layer.services import (CONNECT_DEVICE_SERVICE, DEVICE_API_CALL_SERVICE, DEVICE_COMMAND_SERVICE)
# from hos_interfaces.msg import (Payload)
# from hos_interfaces.srv import (DeviceCommand, ConnectDevice, DeviceAPICall)


# # Launch feature nodes

# @pytest.mark.launch_test
# def generate_test_description(): 
#   device_manager = launch_ros.actions.Node(
#     package='hos_device_layer',
#     executable='device_manager',
#   )

#   layout_path = launch.substitutions.PathJoinSubstitution([
#     launch_ros.substitutions.FindPackageShare('hos_device_simulation'),
#     'layouts/test_layout.yaml'
#   ])
#   # haive4_sim = launch_ros.actions.Node(
#   #   package='hos_device_simulation',
#   #   executable='simulation_haive4',
#   #   arguments=['-l', layout_path],
#   # )

#   context = {
#     'device_manager': device_manager,
#     # 'haive4_sim': haive4_sim,
#   }

#   return launch.LaunchDescription([
#     device_manager,
#     # haive4_sim,
#     # Start tests right away - no need to wait for anything
#     launch_testing.actions.ReadyToTest()]
#   ), context


# # Testing

# class TestDeviceManager(unittest.TestCase):

#   @classmethod
#   def setUpClass(cls) -> None:
#     rclpy.init()

#   @classmethod
#   def tearDownClass(cls) -> None:
#     rclpy.shutdown()

#   def setUp(self) -> None:
#     self.node = rclpy.create_node('test_device_manager')

#   def tearDown(self) -> None:
#     self.node.destroy_node()

#   def test_device_connect(self) -> None:
#     self._create_device_command_service(uid=0)
#     self._connect_device(uid=0)

#   def test_device_api_call(self) -> None:
#     self._create_device_command_service(uid=1)
#     self._connect_device(uid=1)

#     client = self._create_service_client(DeviceAPICall, DEVICE_API_CALL_SERVICE)
#     self.assertTrue(client.service_is_ready(), f"Allocation of service '{DEVICE_API_CALL_SERVICE}' timed out.")

#     req = DeviceAPICall.Request()
#     req.task_id = 0
#     req.device_uid = 1
#     req.function_name = 'function_name'
#     # args = Payload()
#     # args.num_fields = 0
#     # args.field_names = []
#     # args.field_types = []
#     # args.field_data = []
#     # req.args = args
  
#     # TODO: This does not work, because client and server are spinning from same node!!!
#     future = self._do_service_request(client, req)
#     self.assertTrue(future.done(), f"Request of service '{DEVICE_API_CALL_SERVICE}' timed out.")

#     # client = self._create_service_client(DeviceCommand, DEVICE_COMMAND_SERVICE(uid=1))
#     # self.assertTrue(client.service_is_ready(), f"Allocation of service '{DEVICE_COMMAND_SERVICE(uid=1)}' timed out.")

#   def _connect_device(self, uid: int) -> None:
#     client = self._create_service_client(ConnectDevice, CONNECT_DEVICE_SERVICE)
#     self.assertTrue(client.service_is_ready(), f"Allocation of service '{CONNECT_DEVICE_SERVICE}' timed out.")

#     req = ConnectDevice.Request()
#     req.uid = uid
  
#     # future = self._request_device_connection(client, uid)
#     future = self._do_service_request(client, req)
#     self.assertTrue(future.done(), f"Request of service '{CONNECT_DEVICE_SERVICE}' timed out.")
    
#     result = future.result()
#     self.assertTrue(result.success,  f"Request of service '{CONNECT_DEVICE_SERVICE}' failed with error:\n{result.error}")

#   def _create_device_command_service(self, uid: int) -> None:
#     self.node.create_service(DeviceCommand, DEVICE_COMMAND_SERVICE(uid), lambda req, resp: ...)

#   def _create_service_client(self, service_type, service_name) -> rclpy.client.Client:
#     client = self.node.create_client(service_type, service_name)
    
#     for _ in range(5):
#       if client.wait_for_service(timeout_sec=1.0):
#         break

#     return client

#   # def _request_device_connection(self, client, uid: int) -> rclpy.task.Future:
#   #   req = ConnectDevice.Request()
#   #   req.uid = uid

#   #   future = client.call_async(req)
#   #   for _ in range(5):
#   #     rclpy.spin_once(self.node, timeout_sec=1.0)

#   #     self.assertTrue(rclpy.ok(), f"Something went wrong during request of service '{CONNECT_DEVICE_SERVICE}'.")

#   #     if future.done():
#   #       break

#   #   return future

#   def _do_service_request(self, client, request) -> rclpy.task.Future:
#     future = client.call_async(request)
#     for _ in range(5):
#       rclpy.spin_once(self.node)

#       if future.done():
#         break

#     return future
