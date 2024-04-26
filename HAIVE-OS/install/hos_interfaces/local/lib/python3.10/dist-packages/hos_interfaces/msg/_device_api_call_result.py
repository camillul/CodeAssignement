# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hos_interfaces:msg/DeviceAPICallResult.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DeviceAPICallResult(type):
    """Metaclass of message 'DeviceAPICallResult'."""

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
                'hos_interfaces.msg.DeviceAPICallResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__device_api_call_result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__device_api_call_result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__device_api_call_result
            cls._TYPE_SUPPORT = module.type_support_msg__msg__device_api_call_result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__device_api_call_result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DeviceAPICallResult(metaclass=Metaclass_DeviceAPICallResult):
    """Message class 'DeviceAPICallResult'."""

    __slots__ = [
        '_task_id',
        '_success',
        '_error',
        '_result_jsons',
        '_request_time_s',
        '_response_time_s',
    ]

    _fields_and_field_types = {
        'task_id': 'uint32',
        'success': 'boolean',
        'error': 'string',
        'result_jsons': 'string',
        'request_time_s': 'double',
        'response_time_s': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.task_id = kwargs.get('task_id', int())
        self.success = kwargs.get('success', bool())
        self.error = kwargs.get('error', str())
        self.result_jsons = kwargs.get('result_jsons', str())
        self.request_time_s = kwargs.get('request_time_s', float())
        self.response_time_s = kwargs.get('response_time_s', float())

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
        if self.task_id != other.task_id:
            return False
        if self.success != other.success:
            return False
        if self.error != other.error:
            return False
        if self.result_jsons != other.result_jsons:
            return False
        if self.request_time_s != other.request_time_s:
            return False
        if self.response_time_s != other.response_time_s:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def task_id(self):
        """Message field 'task_id'."""
        return self._task_id

    @task_id.setter
    def task_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'task_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'task_id' field must be an unsigned integer in [0, 4294967295]"
        self._task_id = value

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
    def result_jsons(self):
        """Message field 'result_jsons'."""
        return self._result_jsons

    @result_jsons.setter
    def result_jsons(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'result_jsons' field must be of type 'str'"
        self._result_jsons = value

    @builtins.property
    def request_time_s(self):
        """Message field 'request_time_s'."""
        return self._request_time_s

    @request_time_s.setter
    def request_time_s(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'request_time_s' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'request_time_s' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._request_time_s = value

    @builtins.property
    def response_time_s(self):
        """Message field 'response_time_s'."""
        return self._response_time_s

    @response_time_s.setter
    def response_time_s(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'response_time_s' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'response_time_s' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._response_time_s = value
