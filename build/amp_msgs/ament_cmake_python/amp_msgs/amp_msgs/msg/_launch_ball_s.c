// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from amp_msgs:msg/LaunchBall.idl
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
#include "amp_msgs/msg/detail/launch_ball__struct.h"
#include "amp_msgs/msg/detail/launch_ball__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool amp_msgs__msg__launch_ball__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
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
    assert(strncmp("amp_msgs.msg._launch_ball.LaunchBall", full_classname_dest, 36) == 0);
  }
  amp_msgs__msg__LaunchBall * ros_message = _ros_message;
  {  // ball_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "ball_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ball_velocity = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ball_launch_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "ball_launch_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ball_launch_angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ball_launch_heading
    PyObject * field = PyObject_GetAttrString(_pymsg, "ball_launch_heading");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ball_launch_heading = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ball_pos_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "ball_pos_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ball_pos_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ball_pos_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "ball_pos_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ball_pos_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ball_pos_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "ball_pos_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ball_pos_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * amp_msgs__msg__launch_ball__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LaunchBall */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("amp_msgs.msg._launch_ball");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LaunchBall");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  amp_msgs__msg__LaunchBall * ros_message = (amp_msgs__msg__LaunchBall *)raw_ros_message;
  {  // ball_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ball_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ball_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ball_launch_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ball_launch_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ball_launch_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ball_launch_heading
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ball_launch_heading);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ball_launch_heading", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ball_pos_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ball_pos_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ball_pos_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ball_pos_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ball_pos_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ball_pos_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ball_pos_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ball_pos_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ball_pos_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
