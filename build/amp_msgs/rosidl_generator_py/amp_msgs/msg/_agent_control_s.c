// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from amp_msgs:msg/AgentControl.idl
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
#include "amp_msgs/msg/detail/agent_control__struct.h"
#include "amp_msgs/msg/detail/agent_control__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool amp_msgs__msg__agent_control__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("amp_msgs.msg._agent_control.AgentControl", full_classname_dest, 40) == 0);
  }
  amp_msgs__msg__AgentControl * ros_message = _ros_message;
  {  // u0
    PyObject * field = PyObject_GetAttrString(_pymsg, "u0");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->u0 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // u1
    PyObject * field = PyObject_GetAttrString(_pymsg, "u1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->u1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // u2
    PyObject * field = PyObject_GetAttrString(_pymsg, "u2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->u2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // u3
    PyObject * field = PyObject_GetAttrString(_pymsg, "u3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->u3 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * amp_msgs__msg__agent_control__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AgentControl */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("amp_msgs.msg._agent_control");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AgentControl");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  amp_msgs__msg__AgentControl * ros_message = (amp_msgs__msg__AgentControl *)raw_ros_message;
  {  // u0
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->u0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "u0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // u1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->u1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "u1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // u2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->u2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "u2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // u3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->u3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "u3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
