from typing import (Any, List)
import inspect

from rclpy.node import Node
from hos_utils.API import StateAPICallInfo, DeviceAPICallInfo, DeviceAPIArg
from hos_device_layer.hos_state_api_raw import StateAPIGen
import hos_utils.hos as Hos
import hos_robot_state.constants 


class StateAPIClass(StateAPIGen):
    """
    This class inherit from StateAPIGen and used in DeviceAPI.
    Each DeviceAPI function has its "shadow" as a stateAPI in StateAPIGen but since we cannot really automate the content, here we allow the developper to override thos function 
    but by default those StateAPI function will raise an error log if they are not overrided, forcing the developper to actually write the function
    """
    def __init__(self):
        pass
    
    def state_delta_arm_move_r(self, node: Node, device_id: str, x: float, y: float, z: float, r: float) -> StateAPICallInfo:
        function_name = inspect.stack()[0][3]
        args = [
            DeviceAPIArg(
            'x',
            'float32',
            str(x),
            ),
            DeviceAPIArg(
            'y',
            'float32',
            str(y),
            ),
            DeviceAPIArg(
            'z',
            'float32',
            str(z),
            ),
            DeviceAPIArg(
            'r',
            'float32',
            str(r),
            ),
        ]
        #TODO : update futur attribute topics state here
        



    def state_set_slot_power(self, node: Node, device_id: str, slot: int, is_on: int) -> StateAPICallInfo:
        function_name = inspect.stack()[0][3]
        args = [
            DeviceAPIArg(
            'slot',
            'uint8',
            str(slot),
            ),
            DeviceAPIArg(
            'is_on',
            'uint8',
            str(is_on),
            ),
        ]
        args = {"slot_position" : slot}
        Hos.set_state(device_id, StateType.EXPECTED, args)
        node.get_logger().warning("set_slot_power stateAPI done")

    def state_delta_arm_move(self, node: Node, device_id: str, x: float, y: float, z: float) -> StateAPICallInfo:
        function_name = inspect.stack()[0][3]
        args = [
        DeviceAPIArg(
        'x',
        'float32',
        str(x),
        ),
        DeviceAPIArg(
        'y',
        'float32',
        str(y),
        ),
        DeviceAPIArg(
        'z',
        'float32',
        str(z),
        ),
        ]
        
        args = {}
        Hos.set_state(device_id, StateType.EXPECTED, args)
        node.get_logger().warning("delta_arm_move stateAPI still need to be updated")

    def state_pcr_run(self, node: Node, device_id: str, config_file_name: str) -> StateAPICallInfo:
        function_name = inspect.stack()[0][3]
        args = [
        DeviceAPIArg(
        'config_file_name',
        'string',
        str(config_file_name),
        ),
        ]
        node.get_logger().warning("fake pcr_run stateAPI done")