#Those two devices need to be a DeltaHAIVE to make the test work, ensure that they fit the Airtable Database
test_device1 = "H4001"
uid_device1 = 10823358
test_device2 = "H4002"
uid_device1 = 1

###
#How to use me :
# -  $cd HAIVE-OS/      (root of your ros2_workspace)
# -  $. install/setup.bash
# -  $pytest -s src/hos_robot_state/test/test_haive_state.py

###



#TODO:Ricky:Maybe automate test with Airtable for each DeviceAPI call related to each device role.
import rclpy
from threading import Thread
from rclpy.node import Node
from std_msgs.msg import Int8
from std_msgs.msg import UInt32
from rclpy.executors import MultiThreadedExecutor
from hos_device_layer.services import (CONNECT_DEVICE_SERVICE, DEVICE_API_CALL_SERVICE, DEVICE_COMMAND_SERVICE, 
                                       SERIALIZED_DEVICE_COMMAND_SERVICE, DEVICE_CONNECTION_INFOS_SERVICE, GET_STATE_API_CALL_SERVICE, SET_STATE_API_CALL_SERVICE)
from hos_device_layer.topics import (DEVICE_API_CALL_RESULT_TOPIC, DEVICE_PING_TOPIC, DEVICE_CMD_RESULT_TOPIC, DEVICE_STREAM_TOPIC,
                                     DEVICE_CONNECTED, DEVICE_TIMEOUT, DEVICE_RECONNECTED, DEVICE_DISCONNECTED)

from hos_interfaces.msg import (DeviceCommandResult, DeviceAPICallResult, TypedField, DeviceStream, ConnectionInfo)
from hos_interfaces.srv import (ConnectDevice, DeviceCommand, SerializedDeviceCommand, DeviceAPICall, DeviceConnectionInfos, GetStateAPICall, SetStateAPICall )
from rclpy.client import (Future, Client)

from rclpy.callback_groups import (MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup)
from hos_device_layer.hos_device_api import DeviceAPIClass
DeviceAPI = DeviceAPIClass()
from hos_device_layer.device_manager import DeviceManager
from hos_robot_state.state_manager import RobotStateNode
from hos_robot_state.constants import std_msg_dict, StateType
from hos_interfaces.srv import (GetStateAPICall)
import hos_utils.hos as Hos
from hos_utils.API import StateAPICallInfo, DeviceAPICallInfo, DeviceAPIArg

import json
import time
import pytest


node_name = "Test_Device_and_State_API_HAIVE"
spin_rate = 0

