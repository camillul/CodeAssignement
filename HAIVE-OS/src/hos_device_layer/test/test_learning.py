# TODO: Clean this up
# import pytest

# import os
# import launch
# import launch_ros
# import launch_testing
# import sys
# import unittest
# import rclpy

# import std_msgs

# import time
# import uuid


# # Launch feature nodes

# pytest.mark.rostest
# def generate_test_description():
#     file_path = os.path.dirname(__file__)
#     talker_node = launch_ros.actions.Node(
#         executable=sys.executable,
#         arguments=[os.path.join(
#             file_path, "..", "talker_listener", 'talker_node.py'
#         )],
#         additional_env={'PYTHONUNBUFFERED': '1'},
#         parameters=[{
#             "topic": "talker_chatter"
#         }]
#     )
#     listener_node = launch_ros.actions.Node(
#         executable=sys.executable,
#         arguments=[os.path.join(
#             file_path, "..", "talker_listener", 'listener_node.py'
#         )],
#         additional_env={'PYTHONUNBUFFERED': '1'},
#         parameters=[{
#             "topic": "listener_chatter"
#         }]
#     )

#     return (
#         launch.LaunchDescription([
#             talker_node,
#             listener_node,
#             launch_testing.actions.ReadyToTest(),
#         ]),
#         {
#             'talker': talker_node,
#             'listener': listener_node,
#         }
#     )

# # Tests

# class TestTalkerListenerLink(unittest.TestCase):

#     @classmethod
#     def setUpClass(cls) -> None:
#         rclpy.init()

#     @classmethod
#     def tearDownClass(cls) -> None:
#         rclpy.shutdown()

#     def setUp(self) -> None:
#         self.node = rclpy.create_node('test_talker_listener_link')

#     def tearDown(self) -> None:
#         self.node.destroy_node()

#     def test_talker_transmits(self, talker, proc_output):
#         msgs_rx = []

#         sub = self.node.create_subscription(
#             std_msgs.msg.String,
#             'talker_chatter',
#             lambda msg: msgs_rx.sppend(msg),
#             10
#         )

#         try:
#             end_time = time.time() + 10
#             while time.time() < end_time:
#                 rclpy.spin_once(self.node, timeout_sec=0.1)
#                 if len(msgs_rx) > 2:
#                     break

#             self.assertGreater(len(msgs_rx), 2)

#             for msg in msgs_rx:
#                 proc_output.assertWaitFor(
#                     expected_output=msg.data, process=talker
#                 )
#         finally:
#             self.node.destroy_subscription(sub)

#     def test_talker_receives(self, listener, proc_output):
#         pub = self.node.create_publisher(
#             std_msgs.msg.String,
#             'listener_chatter',
#             10
#         )

#         time.sleep(2)

#         try:
#             msg = std_msgs.msg.String()
#             msg.data = str(uuid.uuid4())

#             for _ in range(10):
#                 pub.publish(msg)
#                 success = proc_output.waitFor(
#                     expected_output=msg.data,
#                     process=listener,
#                     timeout=1.0,
#                 )
#                 if success:
#                     break

#             assert success, 'Waiting for output timed out'
#         finally:
#             self.node.destroy_publisher(pub) 


# # def test_device_connection():
# #     rc = main(argv=['.', 'test'])
# #     assert rc == 0, 'Found code style errors / warnings'


# # UNIT TEST
# class TestDummy(unittest.TestCase):
#     def test_dummy(self):
#         assert True




# from ament_index_python import get_package_share_directory

# @pytest.mark.launch_test
# def generate_test_description():
 
#     map_osm_file = os.path.join(
#         get_package_share_directory('lanelet2_map_provider'),
#         'data/test_map.osm'
#     )
 
#     lanelet2_map_provider = launch_ros.actions.Node(
#         package='lanelet2_map_provider',
#         executable='lanelet2_map_provider_exe',
#         namespace='had_maps',
#         parameters=[
#             os.path.join(
#                 get_package_share_directory('lanelet2_map_provider'),
#                 'param/test.param.yaml'
#             ),
#             {
#                 'map_osm_file': map_osm_file
#             }]
#     )
 
#     context = {'lanelet2_map_provider': lanelet2_map_provider}
 
#     return launch.LaunchDescription([
#         lanelet2_map_provider,
#         # Start tests right away - no need to wait for anything
#         launch_testing.actions.ReadyToTest()]
#     ), context


# @launch_testing.post_shutdown_test()
# class TestProcessOutput(unittest.TestCase):
 
#   def test_exit_code(self, proc_output, proc_info, ndt_mapper):
#     # Check that process exits with code -15 code: termination request, sent to the program
#     launch_testing.asserts.assertExitCodes(proc_info, [-15], process=ndt_mapper)



# class TestRunningDataPublisher(unittest.TestCase):
 
#     @classmethod
#     def setUpClass(cls):
#         cls.context = Context()
#         rclpy.init(context=cls.context)
#         cls.node = rclpy.create_node("test_node", context=cls.context)
 
#     @classmethod
#     def tearDownClass(cls):
#         rclpy.shutdown(context=cls.context)
 
#     def setUp(self):
#         self.msgs = []
#         sub = self.node.create_subscription(
#             msg_type=my_msg_type,
#             topic="/info_test",
#             callback=self._msg_received
#         )
#         self.addCleanup(self.node.destroy_subscription, sub)
 
#     def _msg_received(self, msg):
#         # Callback for ROS 2 subscriber used in the test
#         self.msgs.append(msg)
 
#     def get_message(self):
#         startlen = len(self.msgs)
 
#         executor = rclpy.executors.SingleThreadedExecutor(context=self.context)
#         executor.add_node(self.node)
 
#         try:
#             # Try up to 60 s to receive messages
#             end_time = time.time() + 60.0
#             while time.time() < end_time:
#                 executor.spin_once(timeout_sec=0.1)
#                 if startlen != len(self.msgs):
#                     break
 
#             self.assertNotEqual(startlen, len(self.msgs))
#             return self.msgs[-1]
#         finally:
#             executor.remove_node(self.node)
 
#     def test_message_content(self):
#         msg = self.get_message()
#         self.assertEqual(msg, "Hello, world")

