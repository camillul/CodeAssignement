// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:msg/ConnectionInfo.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__CONNECTION_INFO__BUILDER_HPP_
#define HOS_INTERFACES__MSG__DETAIL__CONNECTION_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/msg/detail/connection_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace msg
{

namespace builder
{

class Init_ConnectionInfo_event_time_s
{
public:
  explicit Init_ConnectionInfo_event_time_s(::hos_interfaces::msg::ConnectionInfo & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::msg::ConnectionInfo event_time_s(::hos_interfaces::msg::ConnectionInfo::_event_time_s_type arg)
  {
    msg_.event_time_s = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::msg::ConnectionInfo msg_;
};

class Init_ConnectionInfo_device_type
{
public:
  explicit Init_ConnectionInfo_device_type(::hos_interfaces::msg::ConnectionInfo & msg)
  : msg_(msg)
  {}
  Init_ConnectionInfo_event_time_s device_type(::hos_interfaces::msg::ConnectionInfo::_device_type_type arg)
  {
    msg_.device_type = std::move(arg);
    return Init_ConnectionInfo_event_time_s(msg_);
  }

private:
  ::hos_interfaces::msg::ConnectionInfo msg_;
};

class Init_ConnectionInfo_device_uid
{
public:
  explicit Init_ConnectionInfo_device_uid(::hos_interfaces::msg::ConnectionInfo & msg)
  : msg_(msg)
  {}
  Init_ConnectionInfo_device_type device_uid(::hos_interfaces::msg::ConnectionInfo::_device_uid_type arg)
  {
    msg_.device_uid = std::move(arg);
    return Init_ConnectionInfo_device_type(msg_);
  }

private:
  ::hos_interfaces::msg::ConnectionInfo msg_;
};

class Init_ConnectionInfo_device_id
{
public:
  Init_ConnectionInfo_device_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConnectionInfo_device_uid device_id(::hos_interfaces::msg::ConnectionInfo::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return Init_ConnectionInfo_device_uid(msg_);
  }

private:
  ::hos_interfaces::msg::ConnectionInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::msg::ConnectionInfo>()
{
  return hos_interfaces::msg::builder::Init_ConnectionInfo_device_id();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__CONNECTION_INFO__BUILDER_HPP_
