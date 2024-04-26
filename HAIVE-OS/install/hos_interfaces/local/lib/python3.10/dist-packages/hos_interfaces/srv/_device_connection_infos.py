# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hos_interfaces:srv/DeviceConnectionInfos.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DeviceConnectionInfos_Request(type):
    """Metaclass of message 'DeviceConnectionInfos_Request'."""

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
                'hos_interfaces.srv.DeviceConnectionInfos_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__device_connection_infos__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__device_connection_infos__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__device_connection_infos__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__device_connection_infos__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__device_connection_infos__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DeviceConnectionInfos_Request(metaclass=Metaclass_DeviceConnectionInfos_Request):
    """Message class 'DeviceConnectionInfos_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_DeviceConnectionInfos_Response(type):
    """Metaclass of message 'DeviceConnectionInfos_Response'."""

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
                'hos_interfaces.srv.DeviceConnectionInfos_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__device_connection_infos__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__device_connection_infos__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__device_connection_infos__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__device_connection_infos__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__device_connection_infos__response

            from hos_interfaces.msg import ConnectionInfo
            if ConnectionInfo.__class__._TYPE_SUPPORT is None:
                ConnectionInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DeviceConnectionInfos_Response(metaclass=Metaclass_DeviceConnectionInfos_Response):
    """Message class 'DeviceConnectionInfos_Response'."""

    __slots__ = [
        '_device_infos',
    ]

    _fields_and_field_types = {
        'device_infos': 'sequence<hos_interfaces/ConnectionInfo>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['hos_interfaces', 'msg'], 'ConnectionInfo')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.device_infos = kwargs.get('device_infos', [])

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
        if self.device_infos != other.device_infos:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def device_infos(self):
        """Message field 'device_infos'."""
        return self._device_infos

    @device_infos.setter
    def device_infos(self, value):
        if __debug__:
            from hos_interfaces.msg import ConnectionInfo
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
                 all(isinstance(v, ConnectionInfo) for v in value) and
                 True), \
                "The 'device_infos' field must be a set or sequence and each value of type 'ConnectionInfo'"
        self._device_infos = value


class Metaclass_DeviceConnectionInfos(type):
    """Metaclass of service 'DeviceConnectionInfos'."""

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
                'hos_interfaces.srv.DeviceConnectionInfos')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__device_connection_infos

            from hos_interfaces.srv import _device_connection_infos
            if _device_connection_infos.Metaclass_DeviceConnectionInfos_Request._TYPE_SUPPORT is None:
                _device_connection_infos.Metaclass_DeviceConnectionInfos_Request.__import_type_support__()
            if _device_connection_infos.Metaclass_DeviceConnectionInfos_Response._TYPE_SUPPORT is None:
                _device_connection_infos.Metaclass_DeviceConnectionInfos_Response.__import_type_support__()


class DeviceConnectionInfos(metaclass=Metaclass_DeviceConnectionInfos):
    from hos_interfaces.srv._device_connection_infos import DeviceConnectionInfos_Request as Request
    from hos_interfaces.srv._device_connection_infos import DeviceConnectionInfos_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
