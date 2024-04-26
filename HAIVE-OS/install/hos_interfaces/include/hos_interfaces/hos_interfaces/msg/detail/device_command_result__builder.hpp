// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:msg/DeviceCommandResult.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__DEVICE_COMMAND_RESULT__BUILDER_HPP_
#define HOS_INTERFACES__MSG__DETAIL__DEVICE_COMMAND_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/msg/detail/device_command_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace msg
{

namespace builder
{

class Init_DeviceCommandResult_result_str
{
public:
  explicit Init_DeviceCommandResult_result_str(::hos_interfaces::msg::DeviceCommandResult & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::msg::DeviceCommandResult result_str(::hos_interfaces::msg::DeviceCommandResult::_result_str_type arg)
  {
    msg_.result_str = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceCommandResult msg_;
};

class Init_DeviceCommandResult_error
{
public:
  explicit Init_DeviceCommandResult_error(::hos_interfaces::msg::DeviceCommandResult & msg)
  : msg_(msg)
  {}
  Init_DeviceCommandResult_result_str error(::hos_interfaces::msg::DeviceCommandResult::_error_type arg)
  {
    msg_.error = std::move(arg);
    return Init_DeviceCommandResult_result_str(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceCommandResult msg_;
};

class Init_DeviceCommandResult_success
{
public:
  explicit Init_DeviceCommandResult_success(::hos_interfaces::msg::DeviceCommandResult & msg)
  : msg_(msg)
  {}
  Init_DeviceCommandResult_error success(::hos_interfaces::msg::DeviceCommandResult::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_DeviceCommandResult_error(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceCommandResult msg_;
};

class Init_DeviceCommandResult_cmd_id
{
public:
  explicit Init_DeviceCommandResult_cmd_id(::hos_interfaces::msg::DeviceCommandResult & msg)
  : msg_(msg)
  {}
  Init_DeviceCommandResult_success cmd_id(::hos_interfaces::msg::DeviceCommandResult::_cmd_id_type arg)
  {
    msg_.cmd_id = std::move(arg);
    return Init_DeviceCommandResult_success(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceCommandResult msg_;
};

class Init_DeviceCommandResult_uid
{
public:
  Init_DeviceCommandResult_uid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeviceCommandResult_cmd_id uid(::hos_interfaces::msg::DeviceCommandResult::_uid_type arg)
  {
    msg_.uid = std::move(arg);
    return Init_DeviceCommandResult_cmd_id(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceCommandResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::msg::DeviceCommandResult>()
{
  return hos_interfaces::msg::builder::Init_DeviceCommandResult_uid();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__DEVICE_COMMAND_RESULT__BUILDER_HPP_
