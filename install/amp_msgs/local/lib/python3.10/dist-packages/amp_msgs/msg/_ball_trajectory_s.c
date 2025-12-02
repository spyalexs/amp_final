// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from amp_msgs:msg/BallTrajectory.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "amp_msgs/msg/detail/ball_trajectory__struct.h"
#include "amp_msgs/msg/detail/ball_trajectory__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool amp_msgs__msg__ball_trajectory__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("amp_msgs.msg._ball_trajectory.BallTrajectory", full_classname_dest, 44) == 0);
  }
  amp_msgs__msg__BallTrajectory * ros_message = _ros_message;
  {  // current_pos_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_pos_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_pos_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_pos_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_pos_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_pos_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_pos_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_pos_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_pos_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_vel_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_vel_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_vel_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_vel_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_vel_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_vel_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_vel_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_vel_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_vel_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_damping_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_damping_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_damping_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_damping_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_damping_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_damping_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_damping_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_damping_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_damping_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_mass
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_mass");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_mass = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // landing_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "landing_height");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->landing_height = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * amp_msgs__msg__ball_trajectory__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BallTrajectory */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("amp_msgs.msg._ball_trajectory");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BallTrajectory");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  amp_msgs__msg__BallTrajectory * ros_message = (amp_msgs__msg__BallTrajectory *)raw_ros_message;
  {  // current_pos_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_pos_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_pos_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_pos_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_pos_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_pos_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_pos_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_pos_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_pos_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_vel_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_vel_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_vel_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_vel_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_vel_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_vel_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_vel_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_vel_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_vel_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_damping_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_damping_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_damping_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_damping_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_damping_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_damping_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_damping_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_damping_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_damping_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_mass
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_mass);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_mass", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // landing_height
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->landing_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "landing_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
