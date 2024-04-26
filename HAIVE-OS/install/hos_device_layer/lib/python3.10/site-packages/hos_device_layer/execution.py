
"""
!!!
Probably Deprecated, used to create a class to handle parrallele or sequential API calls
!!!
"""
from abc import ABC
from typing import (List, Tuple, Callable)

from rclpy.node import Node

from hos_device_layer.topics import (DEVICE_CONNECTED, DEVICE_TIMEOUT, DEVICE_RECONNECTED, DEVICE_DISCONNECTED, DEVICE_API_CALL_RESULT_TOPIC)
from hos_interfaces.msg import (ConnectionInfo, DeviceAPICallResult)


class DeviceExecutionGroup(ABC):
  def __init__(self, node: Node):
    self._node = node
    self._api_calls = []
    self._completed = True

    self._node.create_subscription(DeviceAPICallResult, DEVICE_API_CALL_RESULT_TOPIC, self._on_device_api_call_result, 10)

  def add_api_call(self, api_call: Tuple[Callable, List]):
    self._api_calls.append(api_call)

  def add_api_calls(self, api_calls: List[Tuple[Callable, List]]):
    self._api_calls += api_calls

  def _on_device_api_call_result(self, msg: DeviceAPICallResult):
    pass


class SequentialDeviceExecutionGroup(DeviceExecutionGroup):
  def __init__(self, node: Node):
    super(SequentialDeviceExecutionGroup, self).__init__(node)

    self._execution_index = 0
    self._api_call_info = None
    self._pending_task = None

  def start(self):
    self._completed = False
    self._execution_index = 0

    self._execute_next_api_call()

  def is_finished(self):
    return self._completed

  def update(self):
    if self._completed:
      return

    self._update_service_future()

  def _execute_next_api_call(self):
    if self._execution_index == len(self._api_calls):
      self._completed = True
      return

    func, args_list = self._api_calls[self._execution_index]
    self._api_call_info = func(*args_list)

    self._execution_index += 1

  def _update_service_future(self):
    if self._api_call_info == None:
      return

    future = self._api_call_info.future

    if future.done():
      res = future.result()

      if res.is_valid:
        self._api_call_info = None
        self._pending_task = res.task_id
      else:
        self._api_call_info = None  # TODO: Handle this differently!!
        self._node.get_logger().error(f"DeviceAPICall failed: {res.error}")  # TODO: Delete

  def _on_device_api_call_result(self, msg: DeviceAPICallResult):
    super(SequentialDeviceExecutionGroup, self)._on_device_api_call_result(msg)

    self._node.get_logger().info(f"_on_device_api_call_result: task_id={msg.task_id} | success={msg.success} | error={msg.error} | result_jsons={msg.result_jsons} | request_time_s={msg.request_time_s} | response_time_s={msg.response_time_s}")

    # TODO: Handle results

    if msg.task_id == self._pending_task:
      self._pending_task = None
      self._execute_next_api_call()


class ParallelDeviceExecutionGroup(DeviceExecutionGroup):
  def __init__(self, node: Node):
    super(ParallelDeviceExecutionGroup, self).__init__(node)

    self._api_call_infos = []
    self._pending_tasks = set()

  def start(self):
    self._completed = False

    for func, args_list in self._api_calls:
      api_call_info = func(*args_list)
      self._api_call_infos.append(api_call_info)

  def is_finished(self):
    return self._completed

  def update(self):
    if self._completed:
      return

    self._update_service_futures()

    if len(self._api_call_infos) == 0 and len(self._pending_tasks) == 0:
      self._completed = True

  def _update_service_futures(self):
    api_call_infos = []

    for api_call_info in self._api_call_infos:
      future = api_call_info.future

      if future.done():
        res = future.result()

        if res.is_valid:
          self._node.get_logger().info(f"DeviceAPICall sucess: task_id={res.task_id}")  # TODO: Delete
          self._pending_tasks.add(res.task_id)
        else:
          self._node.get_logger().error(f"DeviceAPICall failed: {res.error}")  # TODO: Delete

      else:
        api_call_infos.append(api_call_info)

    self._api_call_infos = api_call_infos

  def _on_device_api_call_result(self, msg: DeviceAPICallResult):
    super(ParallelDeviceExecutionGroup, self)._on_device_api_call_result(msg)

    self._node.get_logger().info(f"_on_device_api_call_result: task_id={msg.task_id} | success={msg.success} | error={msg.error} | result_jsons={msg.result_jsons} | request_time_s={msg.request_time_s} | response_time_s={msg.response_time_s}")

    if msg.task_id in self._pending_tasks:
      self._pending_tasks.remove(msg.task_id)

    # result = json.loads(msg.result_jsons)

    # device_id = self._pending_tasks.pop(msg.task_id)
    # self.get_logger().info(f"_on_device_api_call_result: device_id={device_id}")

    # if device_id[0] == 'H':
    #   self.get_logger().info(f"_on_device_api_call_result: x={result['x']} y={result['y']}")
    # elif device_id[0] == 'C':
    #   self.get_logger().info(f"_on_device_api_call_result: slot={result['slot']} is_flipped={result['is_flipped']} parent_uid={result['uid']}")