class TestNode(Node):
  def __init__(self, node_name: str, device_manager_node = None, state_manager_node = None, share_callback_group = None):
    super().__init__(node_name)
    if share_callback_group:
      self.cb_group = share_callback_group
    else:
      self.cb_group = ReentrantCallbackGroup()
    #Optional
    self._state_api_call_infos = []
    self._api_call_infos  = []
    #Create a publisher for the fake device ping create by the timer later on _fake_connection_method
    self.device_publisher = self.create_publisher(UInt32, DEVICE_PING_TOPIC, 10, callback_group= ReentrantCallbackGroup())
    self.device_manager_node = device_manager_node
    self.state_manager_node = state_manager_node
    self.fake_ping_timer = []
    #There can be several device_uid to simulate that's why we have a list
    self.test_device_uid = []

  def fake_device_connection(self, device_id = test_device1, device_uid = 10823358):
    """
    Return None

    create a device connection msg, simulating the connection of a device.
    """
    #create the serialized command topic for DeviceAPI calls
    TEST_DEVICE_CMD_SERVICE ="haive_os/device/uid"+str(device_uid)+"/serialized_command"
    #create a service for cmd_result so we can receive fake result
    self.cmd_device_service = self.create_service(SerializedDeviceCommand, TEST_DEVICE_CMD_SERVICE, self.fake_cmd_callback, callback_group= ReentrantCallbackGroup())
    #Create connection client so that all the connection event trigger in DeviceManager
    self.connection_client = self.create_client(ConnectDevice, CONNECT_DEVICE_SERVICE, callback_group= ReentrantCallbackGroup())
    #Creatin connection event
    req = ConnectDevice.Request()
    req.uid = device_uid
    if self.connection_client:
      while not self.connection_client.wait_for_service(timeout_sec=5.0):
        self.get_logger().info('service not available, waiting again...')
    else:
      raise Exception("issue at creating client for device, check device_manager")
    self.connection_response = self.connection_client.call_async(req)
    #waiting for connection service to be done
    while not self.connection_response.done():
      rclpy.spin_once(self)
      pass
    print(f'response : {self.connection_response.result().success}')
    print("timer_created")
    #Create a timer in order to fake ping from a device
    timer_period = 2
    self.test_device_uid.append(device_uid)
    self.fake_ping_timer.append(self.create_timer(timer_period, self.fake_device_connection_callback, callback_group =  MutuallyExclusiveCallbackGroup()))
    self.i = 0


  def fake_cmd_callback(self, request, response):
    """
    Return Future

    create a fake response, in that case the cmd is always a sucess
    """
    response.succes = True
    return response

  def fake_device_connection_callback(self):
    """
    Return None

    Create fake ping, this function should be called inside a ros timer
    """
    #Here we send a fake uid ping for each device that need to be simulate (those devices are added to self.test_device_uid)
    ping_msg =  UInt32()
    for uid in self.test_device_uid :
      ping_msg.data = uid
      self.device_publisher.publish(ping_msg)
      self.get_logger().info(f'Publishing: ping uid : {ping_msg.data}')

  def test_delta_api(self):
    """
    Return Future
    Create an exemple of DeviceAPICall with some default parameter
    """
    #TODO:Ricky:Not used yet, used to be used for fake_dynamic_protocol_test but fake answers to DeviceAPICall has'nt been done yet
    return DeviceAPI.delta_arm_move_r(self, test_device1, 40, 40, 150, 3)

  def _fake_protocol_creator_DeltaHAIVE(self, device1: str, device2: str, data_type = StateType.EXPECTED.value) -> List[str]: 
    """
    return List[str]

    This is an exemple of how to create a dynamical protocol
    """
    #device1 and device2  are string name of the concerned device
    #first we get information about their state
    Device1State = Hos.get_state(self, device1, data_type, callback_group=self.cb_group)
    Device2State = Hos.get_state(self, device2, data_type, callback_group=self.cb_group)
    #Optional : but you can add them to a list so that we can keep track of them later
    self._state_api_call_infos.append(Device1State.future)
    self._state_api_call_infos.append(Device2State.future)
    print(" waiting in fake protocol state_api_call_added")
    #Here we are waiting for services to be done
    while (not Device1State.future.done() or not Device2State.future.done()) :
      rclpy.spin_once(self, timeout_sec= 1.0)
      print("ros.spin_until again")
    print(f"Device 1{Device1State.future.done()} Device 2 {Device2State.future.done()}")
    #we initialize a list were fake DeviceAPICall will be added according to devices states
    fake_api_result = []
    #as an exemple here, if the turntable is not at slot 1, we send the deviceAPI call to trun the turtable to slot 1
    #so we check that condition for both of the device here
    if json.loads(Device1State.future.result().result_jsons)["turntable_slot"] != 1:
      fake_api_result.append("turn device1's turnatable to slot 1 ")
    if json.loads(Device2State.future.result().result_jsons)["turntable_slot"] != 1:
      fake_api_result.append("turn device2's turnatable to slot 1 ")
    print("fake protocol ended")
    #return the list of fake API (e.g : ["turn device1's turnatable to slot 1 "] or  ["turn device1's turnatable to slot 1 ", "turn device2's turnatable to slot 1 "])
    return fake_api_result

  def _test_get_state(self, target = test_device1, data_type = StateType.EXPECTED.value ):
    """
    Return None

    test method to test get_state
    """
    #Send GetStateAPI call, H4001State0 is a DeviceAPICallInfo object (with future, time and client information)
    H4001State0 = Hos.get_state(self, target, data_type)
    #Optional : adddd this to a list to keep track of all state api call in the script
    self._state_api_call_infos.append(H4001State0.future)
    #here we wait for the future object to be done (waiting for the ros service to be done)
    while not H4001State0.future.done():
      rclpy.spin_once(self,timeout_sec= 1.0)
    #Checking here that we properly receive a dictionnary 
    # you need to use H4001State0.future.result() to assces the response from the service
    for key, value in json.loads(H4001State0.future.result().result_jsons).items():
       self.get_logger().info(f"key {key}, value {value}")
    print("Done")
      
  def _test_set_state(self, target = test_device1, data_type = StateType.EXPECTED.value, arg_to_update_dict = {"turntable_slot":5, "x_position":2}):
    """
    Return None

    test method to test set_state
    """
    #Send GetStateAPI call, H4001State0 is a DeviceAPICallInfo object (with future, time and client information)
    state_api_info = Hos.set_state(self, target, data_type,arg_to_update_dict)
    #Optional : adddd this to a list to keep track of all state api call in the script
    self._state_api_call_infos.append(state_api_info)
    #here we wait for the future object to be done (waiting for the ros service to be done)
    while not state_api_info.future.done():
      rclpy.spin_once(self, timeout_sec= 1.0)
      print("timeouted")
    print(f"SetStateAPICall returned : {state_api_info.future.result().is_valid}")
    self._state_api_call_infos = []
    state_api_info.client.remove_pending_request(state_api_info.future)
    #now that the SetState API as been done , adn that the GetStateMethod as been already tested, we send  a GetStateCall to ensure that args has been properly updated
    H4001State  = Hos.get_state(self, target, data_type, callback_group= ReentrantCallbackGroup())
    #Optional : adddd this to a list to keep track of all state api call in the script
    self._state_api_call_infos.append(H4001State)
    while not H4001State.future.done():
      rclpy.spin_once(self, timeout_sec= 1.0)
      print("ros.spin_until again")
    print()
    #here we check that the args given by GetState match with the original args (arg_to_update_dict)
    msg_dict = json.loads(H4001State.future.result().result_jsons)
    for key, value in msg_dict.items():
       self.get_logger().info(f"key {key}, value {value}")

    for key,value in arg_to_update_dict.items():
      if msg_dict[key] == value:
        print("arg have been properly updated")
        assert True
      else:
        print("arg have been not properly updated")
        assert False

      
  def spin(self, executor =None):
    while rclpy.ok():
      self.spin_once(executor)


  def spin_once(self, executor =None):
    state_call_infos = []

    for state_call_info in self._state_api_call_infos:
      future = state_call_info

      if future.done():
        res = future.result()
        if res.is_valid:
          self.get_logger().info(f"StateAPICall sucess: task_id={res.task_id}")
        else:
          self.get_logger().error(f"StateAPICall failed: {res.error}")

      else:
        state_call_infos.append(state_call_info)

    self._state_api_call_infos = state_call_infos

    if not self.executor:
      rclpy.spin_once(self)
    else:
      rclpy.spin_once(self)
      # executor.spin_once()


