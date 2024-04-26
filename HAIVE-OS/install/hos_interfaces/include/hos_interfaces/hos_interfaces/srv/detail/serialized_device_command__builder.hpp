// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:srv/SerializedDeviceCommand.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__SERIALIZED_DEVICE_COMMAND__BUILDER_HPP_
#define HOS_INTERFACES__SRV__DETAIL__SERIALIZED_DEVICE_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/srv/detail/serialized_device_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_SerializedDeviceCommand_Request_function_name
{
public:
  explicit Init_SerializedDeviceCommand_Request_function_name(::hos_interfaces::srv::SerializedDeviceCommand_Request & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::SerializedDeviceCommand_Request function_name(::hos_interfaces::srv::SerializedDeviceCommand_Request::_function_name_type arg)
  {
    msg_.function_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::SerializedDeviceCommand_Request msg_;
};

class Init_SerializedDeviceCommand_Request_serialized_command
{
public:
  explicit Init_SerializedDeviceCommand_Request_serialized_command(::hos_interfaces::srv::SerializedDeviceCommand_Request & msg)
  : msg_(msg)
  {}
  Init_SerializedDeviceCommand_Request_function_name serialized_command(::hos_interfaces::srv::SerializedDeviceCommand_Request::_serialized_command_type arg)
  {
    msg_.serialized_command = std::move(arg);
    return Init_SerializedDeviceCommand_Request_function_name(msg_);
  }

private:
  ::hos_interfaces::srv::SerializedDeviceCommand_Request msg_;
};

class Init_SerializedDeviceCommand_Request_cmd_id
{
public:
  Init_SerializedDeviceCommand_Request_cmd_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SerializedDeviceCommand_Request_serialized_command cmd_id(::hos_interfaces::srv::SerializedDeviceCommand_Request::_cmd_id_type arg)
  {
    msg_.cmd_id = std::move(arg);
    return Init_SerializedDeviceCommand_Request_serialized_command(msg_);
  }

private:
  ::hos_interfaces::srv::SerializedDeviceCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::SerializedDeviceCommand_Request>()
{
  return hos_interfaces::srv::builder::Init_SerializedDeviceCommand_Request_cmd_id();
}

}  // namespace hos_interfaces


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_SerializedDeviceCommand_Response_error
{
public:
  explicit Init_SerializedDeviceCommand_Response_error(::hos_interfaces::srv::SerializedDeviceCommand_Response & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::SerializedDeviceCommand_Response error(::hos_interfaces::srv::SerializedDeviceCommand_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::SerializedDeviceCommand_Response msg_;
};

class Init_SerializedDeviceCommand_Response_is_valid
{
public:
  Init_SerializedDeviceCommand_Response_is_valid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SerializedDeviceCommand_Response_error is_valid(::hos_interfaces::srv::SerializedDeviceCommand_Response::_is_valid_type arg)
  {
    msg_.is_valid = std::move(arg);
    return Init_SerializedDeviceCommand_Response_error(msg_);
  }

private:
  ::hos_interfaces::srv::SerializedDeviceCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::SerializedDeviceCommand_Response>()
{
  return hos_interfaces::srv::builder::Init_SerializedDeviceCommand_Response_is_valid();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__SERIALIZED_DEVICE_COMMAND__BUILDER_HPP_
