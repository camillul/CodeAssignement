// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hos_interfaces:msg/DisposalContainerState.idl
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
#include "hos_interfaces/msg/detail/disposal_container_state__struct.h"
#include "hos_interfaces/msg/detail/disposal_container_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hos_interfaces__msg__disposal_container_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[68];
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
    assert(strncmp("hos_interfaces.msg._disposal_container_state.DisposalContainerState", full_classname_dest, 67) == 0);
  }
  hos_interfaces__msg__DisposalContainerState * ros_message = _ros_message;
  {  // is_flipped
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_flipped");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_flipped = (Py_True == field);
    Py_DECREF(field);
  }
  {  // slot_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "slot_position");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->slot_position = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // external_resources
    PyObject * field = PyObject_GetAttrString(_pymsg, "external_resources");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->external_resources, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
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
  {  // is_movable
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_movable");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_movable = (Py_True == field);
    Py_DECREF(field);
  }
  {  // is_connected
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_connected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_connected = (Py_True == field);
    Py_DECREF(field);
  }
  {  // last_ping
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_ping");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->last_ping = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // device_uid
    PyObject * field = PyObject_GetAttrString(_pymsg, "device_uid");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->device_uid, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // is_reconnected
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_reconnected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_reconnected = (Py_True == field);
    Py_DECREF(field);
  }
  {  // device_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "device_type");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->device_type, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // device_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "device_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->device_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hos_interfaces__msg__disposal_container_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DisposalContainerState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hos_interfaces.msg._disposal_container_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DisposalContainerState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hos_interfaces__msg__DisposalContainerState * ros_message = (hos_interfaces__msg__DisposalContainerState *)raw_ros_message;
  {  // is_flipped
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_flipped ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_flipped", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // slot_position
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->slot_position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "slot_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // external_resources
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->external_resources.data,
      strlen(ros_message->external_resources.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "external_resources", field);
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
  {  // is_movable
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_movable ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_movable", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_connected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_connected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_connected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // last_ping
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->last_ping);
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_ping", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // device_uid
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->device_uid.data,
      strlen(ros_message->device_uid.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "device_uid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_reconnected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_reconnected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_reconnected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // device_type
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->device_type.data,
      strlen(ros_message->device_type.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "device_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // device_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->device_id.data,
      strlen(ros_message->device_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "device_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
