// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:srv/DeviceCommand.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__DEVICE_COMMAND__BUILDER_HPP_
#define HOS_INTERFACES__SRV__DETAIL__DEVICE_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/srv/detail/device_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_DeviceCommand_Request_args
{
public:
  explicit Init_DeviceCommand_Request_args(::hos_interfaces::srv::DeviceCommand_Request & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::DeviceCommand_Request args(::hos_interfaces::srv::DeviceCommand_Request::_args_type arg)
  {
    msg_.args = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceCommand_Request msg_;
};

class Init_DeviceCommand_Request_num_args
{
public:
  explicit Init_DeviceCommand_Request_num_args(::hos_interfaces::srv::DeviceCommand_Request & msg)
  : msg_(msg)
  {}
  Init_DeviceCommand_Request_args num_args(::hos_interfaces::srv::DeviceCommand_Request::_num_args_type arg)
  {
    msg_.num_args = std::move(arg);
    return Init_DeviceCommand_Request_args(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceCommand_Request msg_;
};

class Init_DeviceCommand_Request_function_name
{
public:
  explicit Init_DeviceCommand_Request_function_name(::hos_interfaces::srv::DeviceCommand_Request & msg)
  : msg_(msg)
  {}
  Init_DeviceCommand_Request_num_args function_name(::hos_interfaces::srv::DeviceCommand_Request::_function_name_type arg)
  {
    msg_.function_name = std::move(arg);
    return Init_DeviceCommand_Request_num_args(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceCommand_Request msg_;
};

class Init_DeviceCommand_Request_cmd_id
{
public:
  Init_DeviceCommand_Request_cmd_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeviceCommand_Request_function_name cmd_id(::hos_interfaces::srv::DeviceCommand_Request::_cmd_id_type arg)
  {
    msg_.cmd_id = std::move(arg);
    return Init_DeviceCommand_Request_function_name(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::DeviceCommand_Request>()
{
  return hos_interfaces::srv::builder::Init_DeviceCommand_Request_cmd_id();
}

}  // namespace hos_interfaces


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_DeviceCommand_Response_error
{
public:
  explicit Init_DeviceCommand_Response_error(::hos_interfaces::srv::DeviceCommand_Response & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::DeviceCommand_Response error(::hos_interfaces::srv::DeviceCommand_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceCommand_Response msg_;
};

class Init_DeviceCommand_Response_is_valid
{
public:
  Init_DeviceCommand_Response_is_valid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeviceCommand_Response_error is_valid(::hos_interfaces::srv::DeviceCommand_Response::_is_valid_type arg)
  {
    msg_.is_valid = std::move(arg);
    return Init_DeviceCommand_Response_error(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::DeviceCommand_Response>()
{
  return hos_interfaces::srv::builder::Init_DeviceCommand_Response_is_valid();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__DEVICE_COMMAND__BUILDER_HPP_
