# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hos_interfaces:msg/P1000ContainerState.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'tips_availaible'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_P1000ContainerState(type):
    """Metaclass of message 'P1000ContainerState'."""

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
                'hos_interfaces.msg.P1000ContainerState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__p1000_container_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__p1000_container_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__p1000_container_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__p1000_container_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__p1000_container_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class P1000ContainerState(metaclass=Metaclass_P1000ContainerState):
    """Message class 'P1000ContainerState'."""

    __slots__ = [
        '_x_size',
        '_y_size',
        '_tips_availaible',
        '_is_flipped',
        '_slot_position',
        '_external_resources',
        '_temperature',
        '_is_movable',
        '_is_connected',
        '_last_ping',
        '_device_uid',
        '_is_reconnected',
        '_device_type',
        '_device_id',
    ]

    _fields_and_field_types = {
        'x_size': 'uint8',
        'y_size': 'uint8',
        'tips_availaible': 'sequence<uint16>',
        'is_flipped': 'boolean',
        'slot_position': 'uint8',
        'external_resources': 'string',
        'temperature': 'float',
        'is_movable': 'boolean',
        'is_connected': 'boolean',
        'last_ping': 'float',
        'device_uid': 'string',
        'is_reconnected': 'boolean',
        'device_type': 'string',
        'device_id': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint16')),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x_size = kwargs.get('x_size', int())
        self.y_size = kwargs.get('y_size', int())
        self.tips_availaible = array.array('H', kwargs.get('tips_availaible', []))
        self.is_flipped = kwargs.get('is_flipped', bool())
        self.slot_position = kwargs.get('slot_position', int())
        self.external_resources = kwargs.get('external_resources', str())
        self.temperature = kwargs.get('temperature', float())
        self.is_movable = kwargs.get('is_movable', bool())
        self.is_connected = kwargs.get('is_connected', bool())
        self.last_ping = kwargs.get('last_ping', float())
        self.device_uid = kwargs.get('device_uid', str())
        self.is_reconnected = kwargs.get('is_reconnected', bool())
        self.device_type = kwargs.get('device_type', str())
        self.device_id = kwargs.get('device_id', str())

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
        if self.x_size != other.x_size:
            return False
        if self.y_size != other.y_size:
            return False
        if self.tips_availaible != other.tips_availaible:
            return False
        if self.is_flipped != other.is_flipped:
            return False
        if self.slot_position != other.slot_position:
            return False
        if self.external_resources != other.external_resources:
            return False
        if self.temperature != other.temperature:
            return False
        if self.is_movable != other.is_movable:
            return False
        if self.is_connected != other.is_connected:
            return False
        if self.last_ping != other.last_ping:
            return False
        if self.device_uid != other.device_uid:
            return False
        if self.is_reconnected != other.is_reconnected:
            return False
        if self.device_type != other.device_type:
            return False
        if self.device_id != other.device_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x_size(self):
        """Message field 'x_size'."""
        return self._x_size

    @x_size.setter
    def x_size(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x_size' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'x_size' field must be an unsigned integer in [0, 255]"
        self._x_size = value

    @builtins.property
    def y_size(self):
        """Message field 'y_size'."""
        return self._y_size

    @y_size.setter
    def y_size(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y_size' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'y_size' field must be an unsigned integer in [0, 255]"
        self._y_size = value

    @builtins.property
    def tips_availaible(self):
        """Message field 'tips_availaible'."""
        return self._tips_availaible

    @tips_availaible.setter
    def tips_availaible(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'H', \
                "The 'tips_availaible' array.array() must have the type code of 'H'"
            self._tips_availaible = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 65536 for val in value)), \
                "The 'tips_availaible' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 65535]"
        self._tips_availaible = array.array('H', value)

    @builtins.property
    def is_flipped(self):
        """Message field 'is_flipped'."""
        return self._is_flipped

    @is_flipped.setter
    def is_flipped(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_flipped' field must be of type 'bool'"
        self._is_flipped = value

    @builtins.property
    def slot_position(self):
        """Message field 'slot_position'."""
        return self._slot_position

    @slot_position.setter
    def slot_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'slot_position' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'slot_position' field must be an unsigned integer in [0, 255]"
        self._slot_position = value

    @builtins.property
    def external_resources(self):
        """Message field 'external_resources'."""
        return self._external_resources

    @external_resources.setter
    def external_resources(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'external_resources' field must be of type 'str'"
        self._external_resources = value

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

    @builtins.property
    def is_movable(self):
        """Message field 'is_movable'."""
        return self._is_movable

    @is_movable.setter
    def is_movable(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_movable' field must be of type 'bool'"
        self._is_movable = value

    @builtins.property
    def is_connected(self):
        """Message field 'is_connected'."""
        return self._is_connected

    @is_connected.setter
    def is_connected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_connected' field must be of type 'bool'"
        self._is_connected = value

    @builtins.property
    def last_ping(self):
        """Message field 'last_ping'."""
        return self._last_ping

    @last_ping.setter
    def last_ping(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'last_ping' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'last_ping' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._last_ping = value

    @builtins.property
    def device_uid(self):
        """Message field 'device_uid'."""
        return self._device_uid

    @device_uid.setter
    def device_uid(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'device_uid' field must be of type 'str'"
        self._device_uid = value

    @builtins.property
    def is_reconnected(self):
        """Message field 'is_reconnected'."""
        return self._is_reconnected

    @is_reconnected.setter
    def is_reconnected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_reconnected' field must be of type 'bool'"
        self._is_reconnected = value

    @builtins.property
    def device_type(self):
        """Message field 'device_type'."""
        return self._device_type

    @device_type.setter
    def device_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'device_type' field must be of type 'str'"
        self._device_type = value

    @builtins.property
    def device_id(self):
        """Message field 'device_id'."""
        return self._device_id

    @device_id.setter
    def device_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'device_id' field must be of type 'str'"
        self._device_id = value
