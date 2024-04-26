# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hos_interfaces:srv/DeviceCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DeviceCommand_Request(type):
    """Metaclass of message 'DeviceCommand_Request'."""

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
                'hos_interfaces.srv.DeviceCommand_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__device_command__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__device_command__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__device_command__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__device_command__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__device_command__request

            from hos_interfaces.msg import TypedField
            if TypedField.__class__._TYPE_SUPPORT is None:
                TypedField.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DeviceCommand_Request(metaclass=Metaclass_DeviceCommand_Request):
    """Message class 'DeviceCommand_Request'."""

    __slots__ = [
        '_cmd_id',
        '_function_name',
        '_num_args',
        '_args',
    ]

    _fields_and_field_types = {
        'cmd_id': 'uint32',
        'function_name': 'string',
        'num_args': 'uint8',
        'args': 'sequence<hos_interfaces/TypedField>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['hos_interfaces', 'msg'], 'TypedField')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cmd_id = kwargs.get('cmd_id', int())
        self.function_name = kwargs.get('function_name', str())
        self.num_args = kwargs.get('num_args', int())
        self.args = kwargs.get('args', [])

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
        if self.cmd_id != other.cmd_id:
            return False
        if self.function_name != other.function_name:
            return False
        if self.num_args != other.num_args:
            return False
        if self.args != other.args:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def function_name(self):
        """Message field 'function_name'."""
        return self._function_name

    @function_name.setter
    def function_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'function_name' field must be of type 'str'"
        self._function_name = value

    @builtins.property
    def num_args(self):
        """Message field 'num_args'."""
        return self._num_args

    @num_args.setter
    def num_args(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_args' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_args' field must be an unsigned integer in [0, 255]"
        self._num_args = value

    @builtins.property
    def args(self):
        """Message field 'args'."""
        return self._args

    @args.setter
    def args(self, value):
        if __debug__:
            from hos_interfaces.msg import TypedField
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
                 all(isinstance(v, TypedField) for v in value) and
                 True), \
                "The 'args' field must be a set or sequence and each value of type 'TypedField'"
        self._args = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_DeviceCommand_Response(type):
    """Metaclass of message 'DeviceCommand_Response'."""

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
                'hos_interfaces.srv.DeviceCommand_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__device_command__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__device_command__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__device_command__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__device_command__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__device_command__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DeviceCommand_Response(metaclass=Metaclass_DeviceCommand_Response):
    """Message class 'DeviceCommand_Response'."""

    __slots__ = [
        '_is_valid',
        '_error',
    ]

    _fields_and_field_types = {
        'is_valid': 'boolean',
        'error': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.is_valid = kwargs.get('is_valid', bool())
        self.error = kwargs.get('error', str())

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
        if self.is_valid != other.is_valid:
            return False
        if self.error != other.error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def is_valid(self):
        """Message field 'is_valid'."""
        return self._is_valid

    @is_valid.setter
    def is_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_valid' field must be of type 'bool'"
        self._is_valid = value

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


class Metaclass_DeviceCommand(type):
    """Metaclass of service 'DeviceCommand'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hos_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hos_interfaces.srv.DeviceCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__device_command

            from hos_interfaces.srv import _device_command
            if _device_command.Metaclass_DeviceCommand_Request._TYPE_SUPPORT is None:
                _device_command.Metaclass_DeviceCommand_Request.__import_type_support__()
            if _device_command.Metaclass_DeviceCommand_Response._TYPE_SUPPORT is None:
                _device_command.Metaclass_DeviceCommand_Response.__import_type_support__()


class DeviceCommand(metaclass=Metaclass_DeviceCommand):
    from hos_interfaces.srv._device_command import DeviceCommand_Request as Request
    from hos_interfaces.srv._device_command import DeviceCommand_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
