// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hos_interfaces:srv/DeviceCommand.idl
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
#include "hos_interfaces/srv/detail/device_command__struct.h"
#include "hos_interfaces/srv/detail/device_command__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "hos_interfaces/msg/detail/typed_field__functions.h"
// end nested array functions include
bool hos_interfaces__msg__typed_field__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * hos_interfaces__msg__typed_field__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool hos_interfaces__srv__device_command__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[57];
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
    assert(strncmp("hos_interfaces.srv._device_command.DeviceCommand_Request", full_classname_dest, 56) == 0);
  }
  hos_interfaces__srv__DeviceCommand_Request * ros_message = _ros_message;
  {  // cmd_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "cmd_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cmd_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // function_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "function_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->function_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // num_args
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_args");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_args = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // args
    PyObject * field = PyObject_GetAttrString(_pymsg, "args");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'args'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!hos_interfaces__msg__TypedField__Sequence__init(&(ros_message->args), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create hos_interfaces__msg__TypedField__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    hos_interfaces__msg__TypedField * dest = ros_message->args.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!hos_interfaces__msg__typed_field__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hos_interfaces__srv__device_command__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DeviceCommand_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hos_interfaces.srv._device_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DeviceCommand_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hos_interfaces__srv__DeviceCommand_Request * ros_message = (hos_interfaces__srv__DeviceCommand_Request *)raw_ros_message;
  {  // cmd_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cmd_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cmd_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // function_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->function_name.data,
      strlen(ros_message->function_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "function_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // num_args
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->num_args);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_args", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // args
    PyObject * field = NULL;
    size_t size = ros_message->args.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    hos_interfaces__msg__TypedField * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->args.data[i]);
      PyObject * pyitem = hos_interfaces__msg__typed_field__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "args", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "hos_interfaces/srv/detail/device_command__struct.h"
// already included above
// #include "hos_interfaces/srv/detail/device_command__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hos_interfaces__srv__device_command__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
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
    assert(strncmp("hos_interfaces.srv._device_command.DeviceCommand_Response", full_classname_dest, 57) == 0);
  }
  hos_interfaces__srv__DeviceCommand_Response * ros_message = _ros_message;
  {  // is_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_valid = (Py_True == field);
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

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hos_interfaces__srv__device_command__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DeviceCommand_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hos_interfaces.srv._device_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DeviceCommand_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hos_interfaces__srv__DeviceCommand_Response * ros_message = (hos_interfaces__srv__DeviceCommand_Response *)raw_ros_message;
  {  // is_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_valid", field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
