// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:msg/P200ContainerState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__P200_CONTAINER_STATE__BUILDER_HPP_
#define HOS_INTERFACES__MSG__DETAIL__P200_CONTAINER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/msg/detail/p200_container_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace msg
{

namespace builder
{

class Init_P200ContainerState_device_id
{
public:
  explicit Init_P200ContainerState_device_id(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::msg::P200ContainerState device_id(::hos_interfaces::msg::P200ContainerState::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_device_type
{
public:
  explicit Init_P200ContainerState_device_type(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_device_id device_type(::hos_interfaces::msg::P200ContainerState::_device_type_type arg)
  {
    msg_.device_type = std::move(arg);
    return Init_P200ContainerState_device_id(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_is_reconnected
{
public:
  explicit Init_P200ContainerState_is_reconnected(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_device_type is_reconnected(::hos_interfaces::msg::P200ContainerState::_is_reconnected_type arg)
  {
    msg_.is_reconnected = std::move(arg);
    return Init_P200ContainerState_device_type(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_device_uid
{
public:
  explicit Init_P200ContainerState_device_uid(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_is_reconnected device_uid(::hos_interfaces::msg::P200ContainerState::_device_uid_type arg)
  {
    msg_.device_uid = std::move(arg);
    return Init_P200ContainerState_is_reconnected(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_last_ping
{
public:
  explicit Init_P200ContainerState_last_ping(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_device_uid last_ping(::hos_interfaces::msg::P200ContainerState::_last_ping_type arg)
  {
    msg_.last_ping = std::move(arg);
    return Init_P200ContainerState_device_uid(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_is_connected
{
public:
  explicit Init_P200ContainerState_is_connected(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_last_ping is_connected(::hos_interfaces::msg::P200ContainerState::_is_connected_type arg)
  {
    msg_.is_connected = std::move(arg);
    return Init_P200ContainerState_last_ping(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_is_movable
{
public:
  explicit Init_P200ContainerState_is_movable(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_is_connected is_movable(::hos_interfaces::msg::P200ContainerState::_is_movable_type arg)
  {
    msg_.is_movable = std::move(arg);
    return Init_P200ContainerState_is_connected(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_temperature
{
public:
  explicit Init_P200ContainerState_temperature(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_is_movable temperature(::hos_interfaces::msg::P200ContainerState::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_P200ContainerState_is_movable(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_external_resources
{
public:
  explicit Init_P200ContainerState_external_resources(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_temperature external_resources(::hos_interfaces::msg::P200ContainerState::_external_resources_type arg)
  {
    msg_.external_resources = std::move(arg);
    return Init_P200ContainerState_temperature(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_slot_position
{
public:
  explicit Init_P200ContainerState_slot_position(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_external_resources slot_position(::hos_interfaces::msg::P200ContainerState::_slot_position_type arg)
  {
    msg_.slot_position = std::move(arg);
    return Init_P200ContainerState_external_resources(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_is_flipped
{
public:
  explicit Init_P200ContainerState_is_flipped(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_slot_position is_flipped(::hos_interfaces::msg::P200ContainerState::_is_flipped_type arg)
  {
    msg_.is_flipped = std::move(arg);
    return Init_P200ContainerState_slot_position(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_tips_availaible
{
public:
  explicit Init_P200ContainerState_tips_availaible(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_is_flipped tips_availaible(::hos_interfaces::msg::P200ContainerState::_tips_availaible_type arg)
  {
    msg_.tips_availaible = std::move(arg);
    return Init_P200ContainerState_is_flipped(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_y_size
{
public:
  explicit Init_P200ContainerState_y_size(::hos_interfaces::msg::P200ContainerState & msg)
  : msg_(msg)
  {}
  Init_P200ContainerState_tips_availaible y_size(::hos_interfaces::msg::P200ContainerState::_y_size_type arg)
  {
    msg_.y_size = std::move(arg);
    return Init_P200ContainerState_tips_availaible(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

class Init_P200ContainerState_x_size
{
public:
  Init_P200ContainerState_x_size()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_P200ContainerState_y_size x_size(::hos_interfaces::msg::P200ContainerState::_x_size_type arg)
  {
    msg_.x_size = std::move(arg);
    return Init_P200ContainerState_y_size(msg_);
  }

private:
  ::hos_interfaces::msg::P200ContainerState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::msg::P200ContainerState>()
{
  return hos_interfaces::msg::builder::Init_P200ContainerState_x_size();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__P200_CONTAINER_STATE__BUILDER_HPP_
