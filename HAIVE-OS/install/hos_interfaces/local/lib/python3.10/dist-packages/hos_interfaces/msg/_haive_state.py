# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hos_interfaces:msg/HaiveState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HaiveState(type):
    """Metaclass of message 'HaiveState'."""

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
                'hos_interfaces.msg.HaiveState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__haive_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__haive_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__haive_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__haive_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__haive_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HaiveState(metaclass=Metaclass_HaiveState):
    """Message class 'HaiveState'."""

    __slots__ = [
        '_x_position',
        '_y_position',
        '_turntable_slot',
        '_is_connected',
        '_last_ping',
        '_device_uid',
        '_is_reconnected',
        '_device_type',
        '_device_id',
    ]

    _fields_and_field_types = {
        'x_position': 'uint8',
        'y_position': 'uint8',
        'turntable_slot': 'uint8',
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
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
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
        self.x_position = kwargs.get('x_position', int())
        self.y_position = kwargs.get('y_position', int())
        self.turntable_slot = kwargs.get('turntable_slot', int())
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
        if self.x_position != other.x_position:
            return False
        if self.y_position != other.y_position:
            return False
        if self.turntable_slot != other.turntable_slot:
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
    def x_position(self):
        """Message field 'x_position'."""
        return self._x_position

    @x_position.setter
    def x_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x_position' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'x_position' field must be an unsigned integer in [0, 255]"
        self._x_position = value

    @builtins.property
    def y_position(self):
        """Message field 'y_position'."""
        return self._y_position

    @y_position.setter
    def y_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y_position' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'y_position' field must be an unsigned integer in [0, 255]"
        self._y_position = value

    @builtins.property
    def turntable_slot(self):
        """Message field 'turntable_slot'."""
        return self._turntable_slot

    @turntable_slot.setter
    def turntable_slot(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'turntable_slot' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'turntable_slot' field must be an unsigned integer in [0, 255]"
        self._turntable_slot = value

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
