// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hos_interfaces:msg/TubeState.idl
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
#include "hos_interfaces/msg/detail/tube_state__struct.h"
#include "hos_interfaces/msg/detail/tube_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hos_interfaces__msg__tube_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("hos_interfaces.msg._tube_state.TubeState", full_classname_dest, 40) == 0);
  }
  hos_interfaces__msg__TubeState * ros_message = _ros_message;
  {  // liquid_level
    PyObject * field = PyObject_GetAttrString(_pymsg, "liquid_level");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->liquid_level = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tube_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "tube_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->tube_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // tube_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "tube_type");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->tube_type, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // volume
    PyObject * field = PyObject_GetAttrString(_pymsg, "volume");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->volume = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // temperature
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->temperature = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hos_interfaces__msg__tube_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TubeState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hos_interfaces.msg._tube_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TubeState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hos_interfaces__msg__TubeState * ros_message = (hos_interfaces__msg__TubeState *)raw_ros_message;
  {  // liquid_level
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->liquid_level);
    {
      int rc = PyObject_SetAttrString(_pymessage, "liquid_level", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tube_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->tube_id.data,
      strlen(ros_message->tube_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "tube_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tube_type
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->tube_type.data,
      strlen(ros_message->tube_type.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "tube_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // volume
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->volume);
    {
      int rc = PyObject_SetAttrString(_pymessage, "volume", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temperature
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->temperature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
