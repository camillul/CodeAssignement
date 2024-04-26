// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:srv/RobotStateInit.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__ROBOT_STATE_INIT__BUILDER_HPP_
#define HOS_INTERFACES__SRV__DETAIL__ROBOT_STATE_INIT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/srv/detail/robot_state_init__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_RobotStateInit_Request_file_name
{
public:
  Init_RobotStateInit_Request_file_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hos_interfaces::srv::RobotStateInit_Request file_name(::hos_interfaces::srv::RobotStateInit_Request::_file_name_type arg)
  {
    msg_.file_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::RobotStateInit_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::RobotStateInit_Request>()
{
  return hos_interfaces::srv::builder::Init_RobotStateInit_Request_file_name();
}

}  // namespace hos_interfaces


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_RobotStateInit_Response_error
{
public:
  explicit Init_RobotStateInit_Response_error(::hos_interfaces::srv::RobotStateInit_Response & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::RobotStateInit_Response error(::hos_interfaces::srv::RobotStateInit_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::RobotStateInit_Response msg_;
};

class Init_RobotStateInit_Response_is_valid
{
public:
  Init_RobotStateInit_Response_is_valid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStateInit_Response_error is_valid(::hos_interfaces::srv::RobotStateInit_Response::_is_valid_type arg)
  {
    msg_.is_valid = std::move(arg);
    return Init_RobotStateInit_Response_error(msg_);
  }

private:
  ::hos_interfaces::srv::RobotStateInit_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::RobotStateInit_Response>()
{
  return hos_interfaces::srv::builder::Init_RobotStateInit_Response_is_valid();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__ROBOT_STATE_INIT__BUILDER_HPP_