#################################################### FUNCTIONAL TEST ##############################################################################



def test_init():
  """
  Return None

  THis test is just here to ensure the ROS initialization is done properly
  """
  #this is the minimum workbase for HAIVE-OS
  rclpy.init()
  TestNodeObject = TestNode(node_name)
  DeviceManagerObject = DeviceManager('shinkawasaki', True)
  RobotStateNodeObject = RobotStateNode('shinkawasaki', True)
  RobotStateNodeObject.get_logger().info(f"Running test Robot_state")
  TestNodeObject.get_logger().info(f"Running test {node_name}")
  executor1 = MultiThreadedExecutor()
  executor2 = MultiThreadedExecutor()
  executor3 = MultiThreadedExecutor()
  executor1.add_node(DeviceManagerObject)
  executor2.add_node(RobotStateNodeObject)
  executor3.add_node(TestNodeObject)

  rclpy.shutdown()
  time.sleep(0.5) # this ensure we finish first to close ros properly
  assert True



def test_get_state():
  """
  Return None

  This function test the get_state service capabilty, ensure that we can see the robot status

  output expected : knowing initial value when creating the device we should find the same values with get_state
  """
  #this is the minimum workbase for HAIVE-OS
  rclpy.init()
  executor = MultiThreadedExecutor()
  DeviceManagerObject = DeviceManager('shinkawasaki', True)
  DeviceManagerObject.get_logger().info(f"Running test Device manager")
  RobotStateNodeObject = RobotStateNode('shinkawasaki', True)
  RobotStateNodeObject.get_logger().info(f"Running test Robot_state")
  executor1 = MultiThreadedExecutor()
  executor2 = MultiThreadedExecutor()
  executor3 = MultiThreadedExecutor()
  executor1.add_node(DeviceManagerObject)
  executor2.add_node(RobotStateNodeObject)
  state_thread = Thread(target=executor1.spin, daemon=True)
  device_thread = Thread(target=executor2.spin, daemon=True)
  state_thread.start()
  device_thread.start()

  #Now we initialize our TestNode
  TestNodeObject = TestNode(node_name, device_manager_node = DeviceManagerObject, state_manager_node = RobotStateNodeObject)
  TestNodeObject.get_logger().info(f"Running test {node_name}")
  executor3.add_node(TestNodeObject)
  #here we fake the connection of a Device (by default probably H4001)
  TestNodeObject.fake_device_connection()
  time.sleep(3) # this time.sleep is needed because we want to ensure that the connectiosn callback are finished
  #here we test the GetSateAPICall
  TestNodeObject._test_get_state()

  #Clean everything (need to be done properly so that next test is not affected)
  state_thread = None
  device_thread = None
  TestNodeObject.destroy_node()
  DeviceManagerObject.destroy_node()
  rclpy.shutdown()
  time.sleep(0.5) # this ensure we finish first to close ros properly
  assert True


