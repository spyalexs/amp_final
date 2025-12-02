# generated from rosidl_generator_py/resource/_idl.py.em
# with input from amp_msgs:msg/BallTrajectory.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BallTrajectory(type):
    """Metaclass of message 'BallTrajectory'."""

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
                'amp_msgs.msg.BallTrajectory')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ball_trajectory
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ball_trajectory
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ball_trajectory
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ball_trajectory
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ball_trajectory

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BallTrajectory(metaclass=Metaclass_BallTrajectory):
    """Message class 'BallTrajectory'."""

    __slots__ = [
        '_current_pos_x',
        '_current_pos_y',
        '_current_pos_z',
        '_current_vel_x',
        '_current_vel_y',
        '_current_vel_z',
        '_current_damping_x',
        '_current_damping_y',
        '_current_damping_z',
        '_current_mass',
        '_landing_height',
    ]

    _fields_and_field_types = {
        'current_pos_x': 'float',
        'current_pos_y': 'float',
        'current_pos_z': 'float',
        'current_vel_x': 'float',
        'current_vel_y': 'float',
        'current_vel_z': 'float',
        'current_damping_x': 'float',
        'current_damping_y': 'float',
        'current_damping_z': 'float',
        'current_mass': 'float',
        'landing_height': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.current_pos_x = kwargs.get('current_pos_x', float())
        self.current_pos_y = kwargs.get('current_pos_y', float())
        self.current_pos_z = kwargs.get('current_pos_z', float())
        self.current_vel_x = kwargs.get('current_vel_x', float())
        self.current_vel_y = kwargs.get('current_vel_y', float())
        self.current_vel_z = kwargs.get('current_vel_z', float())
        self.current_damping_x = kwargs.get('current_damping_x', float())
        self.current_damping_y = kwargs.get('current_damping_y', float())
        self.current_damping_z = kwargs.get('current_damping_z', float())
        self.current_mass = kwargs.get('current_mass', float())
        self.landing_height = kwargs.get('landing_height', float())

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
        if self.current_pos_x != other.current_pos_x:
            return False
        if self.current_pos_y != other.current_pos_y:
            return False
        if self.current_pos_z != other.current_pos_z:
            return False
        if self.current_vel_x != other.current_vel_x:
            return False
        if self.current_vel_y != other.current_vel_y:
            return False
        if self.current_vel_z != other.current_vel_z:
            return False
        if self.current_damping_x != other.current_damping_x:
            return False
        if self.current_damping_y != other.current_damping_y:
            return False
        if self.current_damping_z != other.current_damping_z:
            return False
        if self.current_mass != other.current_mass:
            return False
        if self.landing_height != other.landing_height:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def current_pos_x(self):
        """Message field 'current_pos_x'."""
        return self._current_pos_x

    @current_pos_x.setter
    def current_pos_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_pos_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_pos_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_pos_x = value

    @builtins.property
    def current_pos_y(self):
        """Message field 'current_pos_y'."""
        return self._current_pos_y

    @current_pos_y.setter
    def current_pos_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_pos_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_pos_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_pos_y = value

    @builtins.property
    def current_pos_z(self):
        """Message field 'current_pos_z'."""
        return self._current_pos_z

    @current_pos_z.setter
    def current_pos_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_pos_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_pos_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_pos_z = value

    @builtins.property
    def current_vel_x(self):
        """Message field 'current_vel_x'."""
        return self._current_vel_x

    @current_vel_x.setter
    def current_vel_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_vel_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_vel_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_vel_x = value

    @builtins.property
    def current_vel_y(self):
        """Message field 'current_vel_y'."""
        return self._current_vel_y

    @current_vel_y.setter
    def current_vel_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_vel_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_vel_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_vel_y = value

    @builtins.property
    def current_vel_z(self):
        """Message field 'current_vel_z'."""
        return self._current_vel_z

    @current_vel_z.setter
    def current_vel_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_vel_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_vel_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_vel_z = value

    @builtins.property
    def current_damping_x(self):
        """Message field 'current_damping_x'."""
        return self._current_damping_x

    @current_damping_x.setter
    def current_damping_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_damping_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_damping_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_damping_x = value

    @builtins.property
    def current_damping_y(self):
        """Message field 'current_damping_y'."""
        return self._current_damping_y

    @current_damping_y.setter
    def current_damping_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_damping_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_damping_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_damping_y = value

    @builtins.property
    def current_damping_z(self):
        """Message field 'current_damping_z'."""
        return self._current_damping_z

    @current_damping_z.setter
    def current_damping_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_damping_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_damping_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_damping_z = value

    @builtins.property
    def current_mass(self):
        """Message field 'current_mass'."""
        return self._current_mass

    @current_mass.setter
    def current_mass(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_mass' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_mass' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_mass = value

    @builtins.property
    def landing_height(self):
        """Message field 'landing_height'."""
        return self._landing_height

    @landing_height.setter
    def landing_height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'landing_height' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'landing_height' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._landing_height = value
