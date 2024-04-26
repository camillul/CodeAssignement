# This file aim to import any external python librarie to use non-serialized API
from typing import (Any, List)
import inspect

from rclpy.node import Node

def pcr_run(node: Node, config_file_name: str) -> str:
    """
    Return error

    Send a config file and run PCR protocol
    """
    node.get_logger().info("fake PCR function")
    return "" 