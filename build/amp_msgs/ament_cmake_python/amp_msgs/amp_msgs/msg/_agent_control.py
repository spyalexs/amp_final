# generated from rosidl_generator_py/resource/_idl.py.em
# with input from amp_msgs:msg/AgentControl.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AgentControl(type):
    """Metaclass of message 'AgentControl'."""

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
                'amp_msgs.msg.AgentControl')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__agent_control
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__agent_control
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__agent_control
            cls._TYPE_SUPPORT = module.type_support_msg__msg__agent_control
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__agent_control

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AgentControl(metaclass=Metaclass_AgentControl):
    """Message class 'AgentControl'."""

    __slots__ = [
        '_u0',
        '_u1',
        '_u2',
        '_u3',
    ]

    _fields_and_field_types = {
        'u0': 'float',
        'u1': 'float',
        'u2': 'float',
        'u3': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.u0 = kwargs.get('u0', float())
        self.u1 = kwargs.get('u1', float())
        self.u2 = kwargs.get('u2', float())
        self.u3 = kwargs.get('u3', float())

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
        if self.u0 != other.u0:
            return False
        if self.u1 != other.u1:
            return False
        if self.u2 != other.u2:
            return False
        if self.u3 != other.u3:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def u0(self):
        """Message field 'u0'."""
        return self._u0

    @u0.setter
    def u0(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'u0' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'u0' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._u0 = value

    @builtins.property
    def u1(self):
        """Message field 'u1'."""
        return self._u1

    @u1.setter
    def u1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'u1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'u1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._u1 = value

    @builtins.property
    def u2(self):
        """Message field 'u2'."""
        return self._u2

    @u2.setter
    def u2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'u2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'u2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._u2 = value

    @builtins.property
    def u3(self):
        """Message field 'u3'."""
        return self._u3

    @u3.setter
    def u3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'u3' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'u3' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._u3 = value
