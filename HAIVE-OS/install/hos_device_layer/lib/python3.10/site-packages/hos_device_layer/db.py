"""
db.py is a file that create dataclass and some method for the database object loaded from Airtable
"""

from dataclasses import (dataclass, field)
from typing import (List, Union)
from abc import ABC

from hos_utils.airtable import (AT_KEY_ID, AT_KEY_CREATED, AT_KEY_FIELDS)
#These are just variable so that can easly replace the keys if there is any airtable change are whatever
# AT_KEY_ID, refer to id or token in the database (ngGI54HBjn)

@dataclass
class AttributeArg():
  arg_name: str
  arg_type: str

@dataclass
class Record(ABC):
  id: str
  created_at: str

@dataclass
class DevicesRecord(Record):
  device_type: str
  device_role: str
  serialized_api: bool
  description: str

@dataclass
class CommunicationTargetsRecord(Record):
  communication_target: str

@dataclass
class APIsRecord(Record):
  function_name: str
  description: str
  arguments: List[str] = field(default_factory=lambda: [])
  results: List[str] = field(default_factory=lambda: [])
  device_type_ids: List[str] = field(default_factory=lambda: [])
  api_serializer_id: str = None

@dataclass
class StreamsRecord(Record):
  stream: str
  description: str
  values: List[str] = field(default_factory=lambda: [])
  device_type_ids: List[str] = field(default_factory=lambda: [])

@dataclass
class FleetRecord(Record):
  device_id: str
  device_uid: str
  device_type_id: str
  communication_target: str
  child_device: List[str] = field(default_factory=lambda: [])
  wifi_info: str = None
  serial_info: str = None
  can_info: str = None
  baud_rate:int = None

@dataclass
class APISerializerRecord(Record):
  serializer: str
  function_name_id: str

@dataclass
class RobotStateRecord(Record):
  ros_state_msg: str
  device_type: List[str] = field(default_factory=lambda: [])
  attributes: List[AttributeArg] = field(default_factory=lambda: [])
  inheritance: str = ''




def cast_db_type_str(db_type: str) -> Union[str, str]:
  """
  Return type, error
  
  translate string type to python string type
  """
  if db_type == 'bool': return 'bool', ''
  elif db_type == 'char': return 'str', ''
  elif db_type == 'string': return 'str', ''
  elif db_type == 'int8': return 'int', ''
  elif db_type == 'int16': return 'int', ''
  elif db_type == 'int32': return 'int', ''
  elif db_type == 'int64': return 'int', ''
  elif db_type == 'uint8': return 'int', ''
  elif db_type == 'uint16': return 'int', ''
  elif db_type == 'uint32': return 'int', ''
  elif db_type == 'uint64': return 'int', ''
  elif db_type == 'float32': return 'float', ''
  elif db_type == 'float64': return 'float', ''
  else: return None, f"Casting failed! Invalid type '{db_type}' passed."

def cast_db_type(db_type: str, value: str) -> Union[str, str]:
  """
  Return value, error

  actually cast type for value and return them with error information
  """
  try:
    if db_type == 'bool':
      if value == 'False':
        return False, ''
      elif value == 'True':
        return True, ''
      else:
        raise ValueError(f"Unable to cast `{value}` to boolean type.")
    elif db_type == 'char': return str(value), ''
    elif db_type == 'string': return str(value), ''
    elif db_type == 'int8': return int(float(value)), ''
    elif db_type == 'int16': return int(float(value)), ''
    elif db_type == 'int32': return int(float(value)), ''
    elif db_type == 'int64': return int(float(value)), ''
    elif db_type == 'uint8': return int(float(value)), ''
    elif db_type == 'uint16': return int(float(value)), ''
    elif db_type == 'uint32': return int(float(value)), ''
    elif db_type == 'uint64': return int(float(value)), ''
    elif db_type == 'float32': return float(value), ''
    elif db_type == 'float64': return float(value), ''
    else: return None, f"Casting failed! Invalid type '{db_type}' passed."
  except:
    return None, f"Casting failed! Unable to cast value '{value}' to type '{db_type}'."


