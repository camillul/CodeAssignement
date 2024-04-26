// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:srv/BehaviorRequestMoveContainer.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__BUILDER_HPP_
#define HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/srv/detail/behavior_request_move_container__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_BehaviorRequestMoveContainer_Request_slot
{
public:
  explicit Init_BehaviorRequestMoveContainer_Request_slot(::hos_interfaces::srv::BehaviorRequestMoveContainer_Request & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::BehaviorRequestMoveContainer_Request slot(::hos_interfaces::srv::BehaviorRequestMoveContainer_Request::_slot_type arg)
  {
    msg_.slot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::BehaviorRequestMoveContainer_Request msg_;
};

class Init_BehaviorRequestMoveContainer_Request_haive_id
{
public:
  explicit Init_BehaviorRequestMoveContainer_Request_haive_id(::hos_interfaces::srv::BehaviorRequestMoveContainer_Request & msg)
  : msg_(msg)
  {}
  Init_BehaviorRequestMoveContainer_Request_slot haive_id(::hos_interfaces::srv::BehaviorRequestMoveContainer_Request::_haive_id_type arg)
  {
    msg_.haive_id = std::move(arg);
    return Init_BehaviorRequestMoveContainer_Request_slot(msg_);
  }

private:
  ::hos_interfaces::srv::BehaviorRequestMoveContainer_Request msg_;
};

class Init_BehaviorRequestMoveContainer_Request_container_id
{
public:
  Init_BehaviorRequestMoveContainer_Request_container_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BehaviorRequestMoveContainer_Request_haive_id container_id(::hos_interfaces::srv::BehaviorRequestMoveContainer_Request::_container_id_type arg)
  {
    msg_.container_id = std::move(arg);
    return Init_BehaviorRequestMoveContainer_Request_haive_id(msg_);
  }

private:
  ::hos_interfaces::srv::BehaviorRequestMoveContainer_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::BehaviorRequestMoveContainer_Request>()
{
  return hos_interfaces::srv::builder::Init_BehaviorRequestMoveContainer_Request_container_id();
}

}  // namespace hos_interfaces


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_BehaviorRequestMoveContainer_Response_error
{
public:
  explicit Init_BehaviorRequestMoveContainer_Response_error(::hos_interfaces::srv::BehaviorRequestMoveContainer_Response & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::BehaviorRequestMoveContainer_Response error(::hos_interfaces::srv::BehaviorRequestMoveContainer_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::BehaviorRequestMoveContainer_Response msg_;
};

class Init_BehaviorRequestMoveContainer_Response_success
{
public:
  Init_BehaviorRequestMoveContainer_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BehaviorRequestMoveContainer_Response_error success(::hos_interfaces::srv::BehaviorRequestMoveContainer_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_BehaviorRequestMoveContainer_Response_error(msg_);
  }

private:
  ::hos_interfaces::srv::BehaviorRequestMoveContainer_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::BehaviorRequestMoveContainer_Response>()
{
  return hos_interfaces::srv::builder::Init_BehaviorRequestMoveContainer_Response_success();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__BUILDER_HPP_
