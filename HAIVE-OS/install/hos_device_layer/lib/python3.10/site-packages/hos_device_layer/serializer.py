from dataclasses import (dataclass, field)
from typing import List

from hos_interfaces.msg import (TypedField)


@dataclass
class CommandSerializerInfo:
  function_name: str
  serializer: List[str] = field(default_factory=lambda: [])

class CommandSerializer():
  """
  CommanSerializer is an object elding only the serialization information from the database
  it will after allow to generate api string (A$T$V$, ...) only from function_name and args
  """
  def __init__(self, serializer_infos: List[CommandSerializerInfo]):
    self._serializers = {}
    for info in serializer_infos:
      self._serializers[info.function_name] = info

  def serialize_command(self, function_name: str, args: List[TypedField]) -> (str, str):
    """
    Return APIString, error

    return the API string (A$T$V$, ...) according to the function_name and args

    Parameters
    ----------
    function_name (str) : name of the DeviceAPI function 
    args (Any) : argument of the target function
    """
    if function_name not in self._serializers.keys():
      return None, f"No serializer found for function `{function_name}`."

    info = self._serializers[function_name]

    if len(info.serializer) == 1:
      return info.serializer[0], ''

    if len(info.serializer) != len(args):
      return None, f"Cannot serialize command due to illegal arguments size. Expected {len(info.serializer)} but received {len(args)}."

    #Here the slicing happen feeding the function args in to the api format given in Airtable
    cmd = ''
    for i, cmd_slice in enumerate(info.serializer):
      cmd += f'{cmd_slice}{args[i].data}'

    return cmd, ''

  def can_command(self, function_name: str, args: List[TypedField]) -> (bytes, str):
    """
    Return APIbytes, error

    Create bytes for can communication according to function_name and args
    Parameters
    ----------
    function_name (str) : name of the DeviceAPI function 
    args (Any) : argument of the target function
    """

    if function_name not in self._serializers.keys():
      return None, f"No serializer found for function `{function_name}`."