def debug_spin(executor):
  executor.spin()
  print("spin ended")

def test_set_state():
  """
  Return None

  This function test the set_state service capabilty, ensure that the target arg is updated
  Requirement : function get_state need to be tested before to ensure we can properly evaluate if set_state is working or not

  output expected : 
  we set a different value from the initial value and themn use get_state on that value to ensure we update properly that value.
  """
  rclpy.init()

  #this is the minimum workbase for HAIVE-OS
  DeviceManagerObject = DeviceManager('shinkawasaki', True)
  DeviceManagerObject.get_logger().info(f"Running test Device manager")
  RobotStateNodeObject = RobotStateNode('shinkawasaki', True)
  RobotStateNodeObject.get_logger().info(f"Running test Robot_state")
  executor1 = MultiThreadedExecutor()
  executor2 = MultiThreadedExecutor()
  executor3 = MultiThreadedExecutor()
  executor1.add_node(DeviceManagerObject)
  executor2.add_node(RobotStateNodeObject)
  
  state_thread = Thread(target=executor1.spin, daemon=True)
  device_thread = Thread(target=executor2.spin, daemon=True)
  state_thread.start()
  device_thread.start()
  #Now we initialize our TestNode
  TestNodeObject = TestNode(node_name, device_manager_node = DeviceManagerObject, state_manager_node = RobotStateNodeObject)
  TestNodeObject.get_logger().info(f"Running test {node_name}")
  executor3.add_node(TestNodeObject)

  #here we fake the connection of a Device (by default probably H4001)
  TestNodeObject.fake_device_connection()
  time.sleep(3) # this time.sleep is needed because we want to ensure that the connectiosn callback are finished
  #here we test the SetSateAPICall
  TestNodeObject._test_set_state()

  #Clean everything (need to be done properly so that next test is not affected)
  TestNodeObject.destroy_node()
  state_thread = None
  device_thread = None
  DeviceManagerObject.destroy_node()
  rclpy.shutdown() # this ensure we finish first to close ros properly
  assert True



