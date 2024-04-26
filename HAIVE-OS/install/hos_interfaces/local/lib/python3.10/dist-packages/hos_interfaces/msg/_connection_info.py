# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hos_interfaces:msg/ConnectionInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ConnectionInfo(type):
    """Metaclass of message 'ConnectionInfo'."""

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
                'hos_interfaces.msg.ConnectionInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__connection_info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__connection_info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__connection_info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__connection_info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__connection_info

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ConnectionInfo(metaclass=Metaclass_ConnectionInfo):
    """Message class 'ConnectionInfo'."""

    __slots__ = [
        '_device_id',
        '_device_uid',
        '_device_type',
        '_event_time_s',
    ]

    _fields_and_field_types = {
        'device_id': 'string',
        'device_uid': 'uint32',
        'device_type': 'string',
        'event_time_s': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.device_id = kwargs.get('device_id', str())
        self.device_uid = kwargs.get('device_uid', int())
        self.device_type = kwargs.get('device_type', str())
        self.event_time_s = kwargs.get('event_time_s', float())

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
        if self.device_id != other.device_id:
            return False
        if self.device_uid != other.device_uid:
            return False
        if self.device_type != other.device_type:
            return False
        if self.event_time_s != other.event_time_s:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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

    @builtins.property
    def device_uid(self):
        """Message field 'device_uid'."""
        return self._device_uid

    @device_uid.setter
    def device_uid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'device_uid' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'device_uid' field must be an unsigned integer in [0, 4294967295]"
        self._device_uid = value

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
    def event_time_s(self):
        """Message field 'event_time_s'."""
        return self._event_time_s

    @event_time_s.setter
    def event_time_s(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'event_time_s' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'event_time_s' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._event_time_s = value
