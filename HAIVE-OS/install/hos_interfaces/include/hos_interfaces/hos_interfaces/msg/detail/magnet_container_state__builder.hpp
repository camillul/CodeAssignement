// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:msg/MagnetContainerState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__MAGNET_CONTAINER_STATE__BUILDER_HPP_
#define HOS_INTERFACES__MSG__DETAIL__MAGNET_CONTAINER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/msg/detail/magnet_container_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace msg
{

namespace builder
{

class Init_MagnetContainerState_device_id
{
public:
  explicit Init_MagnetContainerState_device_id(::hos_interfaces::msg::MagnetContainerState & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::msg::MagnetContainerState device_id(::hos_interfaces::msg::MagnetContainerState::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::msg::MagnetContainerState msg_;
};

class Init_MagnetContainerState_device_type
{
public:
  explicit Init_MagnetContainerState_device_type(::hos_interfaces::msg::MagnetContainerState & msg)
  : msg_(msg)
  {}
  Init_MagnetContainerState_device_id device_type(::hos_interfaces::msg::MagnetContainerState::_device_type_type arg)
  {
    msg_.device_type = std::move(arg);
    return Init_MagnetContainerState_device_id(msg_);
  }

private:
  ::hos_interfaces::msg::MagnetContainerState msg_;
};

class Init_MagnetContainerState_is_reconnected
{
public:
  explicit Init_MagnetContainerState_is_reconnected(::hos_interfaces::msg::MagnetContainerState & msg)
  : msg_(msg)
  {}
  Init_MagnetContainerState_device_type is_reconnected(::hos_interfaces::msg::MagnetContainerState::_is_reconnected_type arg)
  {
    msg_.is_reconnected = std::move(arg);
    return Init_MagnetContainerState_device_type(msg_);
  }

private:
  ::hos_interfaces::msg::MagnetContainerState msg_;
};

class Init_MagnetContainerState_device_uid
{
public:
  explicit Init_MagnetContainerState_device_uid(::hos_interfaces::msg::MagnetContainerState & msg)
  : msg_(msg)
  {}
  Init_MagnetContainerState_is_reconnected device_uid(::hos_interfaces::msg::MagnetContainerState::_device_uid_type arg)
  {
    msg_.device_uid = std::move(arg);
    return Init_MagnetContainerState_is_reconnected(msg_);
  }

private:
  ::hos_interfaces::msg::MagnetContainerState msg_;
};

class Init_MagnetContainerState_last_ping
{
public:
  explicit Init_MagnetContainerState_last_ping(::hos_interfaces::msg::MagnetContainerState & msg)
  : msg_(msg)
  {}
  Init_MagnetContainerState_device_uid last_ping(::hos_interfaces::msg::MagnetContainerState::_last_ping_type arg)
  {
    msg_.last_ping = std::move(arg);
    return Init_MagnetContainerState_device_uid(msg_);
  }

private:
  ::hos_interfaces::msg::MagnetContainerState msg_;
};

class Init_MagnetContainerState_is_connected
{
public:
  explicit Init_MagnetContainerState_is_connected(::hos_interfaces::msg::MagnetContainerState & msg)
  : msg_(msg)
  {}
  Init_MagnetContainerState_last_ping is_connected(::hos_interfaces::msg::MagnetContainerState::_is_connected_type arg)
  {
    msg_.is_connected = std::move(arg);
    return Init_MagnetContainerState_last_ping(msg_);
  }

private:
  ::hos_interfaces::msg::MagnetContainerState msg_;
};

class Init_MagnetContainerState_is_movable
{
public:
  explicit Init_MagnetContainerState_is_movable(::hos_interfaces::msg::MagnetContainerState & msg)
  : msg_(msg)
  {}
  Init_MagnetContainerState_is_connected is_movable(::hos_interfaces::msg::MagnetContainerState::_is_movable_type arg)
  {
    msg_.is_movable = std::move(arg);
    return Init_MagnetContainerState_is_connected(msg_);
  }

private:
  ::hos_interfaces::msg::MagnetContainerState msg_;
};

class Init_MagnetContainerState_temperature
{
public:
  explicit Init_MagnetContainerState_temperature(::hos_interfaces::msg::MagnetContainerState & msg)
  : msg_(msg)
  {}
  Init_MagnetContainerState_is_movable temperature(::hos_interfaces::msg::MagnetContainerState::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_MagnetContainerState_is_movable(msg_);
  }

private:
  ::hos_interfaces::msg::MagnetContainerState msg_;
};

class Init_MagnetContainerState_external_resources
{
public:
  explicit Init_MagnetContainerState_external_resources(::hos_interfaces::msg::MagnetContainerState & msg)
  : msg_(msg)
  {}
  Init_MagnetContainerState_temperature external_resources(::hos_interfaces::msg::MagnetContainerState::_external_resources_type arg)
  {
    msg_.external_resources = std::move(arg);
    return Init_MagnetContainerState_temperature(msg_);
  }

private:
  ::hos_interfaces::msg::MagnetContainerState msg_;
};

class Init_MagnetContainerState_slot_position
{
public:
  explicit Init_MagnetContainerState_slot_position(::hos_interfaces::msg::MagnetContainerState & msg)
  : msg_(msg)
  {}
  Init_MagnetContainerState_external_resources slot_position(::hos_interfaces::msg::MagnetContainerState::_slot_position_type arg)
  {
    msg_.slot_position = std::move(arg);
    return Init_MagnetContainerState_external_resources(msg_);
  }

private:
  ::hos_interfaces::msg::MagnetContainerState msg_;
};

class Init_MagnetContainerState_is_flipped
{
public:
  Init_MagnetContainerState_is_flipped()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MagnetContainerState_slot_position is_flipped(::hos_interfaces::msg::MagnetContainerState::_is_flipped_type arg)
  {
    msg_.is_flipped = std::move(arg);
    return Init_MagnetContainerState_slot_position(msg_);
  }

private:
  ::hos_interfaces::msg::MagnetContainerState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::msg::MagnetContainerState>()
{
  return hos_interfaces::msg::builder::Init_MagnetContainerState_is_flipped();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__MAGNET_CONTAINER_STATE__BUILDER_HPP_