class Database():
  """
  Database object, this one held all tables information as dataclass in attributes
  """
  def __init__(self, db_data: dict) -> None:
    self._devices = {}
    self._apis = {}
    self._api_serializers = {}
    self._streams = {}
    self._fleet = {}
    self._robot_state = {}
    self._communication_targets = {}

    self._store(db_data)

  def _store(self, db_data: dict):
    """
    Return None

    this is internally called in the def __init__ method and allow from database information to create dataclass object and feed them in self attributes
    db_data is the raw object downloaded from Airtable
    it can be unpacked as table for instance : 

    devices, apis, api_serializers, streams, robot_state, fleet = db_data

    once unpack it's a dictionnary with id, created_time and field informations
    
    Then instead of browsing the db_data, we create dataclass object called <table_name>Record.
    all of them inherit from the object Record with 2 attributes : Id and Created time 

    """
    #If you add tables, fleet need to be the last arg anyway
    devices, apis, api_serializers, streams, robot_state, fleet = db_data

    #Here we feel all information about devices table in Airtable
    #Please refere to _store method for more details
    for d in devices:
      reference_id = d[AT_KEY_ID]
      serialized_api = False
      if 'serialized_api' in d[AT_KEY_FIELDS]:
        serialized_api = d[AT_KEY_FIELDS]['serialized_api']
      #Here we initialize the Record object and append to the devices attribute of the Database class object
      self._devices[reference_id] = DevicesRecord(
        reference_id, #name
        d[AT_KEY_CREATED],#time
        d[AT_KEY_FIELDS]['device_type'], #device_type (e.g : DeltaHAive, Container, Falcon, )
        d[AT_KEY_FIELDS]['device_role'], #device_role (e.g : haive, container, equipement, sensor)
        serialized_api, #boolean, if there is serialized API or not
        d[AT_KEY_FIELDS]['description'], #description iven by the developper in Airtaible
      )

    #TODO:Ricky: Why comm table won't be unpack ?
    # for com_target in communication_targets:
    #   reference_id = communication_target[AT_KEY_ID]
    #   #Here we initialize the Record object and append to the api_serializer attribute of the Database class object : self._apis
    #   self._communication_targets[reference_id] = CommunicationTargetsRecord(
    #     id =                reference_id, #id/token
    #     created_at =        com_target[AT_KEY_CREATED], #time
    #     communication_target =     com_target[AT_KEY_FIELDS]['communication_target'],      
    #   )
      
    #here we feed all information about API function in Airtable
    #Please refere to _store method for more details
    for a in apis:
      reference_id = a[AT_KEY_ID]
      #Here we initialize the Record object and append to the api_serializer attribute of the Database class object : self._apis
      self._apis[reference_id] = APIsRecord(
        id =                reference_id, #id/token
        created_at =        a[AT_KEY_CREATED], #time
        function_name =     a[AT_KEY_FIELDS]['function_name'], #name of the API function
        description =       a[AT_KEY_FIELDS]['description'], #description iven by the developper in Airtaible
        device_type_ids =   a[AT_KEY_FIELDS]['device_types'], #device_type related to this API function
      )
      #args can be empty so that we don't raise an Exception, we treat this in a if statement (inside the Record dataclass, this args is defined as empty by default)
      if 'arguments' in a[AT_KEY_FIELDS]:
        self._apis[reference_id].arguments = a[AT_KEY_FIELDS]['arguments']
      #result can be empty so that we don't raise an Exception, we treat this in a if statement (inside the Record dataclass, this arg is defined as empty by default)
      if 'results' in a[AT_KEY_FIELDS]:
        self._apis[reference_id].results = a[AT_KEY_FIELDS]['results']
      #api_serializer can be empty so that we don't raise an Exception, we treat this in a if statement (inside the Record dataclass, args is defined as empty by default)
      #api_serializer can be empty because sometimes the API is given by a python library or something, in that case this attribute should be empty
      if 'api_serializer' in a[AT_KEY_FIELDS]:
        self._apis[reference_id].api_serializer_id = a[AT_KEY_FIELDS]['api_serializer'][0]


    #Here we feed all information about api_serializer table in Airtable
    #Please refere to _store method for more details
    for se in api_serializers:
      reference_id = se[AT_KEY_ID]
      #Here we initialize the Record object and append to the api_serializer attribute of the Database class object : self._api_serializers
      self._api_serializers[reference_id] = APISerializerRecord(
        reference_id, #id/token
        se[AT_KEY_CREATED], #time
        se[AT_KEY_FIELDS]['serializer'], #seriliazer format with $
        se[AT_KEY_FIELDS]['function_name'][0], #function name, link/reference to the api table
      )

    #Here we feed all information about stream table in Airtable
    #Please refere to _store method for more details
    for s in streams:
      reference_id = s[AT_KEY_ID]
      #Here we initialize the Record object and append to the stream attribute of the Database class object : self._streams
      self._streams[reference_id] = StreamsRecord(
        reference_id,
        s[AT_KEY_CREATED],
        s[AT_KEY_FIELDS]['stream'], #stream_name
        s[AT_KEY_FIELDS]['description'], #description iven by the developper in Airtaible
        s[AT_KEY_FIELDS]['values'], #values est le type de donnée du stream
        s[AT_KEY_FIELDS]['device_types'], #device_type refer which type of device could stream those data
      )

    #Here we feel all information about devices table in Airtable
    #Please refere to _store method for more details
    for r in robot_state:
      reference_id = r[AT_KEY_ID] 
      #Here we initialize the Record object and append to the robot_state attribute of the Database class object : self._robot_state
      self._robot_state[reference_id] = RobotStateRecord(
        reference_id, #id/token
        r[AT_KEY_CREATED], #time
        r[AT_KEY_FIELDS]['ros_state_msg'], #robot_state_msg name
      )
      #attributes can be empty so that we don't raise an Exception, we treat this in a if statement (inside the Record dataclass, this arg is defined as empty by default)
      #some robot_state_msg are only inheritance of other messages that's why they dont have any further attributes.
      if 'attributes' in r[AT_KEY_FIELDS]:
          self._robot_state[reference_id].attributes = [AttributeArg(arg_name, arg_type) for arg_name, arg_type in [arg.split(':') for arg in r[AT_KEY_FIELDS]['attributes']]]
      #inherithance can be empty so that we don't raise an Exception, we treat this in a if statement (inside the Record dataclass, this arg is defined as empty by default)
      if 'inheritance' in r[AT_KEY_FIELDS]:
        self._robot_state[reference_id].inheritance = r[AT_KEY_FIELDS]['inheritance']
      #device_type can be empty so that we don't raise an Exception, we treat this in a if statement (inside the Record dataclass, this arg is defined as empty by default)
      #they might be empty espacially for abstract robot_state_msg such as DeviceState
      if 'device_type' in r[AT_KEY_FIELDS]:
        for device_type_id in r[AT_KEY_FIELDS]['device_type']:
          self._robot_state[reference_id].device_type.append(self._devices[device_type_id].device_type)
        #TODO:Ricky:Maybe needs to be changed if several Device type share the same ros_state_msg.

    # Here we feel all information about fleet table in Airtable
    # Please refere to _store method for more details
    # WARNING, fleet should always be done at last        
    for f in fleet:
      reference_id = f[AT_KEY_ID]
      self._fleet[reference_id] = FleetRecord(
        reference_id, #id/token
        f[AT_KEY_CREATED], # time
        f[AT_KEY_FIELDS]['device_id'], #device_id, name of the device (e.g. : C4001)
        f[AT_KEY_FIELDS]['device_uid'], #device_uid, serie number of the chip as an unique identifier
        f[AT_KEY_FIELDS]['device_type'][0], #device_type (e.g : DeltaHAive, Container, Falcon,.. )
        f[AT_KEY_FIELDS]['communication_target'], #giving communication type information (wifi, serial, can , ...)

      )

    # child_device can be empty so that we don't raise an Exception, we treat this in a if statement (inside the Record dataclass, this arg is defined as empty by default)
    # child device is necessary if there is a device or sensor that belong to a parent device so that automatically those device subcribe to their children and trigger any callback if there is any
    for f in fleet:
      reference_id = f[AT_KEY_ID]
      if 'child_device' in f[AT_KEY_FIELDS]:
        for child_device_id in f[AT_KEY_FIELDS]['child_device']:
          self._fleet[reference_id].child_device.append(self._fleet[child_device_id].device_id) #child_device are device_id names

    # wifi_info, can_info, serial_info can be empty so that we don't raise an Exception, we treat this in a if statement (inside the Record dataclass, this arg is defined as empty by default)
    # those infos are necessary to know for instance which port it should communicate.
    for f in fleet:
      reference_id = f[AT_KEY_ID]
      if 'wifi_info' in f[AT_KEY_FIELDS]:
        self._fleet[reference_id].wifi_info = f[AT_KEY_FIELDS]['wifi_info']

    for f in fleet:
      reference_id = f[AT_KEY_ID]
      if 'serial_info' in f[AT_KEY_FIELDS]:
        self._fleet[reference_id].serial_info = f[AT_KEY_FIELDS]['serial_info']

    for f in fleet:
      reference_id = f[AT_KEY_ID]
      if 'can_info' in f[AT_KEY_FIELDS]:
        self._fleet[reference_id].can_info = f[AT_KEY_FIELDS]['can_info']
    # Also giving baud_rate information for can and serial 
    for f in fleet:
      reference_id = f[AT_KEY_ID]
      if 'baud_rate' in f[AT_KEY_FIELDS]:
        self._fleet[reference_id].baud_rate = f[AT_KEY_FIELDS]['baud_rate']


    self.update_attributes_robot_state(robot_state)

  def update_attributes_robot_state(self,robot_state_from_db):
    '''
    Return None

    Update RobotState list according to inheritance
    '''

    #Init first all robot_state with no inheritance
    parent_robot_states = []
    count = 0
    timeout = 0
    for robot_state in robot_state_from_db:
      reference_id = robot_state[AT_KEY_ID]
      r = self._robot_state[reference_id]
      if not r.inheritance:
        parent_robot_states.append(r)
        count += 1
    #TODO:Ricky:Count threshold need to be changed if we want to do multi-inheritance
    #Now that every robot_state_without inheritance has been created, we create the others
    while count < len(self._robot_state.values()):
      #iteration through all robot_state Records object.
      for robot_state in robot_state_from_db:
        reference_id = robot_state[AT_KEY_ID]
        r = self._robot_state[reference_id]
        #First we get robot_state record of parents referred in inherithance (we only have the name but we want all attributes of those parents state)
        robot_state_msg_parent_list = [(parent_r.ros_state_msg) for parent_r in parent_robot_states if (parent_r.ros_state_msg in r.inheritance)]
        #Then we fuse all attributes of those parents
        attributes_parent_list = [(parent_r.attributes) for parent_r in parent_robot_states if (parent_r.ros_state_msg in r.inheritance)]
        # Here a state jsut to check that it correspond to properly to the robot_state inheritance information
        if r.inheritance == robot_state_msg_parent_list:
          #Then we fuse all the attributes and add it to the record object
          for parent_r_attributes in attributes_parent_list:
            for attribute in parent_r_attributes:
              if not (attribute in r.attributes):
                r.attributes.extend(parent_r_attributes)
          parent_robot_states.append(r)
          count += 1

  def get_fleet(self) -> List[FleetRecord]:
    """
    Return List[FleetRecord]

    return all record of fleet table
    """
    return [f for f in self._fleet.values()]

  def get_fleet_device(self, device_id: str) -> FleetRecord:
    """
    Return FleetRecord

    Return a fleet record from device_id
    """
    for f in self._fleet.values():
      if f.device_id == device_id:
        return f
    return None

  def get_device_id(self, device_uid: int) -> str:
    """
    Return string

    return a device_id from device_uid information (be sure that you are checking in the right fleet)
    """
    for f in self.get_fleet():
      if f.device_uid == device_uid:
        return f.device_id
    return None

  def get_device_uid(self, device_id: str) -> int:
    """
    Return int

    get device_uid from device_id information (be sure that you are checking in the right fleet)
    """
    fleet_record = self.get_fleet_device(device_id)
    if not fleet_record:
      return None

    try:
      return int(fleet_record.device_uid)
    except:
      return None

  def get_device_info(self, device_id: str) -> DevicesRecord:
    """
    Return DevicesRecord

    return a DevicesRecord by giving device_id
    """
    fleet_device = self.get_fleet_device(device_id)
    if not fleet_device:
      return None

    if fleet_device.device_type_id not in self._devices.keys():
      return None

    return self._devices[fleet_device.device_type_id]

  def get_device_functions(self, device_id: str) -> List[APIsRecord]:
    """
    Return List[APIsRecord]

    from device_id return a list of all possible API of this device
    """
    device_info = self.get_device_info(device_id)
    if not device_info:
      return None

    device_record_id = device_info.id
    functions = []
    for a in self._apis.values():
      if device_record_id in a.device_type_ids:
        functions.append(a)

    return functions

  def get_device_function_info(self, device_id: str, function_name: str) -> APIsRecord:
    """
    Return APIsRecord

    from function_name and device_id, it can return the APIsRecord object (helding api_serializer information for instance)
    """
    apis = self.get_device_functions(device_id)
    if not apis:
      return None

    for a in apis:
      if a.function_name == function_name:
        return a

    return None

  def get_api_serializer(self, function_name: str) -> APISerializerRecord:
    """
    Return APISerializerRecord

    from a function_name you can get the related APISerializerRecord
    """
    serializer_id = None

    for a in self._apis.values():
      if a.function_name == function_name:
        serializer_id = a.api_serializer_id

    if serializer_id == None:
      return None

    for se in self._api_serializers.values():
      if se.id == serializer_id:
        return se

    return None

  def get_device_streams(self, device_id: str) -> List[StreamsRecord]:
    """
    Return List[StreamsRecord]

    from a device_id, return the list of all StreamsRecord giving stream name, values, ...
    """
    #TODO:Ricky:need to be update so that child object stream are also referred.
    device_info = self.get_device_info(device_id)
    if not device_info:
      return None

    device_record_id = device_info.id
    streams = []
    for s in self._streams.values():
      if device_record_id in s.device_type_ids:
        streams.append(s)

    return streams

  def get_device_stream_info(self, device_id: str, stream: str) -> StreamsRecord:
    """
    Return StreamsRecord

    from device_id and stream value, return the StreamsRecord informations
    """
    streams = self.get_device_streams(device_id)
    if not streams:
      return None

    for s in streams:
      if s.stream == stream:
        return s
        
  def get_robot_state(self, device_type: str ) -> RobotStateRecord:
    """
    Return RobotStateRecord

    from device type, return the RobotStateRecord (equivalent to robot_state_msg information)
    """
    if not robot_state:
      return None

    for r in robot_state:
      if r.device_type == device_type:
        return r
    return None
