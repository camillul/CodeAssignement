# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hos_interfaces:srv/BehaviorRequestMoveContainer.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BehaviorRequestMoveContainer_Request(type):
    """Metaclass of message 'BehaviorRequestMoveContainer_Request'."""

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
                'hos_interfaces.srv.BehaviorRequestMoveContainer_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__behavior_request_move_container__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__behavior_request_move_container__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__behavior_request_move_container__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__behavior_request_move_container__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__behavior_request_move_container__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BehaviorRequestMoveContainer_Request(metaclass=Metaclass_BehaviorRequestMoveContainer_Request):
    """Message class 'BehaviorRequestMoveContainer_Request'."""

    __slots__ = [
        '_container_id',
        '_haive_id',
        '_slot',
    ]

    _fields_and_field_types = {
        'container_id': 'string',
        'haive_id': 'string',
        'slot': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.container_id = kwargs.get('container_id', str())
        self.haive_id = kwargs.get('haive_id', str())
        self.slot = kwargs.get('slot', int())

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
        if self.container_id != other.container_id:
            return False
        if self.haive_id != other.haive_id:
            return False
        if self.slot != other.slot:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def container_id(self):
        """Message field 'container_id'."""
        return self._container_id

    @container_id.setter
    def container_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'container_id' field must be of type 'str'"
        self._container_id = value

    @builtins.property
    def haive_id(self):
        """Message field 'haive_id'."""
        return self._haive_id

    @haive_id.setter
    def haive_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'haive_id' field must be of type 'str'"
        self._haive_id = value

    @builtins.property
    def slot(self):
        """Message field 'slot'."""
        return self._slot

    @slot.setter
    def slot(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'slot' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'slot' field must be an unsigned integer in [0, 255]"
        self._slot = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_BehaviorRequestMoveContainer_Response(type):
    """Metaclass of message 'BehaviorRequestMoveContainer_Response'."""

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
                'hos_interfaces.srv.BehaviorRequestMoveContainer_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__behavior_request_move_container__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__behavior_request_move_container__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__behavior_request_move_container__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__behavior_request_move_container__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__behavior_request_move_container__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BehaviorRequestMoveContainer_Response(metaclass=Metaclass_BehaviorRequestMoveContainer_Response):
    """Message class 'BehaviorRequestMoveContainer_Response'."""

    __slots__ = [
        '_success',
        '_error',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
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
        self.success = kwargs.get('success', bool())
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
        if self.success != other.success:
            return False
        if self.error != other.error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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


class Metaclass_BehaviorRequestMoveContainer(type):
    """Metaclass of service 'BehaviorRequestMoveContainer'."""

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
                'hos_interfaces.srv.BehaviorRequestMoveContainer')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__behavior_request_move_container

            from hos_interfaces.srv import _behavior_request_move_container
            if _behavior_request_move_container.Metaclass_BehaviorRequestMoveContainer_Request._TYPE_SUPPORT is None:
                _behavior_request_move_container.Metaclass_BehaviorRequestMoveContainer_Request.__import_type_support__()
            if _behavior_request_move_container.Metaclass_BehaviorRequestMoveContainer_Response._TYPE_SUPPORT is None:
                _behavior_request_move_container.Metaclass_BehaviorRequestMoveContainer_Response.__import_type_support__()


class BehaviorRequestMoveContainer(metaclass=Metaclass_BehaviorRequestMoveContainer):
    from hos_interfaces.srv._behavior_request_move_container import BehaviorRequestMoveContainer_Request as Request
    from hos_interfaces.srv._behavior_request_move_container import BehaviorRequestMoveContainer_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