def test_dynamical_protocol():
  """
  Return None

  This function test/ensure that we can create a dynamic protocol according to the status  of the device
  Requirement : - test_set_state
                - test_get_state

  output expected : list of DeviceAPICall args should be different for each device
  """
  #this is the minimum workbase for HAIVE-OS
  rclpy.init()
  DeviceManagerObject = DeviceManager('shinkawasaki', True)
  DeviceManagerObject.get_logger().info(f"Running test Device manager")
  RobotStateNodeObject = RobotStateNode('shinkawasaki', True)
  RobotStateNodeObject.get_logger().info(f"Running test Robot_state")
  executor1 = MultiThreadedExecutor()
  executor2 = MultiThreadedExecutor()
  executor3 = MultiThreadedExecutor()
  executor1.add_node(DeviceManagerObject)
  executor2.add_node(RobotStateNodeObject)
  state_thread = Thread(target=executor1.spin, daemon=True)
  device_thread = Thread(target=executor2.spin, daemon=True)
  state_thread.start()
  device_thread.start()

#Now we initialize our TestNode
  TestNodeObject = TestNode(node_name, device_manager_node = DeviceManagerObject, state_manager_node = RobotStateNodeObject)
  TestNodeObject.get_logger().info(f"Running test {node_name}")
  executor3.add_node(TestNodeObject)

  #He we fake the connection of 2 devices 
  TestNodeObject.fake_device_connection(device_id = test_device1)
  TestNodeObject.fake_device_connection(device_id = test_device2, device_uid = uid_device2) #TODO:SHould be jsut 2 exemples from Airtable
  time.sleep(3) # waiting for both device to be connected
  #initlialization of API List, according to devices states, they will receive fake_api calls (strings)
  fake_api_list1 = []
  fake_api_list2 = []
  #also kind of as an intiialization, we set device1 and device2 (e.g. : H4001, H4002, ...) with some args
  H4001State = Hos.set_state(TestNodeObject, test_device1, StateType.EXPECTED.value, {"turntable_slot":11, "x_position":2}, TestNodeObject.cb_group)
  H4002State = Hos.set_state(TestNodeObject, test_device2, StateType.EXPECTED.value, {"turntable_slot":9, "x_position":1}, TestNodeObject.cb_group)
  while (not H4001State.future.done() or not H4002State.future.done()):
    rclpy.spin_once(TestNodeObject)
    pass
  #Now here we create the fake_protocol, behind we do a GetStateAPi call for each device and accordin g to their status, we create a fake DeviceAPI call 
  fake_api_list1 = TestNodeObject._fake_protocol_creator_DeltaHAIVE(test_device1,test_device2)
  #Here we do the same but with diffrent initialization value and see if there is a protocol difference between fake_api_list1 and fake_api_list2
  H4001State2 = Hos.set_state(TestNodeObject, test_device1, StateType.EXPECTED.value, {"turntable_slot":1, "x_position":2}, TestNodeObject.cb_group)
  H4002State2 = Hos.set_state(TestNodeObject, test_device2, StateType.EXPECTED.value, {"turntable_slot":9, "x_position":1}, TestNodeObject.cb_group)
  print("both state_api_call_added")
  while (not H4001State2.future.done() or not H4002State2.future.done()):
    rclpy.spin_once(TestNodeObject)
    pass
  #Now here we create the fake_protocol, behind we do a GetStateAPi call for each device and accordin g to their status, we create a fake DeviceAPI call 
  fake_api_list2 = TestNodeObject._fake_protocol_creator_DeltaHAIVE(test_device1, test_device2)
  print(f"len protocol1 :{len(fake_api_list1)}, len protocol2 : {len(fake_api_list2)}")
  #we compare the len of those fake_api_list.
  #Indeed according to the protocol create, he will send an API call if the turntable slot is different to 1, 
  #yet in the first situation both device were not at the turntable slot 1, so fake_api_list1 should be of lenght 2.
  #While the other situation device1 was already at turntable slot 1 so he didn't sended the api call, so fake_api_list2 should be of leght is 1 
  assert len(fake_api_list1) != len(fake_api_list2)

  #Clean everything (need to be done properly so that next test is not affected)e
  state_thread = None
  device_thread = None
  TestNodeObject.destroy_node()
  DeviceManagerObject.destroy_node()
  rclpy.shutdown()
  time.sleep(0.5) # this ensure we finish first to close ros properly
  assert True



