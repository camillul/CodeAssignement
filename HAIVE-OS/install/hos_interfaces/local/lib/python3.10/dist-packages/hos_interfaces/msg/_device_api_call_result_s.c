// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hos_interfaces:msg/DeviceAPICallResult.idl
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
#include "hos_interfaces/msg/detail/device_api_call_result__struct.h"
#include "hos_interfaces/msg/detail/device_api_call_result__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hos_interfaces__msg__device_api_call_result__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[63];
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
    assert(strncmp("hos_interfaces.msg._device_api_call_result.DeviceAPICallResult", full_classname_dest, 62) == 0);
  }
  hos_interfaces__msg__DeviceAPICallResult * ros_message = _ros_message;
  {  // task_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->task_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // error
    PyObject * field = PyObject_GetAttrString(_pymsg, "error");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->error, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // result_jsons
    PyObject * field = PyObject_GetAttrString(_pymsg, "result_jsons");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->result_jsons, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // request_time_s
    PyObject * field = PyObject_GetAttrString(_pymsg, "request_time_s");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->request_time_s = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // response_time_s
    PyObject * field = PyObject_GetAttrString(_pymsg, "response_time_s");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->response_time_s = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hos_interfaces__msg__device_api_call_result__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DeviceAPICallResult */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hos_interfaces.msg._device_api_call_result");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DeviceAPICallResult");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hos_interfaces__msg__DeviceAPICallResult * ros_message = (hos_interfaces__msg__DeviceAPICallResult *)raw_ros_message;
  {  // task_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->task_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->error.data,
      strlen(ros_message->error.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // result_jsons
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->result_jsons.data,
      strlen(ros_message->result_jsons.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "result_jsons", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // request_time_s
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->request_time_s);
    {
      int rc = PyObject_SetAttrString(_pymessage, "request_time_s", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // response_time_s
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->response_time_s);
    {
      int rc = PyObject_SetAttrString(_pymessage, "response_time_s", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}