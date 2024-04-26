import hos_utils.hos as Hos
from hos_robot_state.constants import std_msg_dict, StateType
import hos_robot_state

from rclpy.node import Node
from rclpy.callback_groups import (MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup)

from threading import Thread
import json
import time

def tube_information_parsing(node, value: str) -> dict:
	'''
	Return a dictionnary from string value holding tube information

	Exemple : T4001/1356
	Should be pardes like the following :
			- tube_id : T4001
			- liquid_volume : 1356 ul
	'''
	value_split = value.split('/')
	tube_id = ""
	liquid_level = 0
	try :
		tube_id = str(value_split[0])
		liquid_level = float(value_split[1])
	except:
		if value != "":
			node.get_logger().warning(f"Couldn't parse tube information from this value : {value}")
		else :
			node.get_logger().info(f"DEBUG : No tube information")
	return {"tube_id": tube_id, "liquid_level": liquid_level}

def container_information_parsing(node, value: str) -> dict:
	'''
	Return a dictionnary from string value holding container information

	Exemple : S0VC4002V1V46VT4001/1356VT4002/7877VVOK
	'''
	value_split = value.split('V')
	tube_info_list = []
	try :
		device_id = str(value_split[1])
		is_flipped = bool(value_split[2])
		available_tips = int(value_split[3])
		for i in range(4,len(value_split)-1):
			tube_info_list.append(tube_information_parsing(node, value_split[i]))
	except Exception as X:
		node.get_logger().error(f"Couldn't parse container information from this value : {value}, {X}")
	node.get_logger().info(f" list value {value_split}")
	#TODO:Ricky:Update for tips
	return {"device_id": device_id, "is_flipped": is_flipped, "external_resources": tube_info_list}

def rfid_info_callback(node, value:str) -> None:
	rfid_thread = Thread(target=rfid_info_update,args = (node, value), daemon=True)
	rfid_thread.start()

def rfid_info_update(node, value:str) -> None:
	'''
	Return None

	This callback allow to handle data value from rfid_info sensor type
	Exemple : S0VC4002V1V46VT4001/1356VT4002/7877VVOK
	format should be parsed like the following :
			- device_id
			- is_flipped
			- available_tips
			- tube_info1
			- tube_info2
			- tube_info3
			- tube_info4
	
	tube_infoX will held either tube information (should be 4 maximum)
	or plate information.
	this format should be able to handle all our current type of container
	'''
	container_args = {}

	stream_result = container_information_parsing(node, value)
	#TODO:Ricky:need to update container info from this with StateAPI
	#TODO:Ricky:here also give slot information from sensor information (one possibility is the sensor device name : RFID50207 meaning version 5, HAIVE4002, slot7)
	#TODO:Change for resource_id instead of tube_id

	#TODO:RICKY:TEST TO REMOVE
	temp_node = Node("temp_node")
	Hos.set_state(temp_node,"H4001",StateType.BOTH.value,{"turntable_slot":1, "x_position":2})
	Hos.set_state(temp_node,"H4001",StateType.BOTH.value,{"turntable_slot":1, "x_position":2}, ReentrantCallbackGroup())
	device_id = stream_result["device_id"]
	container_args["is_flipped"] = stream_result["is_flipped"]
	container_args["external_resources"] = json.dumps(stream_result["external_resources"])
	Hos.set_state(temp_node, device_id, StateType.BOTH.value, container_args, ReentrantCallbackGroup())
	for i in range(len(stream_result["external_resource"])):
		if stream_result["external_resource"][i]:
			if stream_result["external_resource"][i]["tube_id"]:
				resource_id = stream_result["external_resource"][i]["tube_id"]
				resource_args = stream_result["external_resource"][i]
				Hos.set_state(temp_node, resource_id, StateType.BOTH.value, resource_args, ReentrantCallbackGroup())
	return