#################################################################### UNIT TEST ############################################################################
#TODO:Ricky:To finish/update later and error handling


def test_known_device_not_connected():
  """
  - Failure check
    - input : updating a known device but not connected
    - parameter : None
    - output expected : Should create only a DeviceState State space and little warning to the user
  """
  #this is the minimum workbase for HAIVE-OS
  rclpy.init()
  DeviceManagerObject = DeviceManager('shinkawasaki', True)
  DeviceManagerObject.get_logger().info(f"Running test Device manager")
  RobotStateNodeObject = RobotStateNode('shinkawasaki', True)
  RobotStateNodeObject.get_logger().info(f"Running test Robot_state")
  executor1 = MultiThreadedExecutor()
  executor2 = MultiThreadedExecutor()
  executor3 = MultiThreadedExecutor()
  executor1.add_node(DeviceManagerObject)
  executor2.add_node(RobotStateNodeObject)
  state_thread = Thread(target=executor1.spin, daemon=True)
  device_thread = Thread(target=executor2.spin, daemon=True)
  state_thread.start()
  device_thread.start()


  TestNodeObject = TestNode(node_name, device_manager_node = DeviceManagerObject, state_manager_node = RobotStateNodeObject)
  TestNodeObject.get_logger().info(f"Running test {node_name}")
  executor3.add_node(TestNodeObject)

  #Here we remove on purpose the fake_connection
  # TestNodeObject.fake_device_connection(device_id = test_device1, device_uid = 13212713)
  # time.sleep(3) #This is here just to ensure we finished to connected the fake device.

  #Checking both set_state and get_state for a not connected device
  #In a first test we check that DeviceState attribute such as last_ping can be properly update
  TestNodeObject._test_set_state(test_device1,StateType.EXPECTED.value,{"last_ping":float(12.3)})
  TestNodeObject._test_get_state(test_device1)
  state_api_info = Hos.set_state(TestNodeObject, test_device1, StateType.EXPECTED.value, {"last_ping":float(12.3)}, TestNodeObject.cb_group)
  #waiting for service to be done
  while (not state_api_info.future.done()):
    rclpy.spin_once(TestNodeObject)
    pass
  #send a get_state to ensure that the last_pign attribute has been properly updated
  state_api_info2 = Hos.get_state(TestNodeObject, test_device1, StateType.EXPECTED.value, TestNodeObject.cb_group)
  TestNodeObject._state_api_call_infos.append(state_api_info2)
  #waiting for service to be done
  while (not state_api_info2.future.done()):
    rclpy.spin_once(TestNodeObject)
    pass
  print(state_api_info2.future.result().result_jsons)
  #asser that it has been updated as we send last_ping":float(12.3) before.
  assert json.loads(state_api_info2.future.result().result_jsons)["last_ping"] == float(12.3)

  #In a second test we check that if we use an arg not in  the device attribute list, it shoudl return an error.
  state_api_info3 = Hos.set_state(TestNodeObject, test_device1, StateType.EXPECTED.value, {"weird_attribute":5}, TestNodeObject.cb_group)
  TestNodeObject._state_api_call_infos.append(state_api_info3)
  while (not state_api_info3.future.done()):
    rclpy.spin_once(TestNodeObject)
    pass
  if state_api_info.error == "":
    if state_api_info3.future.done():
      assert "is not an attribute own by the device or can't create message" in state_api_info3.future.result().error
  else :
    assert "hos.set_state failed" in state_api_info3.error

  TestNodeObject.destroy_node()
  DeviceManagerObject.destroy_node()
  rclpy.shutdown()
  time.sleep(0.5)



