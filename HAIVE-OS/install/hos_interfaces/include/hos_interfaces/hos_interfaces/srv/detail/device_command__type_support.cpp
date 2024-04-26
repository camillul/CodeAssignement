// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from hos_interfaces:srv/DeviceCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "hos_interfaces/srv/detail/device_command__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace hos_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void DeviceCommand_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) hos_interfaces::srv::DeviceCommand_Request(_init);
}

void DeviceCommand_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<hos_interfaces::srv::DeviceCommand_Request *>(message_memory);
  typed_message->~DeviceCommand_Request();
}

size_t size_function__DeviceCommand_Request__args(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<hos_interfaces::msg::TypedField> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DeviceCommand_Request__args(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<hos_interfaces::msg::TypedField> *>(untyped_member);
  return &member[index];
}

void * get_function__DeviceCommand_Request__args(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<hos_interfaces::msg::TypedField> *>(untyped_member);
  return &member[index];
}

void fetch_function__DeviceCommand_Request__args(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const hos_interfaces::msg::TypedField *>(
    get_const_function__DeviceCommand_Request__args(untyped_member, index));
  auto & value = *reinterpret_cast<hos_interfaces::msg::TypedField *>(untyped_value);
  value = item;
}

void assign_function__DeviceCommand_Request__args(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<hos_interfaces::msg::TypedField *>(
    get_function__DeviceCommand_Request__args(untyped_member, index));
  const auto & value = *reinterpret_cast<const hos_interfaces::msg::TypedField *>(untyped_value);
  item = value;
}

void resize_function__DeviceCommand_Request__args(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<hos_interfaces::msg::TypedField> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DeviceCommand_Request_message_member_array[4] = {
  {
    "cmd_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces::srv::DeviceCommand_Request, cmd_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "function_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces::srv::DeviceCommand_Request, function_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_args",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces::srv::DeviceCommand_Request, num_args),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "args",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<hos_interfaces::msg::TypedField>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces::srv::DeviceCommand_Request, args),  // bytes offset in struct
    nullptr,  // default value
    size_function__DeviceCommand_Request__args,  // size() function pointer
    get_const_function__DeviceCommand_Request__args,  // get_const(index) function pointer
    get_function__DeviceCommand_Request__args,  // get(index) function pointer
    fetch_function__DeviceCommand_Request__args,  // fetch(index, &value) function pointer
    assign_function__DeviceCommand_Request__args,  // assign(index, value) function pointer
    resize_function__DeviceCommand_Request__args  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DeviceCommand_Request_message_members = {
  "hos_interfaces::srv",  // message namespace
  "DeviceCommand_Request",  // message name
  4,  // number of fields
  sizeof(hos_interfaces::srv::DeviceCommand_Request),
  DeviceCommand_Request_message_member_array,  // message members
  DeviceCommand_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  DeviceCommand_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DeviceCommand_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DeviceCommand_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace hos_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<hos_interfaces::srv::DeviceCommand_Request>()
{
  return &::hos_interfaces::srv::rosidl_typesupport_introspection_cpp::DeviceCommand_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, hos_interfaces, srv, DeviceCommand_Request)() {
  return &::hos_interfaces::srv::rosidl_typesupport_introspection_cpp::DeviceCommand_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "hos_interfaces/srv/detail/device_command__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace hos_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void DeviceCommand_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) hos_interfaces::srv::DeviceCommand_Response(_init);
}

void DeviceCommand_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<hos_interfaces::srv::DeviceCommand_Response *>(message_memory);
  typed_message->~DeviceCommand_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DeviceCommand_Response_message_member_array[2] = {
  {
    "is_valid",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces::srv::DeviceCommand_Response, is_valid),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "error",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces::srv::DeviceCommand_Response, error),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DeviceCommand_Response_message_members = {
  "hos_interfaces::srv",  // message namespace
  "DeviceCommand_Response",  // message name
  2,  // number of fields
  sizeof(hos_interfaces::srv::DeviceCommand_Response),
  DeviceCommand_Response_message_member_array,  // message members
  DeviceCommand_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  DeviceCommand_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DeviceCommand_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DeviceCommand_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace hos_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<hos_interfaces::srv::DeviceCommand_Response>()
{
  return &::hos_interfaces::srv::rosidl_typesupport_introspection_cpp::DeviceCommand_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, hos_interfaces, srv, DeviceCommand_Response)() {
  return &::hos_interfaces::srv::rosidl_typesupport_introspection_cpp::DeviceCommand_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "hos_interfaces/srv/detail/device_command__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace hos_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers DeviceCommand_service_members = {
  "hos_interfaces::srv",  // service namespace
  "DeviceCommand",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<hos_interfaces::srv::DeviceCommand>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t DeviceCommand_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DeviceCommand_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace hos_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<hos_interfaces::srv::DeviceCommand>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::hos_interfaces::srv::rosidl_typesupport_introspection_cpp::DeviceCommand_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::hos_interfaces::srv::DeviceCommand_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::hos_interfaces::srv::DeviceCommand_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, hos_interfaces, srv, DeviceCommand)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<hos_interfaces::srv::DeviceCommand>();
}

#ifdef __cplusplus
}
#endif
