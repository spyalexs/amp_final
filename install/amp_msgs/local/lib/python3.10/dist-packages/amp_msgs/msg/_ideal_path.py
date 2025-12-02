# generated from rosidl_generator_py/resource/_idl.py.em
# with input from amp_msgs:msg/IdealPath.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'duration_array'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_IdealPath(type):
    """Metaclass of message 'IdealPath'."""

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
            module = import_type_support('amp_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'amp_msgs.msg.IdealPath')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ideal_path
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ideal_path
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ideal_path
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ideal_path
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ideal_path

            from amp_msgs.msg import AgentControl
            if AgentControl.__class__._TYPE_SUPPORT is None:
                AgentControl.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class IdealPath(metaclass=Metaclass_IdealPath):
    """Message class 'IdealPath'."""

    __slots__ = [
        '_control_array',
        '_duration_array',
        '_run_time',
    ]

    _fields_and_field_types = {
        'control_array': 'sequence<amp_msgs/AgentControl>',
        'duration_array': 'sequence<float>',
        'run_time': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['amp_msgs', 'msg'], 'AgentControl')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.control_array = kwargs.get('control_array', [])
        self.duration_array = array.array('f', kwargs.get('duration_array', []))
        self.run_time = kwargs.get('run_time', float())

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
        if self.control_array != other.control_array:
            return False
        if self.duration_array != other.duration_array:
            return False
        if self.run_time != other.run_time:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def control_array(self):
        """Message field 'control_array'."""
        return self._control_array

    @control_array.setter
    def control_array(self, value):
        if __debug__:
            from amp_msgs.msg import AgentControl
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
                 all(isinstance(v, AgentControl) for v in value) and
                 True), \
                "The 'control_array' field must be a set or sequence and each value of type 'AgentControl'"
        self._control_array = value

    @builtins.property
    def duration_array(self):
        """Message field 'duration_array'."""
        return self._duration_array

    @duration_array.setter
    def duration_array(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'duration_array' array.array() must have the type code of 'f'"
            self._duration_array = value
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'duration_array' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._duration_array = array.array('f', value)

    @builtins.property
    def run_time(self):
        """Message field 'run_time'."""
        return self._run_time

    @run_time.setter
    def run_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'run_time' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'run_time' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._run_time = value