def test_unknown_device_not_connected():
  """
  - Failure check
    - input : updating a known device but not connected
    - parameter : None
    - output expected : WARNING message can't update
  """
  rclpy.init()

  DeviceManagerObject = DeviceManager('shinkawasaki', True)
  DeviceManagerObject.get_logger().info(f"Running test Device manager")
  RobotStateNodeObject = RobotStateNode('shinkawasaki', True)
  RobotStateNodeObject.get_logger().info(f"Running test Robot_state")
  executor1 = MultiThreadedExecutor()
  executor2 = MultiThreadedExecutor()
  executor3 = MultiThreadedExecutor()
  executor1.add_node(DeviceManagerObject)
  executor2.add_node(RobotStateNodeObject)
  state_thread = Thread(target=executor1.spin, daemon=True)
  device_thread = Thread(target=executor2.spin, daemon=True)
  state_thread.start()
  device_thread.start()

  TestNodeObject = TestNode(node_name, device_manager_node = DeviceManagerObject, state_manager_node = RobotStateNodeObject)
  TestNodeObject.get_logger().info(f"Running test {node_name}") 
  executor3.add_node(TestNodeObject)

  #Fake the connection of a Device not referred in the database
  TestNodeObject.fake_device_connection(device_id = "Unknown0", device_uid = 999999)
  time.sleep(3) #ensure taht the connection callback is done
  #try to send a set_state call to the unknown device.
  state_api_info = Hos.set_state(TestNodeObject, "Unknown0", StateType.EXPECTED.value, {"turntable_slot":1, "x_position":2}, TestNodeObject.cb_group)
  TestNodeObject._state_api_call_infos.append(state_api_info)
  #waiting for the service call to be done
  while (not state_api_info.future.done()):
    rclpy.spin_once(TestNodeObject)
    pass
  #Here we check in the error result from the service that at least 1 error occured
  if state_api_info.error == "":
    if state_api_info.future.done():
      assert "Can't update" in state_api_info.future.result().error
  else :
    assert "hos.set_state failed" in state_api_info.error

  TestNodeObject.destroy_node()
  DeviceManagerObject.destroy_node()
  RobotStateNodeObject.destroy_node()
  rclpy.shutdown()
  time.sleep(0.5) # this ensure we finish first to close ros properly



# @pytest.mark.xfail(raises=Exception, reason = "Can't update")
# def test_known_device_not_connected_failure_check_2():
#   """
#   - Failure check
#     - input : updating a known device but not connected
#     - parameter : None
#     - output expected : WARNING message and  only DeviceState node should be create, that is to say
#   """
#   rclpy.init()

#   DeviceManagerObject = DeviceManager('shinkawasaki', True)
#   DeviceManagerObject.get_logger().info(f"Running test Device manager")
#   RobotStateNodeObject = RobotStateNode('shinkawasaki', True)
#   RobotStateNodeObject.get_logger().info(f"Running test Robot_state")

#   TestNodeObject = TestNode(node_name, device_manager_node = DeviceManagerObject, state_manager_node = RobotStateNodeObject)
#   TestNodeObject.get_logger().info(f"Running test {node_name}")

#   executor1 = MultiThreadedExecutor()
#   executor2 = MultiThreadedExecutor()
#   executor3 = MultiThreadedExecutor()
#   executor1.add_node(DeviceManagerObject)
#   executor2.add_node(RobotStateNodeObject)
#   executor3.add_node(TestNodeObject)
#   TestNodeObject.executor = executor3

#   state_thread = Thread(target=executor1.spin, daemon=True)
#   device_thread = Thread(target=executor2.spin, daemon=True)
#   state_thread.start()
#   device_thread.start()
#   # TestNodeObject.fake_device_connection(device_id = "F4001", device_uid = 0)

#   TestNodeObject._test_set_state("F4001", StateType.EXPECTED.value, arg_to_update_dict = {"turntable_slot":5, "x_position":2})
#   TestNodeObject.destroy_node()
#   DeviceManagerObject.destroy_node()
#   rclpy.shutdown()
#   time.sleep(0.5) # this ensure we finish first to close ros properly
