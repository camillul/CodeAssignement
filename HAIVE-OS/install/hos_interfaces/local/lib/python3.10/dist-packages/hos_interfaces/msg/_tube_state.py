# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hos_interfaces:msg/TubeState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TubeState(type):
    """Metaclass of message 'TubeState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hos_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hos_interfaces.msg.TubeState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__tube_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__tube_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__tube_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__tube_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__tube_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TubeState(metaclass=Metaclass_TubeState):
    """Message class 'TubeState'."""

    __slots__ = [
        '_liquid_level',
        '_tube_id',
        '_tube_type',
        '_volume',
        '_temperature',
    ]

    _fields_and_field_types = {
        'liquid_level': 'float',
        'tube_id': 'string',
        'tube_type': 'string',
        'volume': 'float',
        'temperature': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.liquid_level = kwargs.get('liquid_level', float())
        self.tube_id = kwargs.get('tube_id', str())
        self.tube_type = kwargs.get('tube_type', str())
        self.volume = kwargs.get('volume', float())
        self.temperature = kwargs.get('temperature', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.liquid_level != other.liquid_level:
            return False
        if self.tube_id != other.tube_id:
            return False
        if self.tube_type != other.tube_type:
            return False
        if self.volume != other.volume:
            return False
        if self.temperature != other.temperature:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def liquid_level(self):
        """Message field 'liquid_level'."""
        return self._liquid_level

    @liquid_level.setter
    def liquid_level(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'liquid_level' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'liquid_level' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._liquid_level = value

    @builtins.property
    def tube_id(self):
        """Message field 'tube_id'."""
        return self._tube_id

    @tube_id.setter
    def tube_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'tube_id' field must be of type 'str'"
        self._tube_id = value

    @builtins.property
    def tube_type(self):
        """Message field 'tube_type'."""
        return self._tube_type

    @tube_type.setter
    def tube_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'tube_type' field must be of type 'str'"
        self._tube_type = value

    @builtins.property
    def volume(self):
        """Message field 'volume'."""
        return self._volume

    @volume.setter
    def volume(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'volume' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'volume' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._volume = value

    @builtins.property
    def temperature(self):
        """Message field 'temperature'."""
        return self._temperature

    @temperature.setter
    def temperature(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'temperature' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'temperature' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._temperature = value
