# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hos_interfaces:msg/DeviceCommandResult.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DeviceCommandResult(type):
    """Metaclass of message 'DeviceCommandResult'."""

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
                'hos_interfaces.msg.DeviceCommandResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__device_command_result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__device_command_result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__device_command_result
            cls._TYPE_SUPPORT = module.type_support_msg__msg__device_command_result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__device_command_result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DeviceCommandResult(metaclass=Metaclass_DeviceCommandResult):
    """Message class 'DeviceCommandResult'."""

    __slots__ = [
        '_uid',
        '_cmd_id',
        '_success',
        '_error',
        '_result_str',
    ]

    _fields_and_field_types = {
        'uid': 'uint32',
        'cmd_id': 'uint32',
        'success': 'boolean',
        'error': 'string',
        'result_str': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.uid = kwargs.get('uid', int())
        self.cmd_id = kwargs.get('cmd_id', int())
        self.success = kwargs.get('success', bool())
        self.error = kwargs.get('error', str())
        self.result_str = kwargs.get('result_str', str())

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
        if self.uid != other.uid:
            return False
        if self.cmd_id != other.cmd_id:
            return False
        if self.success != other.success:
            return False
        if self.error != other.error:
            return False
        if self.result_str != other.result_str:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def uid(self):
        """Message field 'uid'."""
        return self._uid

    @uid.setter
    def uid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'uid' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'uid' field must be an unsigned integer in [0, 4294967295]"
        self._uid = value

    @builtins.property
    def cmd_id(self):
        """Message field 'cmd_id'."""
        return self._cmd_id

    @cmd_id.setter
    def cmd_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cmd_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'cmd_id' field must be an unsigned integer in [0, 4294967295]"
        self._cmd_id = value

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def error(self):
        """Message field 'error'."""
        return self._error

    @error.setter
    def error(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'error' field must be of type 'str'"
        self._error = value

    @builtins.property
    def result_str(self):
        """Message field 'result_str'."""
        return self._result_str

    @result_str.setter
    def result_str(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'result_str' field must be of type 'str'"
        self._result_str = value
