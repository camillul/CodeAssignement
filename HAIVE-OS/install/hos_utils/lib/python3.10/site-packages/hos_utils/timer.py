from typing import (Callable, List)

from rclpy.node import Node
from rclpy.callback_groups import CallbackGroup


class OneShotTimer():
  def __init__(self, node: Node, func: Callable, args: List = [], call_after_s: float = 0.0, cb_group: CallbackGroup = None):
    self._node = node
    self._timer = node.create_timer(call_after_s, self._call, cb_group)
    self._func = func
    self._args = args

  def _call(self):
    self._func(*self._args)
    self._node.destroy_timer(self._timer)
    _cleanup_timer(self)

_timers = {}

def create_one_shot_timer(node: Node, func: Callable, args: List = [], call_after_s: float = 0.0):
  global _timers
  timer = OneShotTimer(node, func, args, call_after_s)
  _timers[id(timer)] = timer

def _cleanup_timer(timer: OneShotTimer):
  global _timers
  del _timers[id(timer)]
