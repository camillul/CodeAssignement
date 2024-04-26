// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:msg/DeviceAPICallResult.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__BUILDER_HPP_
#define HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/msg/detail/device_api_call_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace msg
{

namespace builder
{

class Init_DeviceAPICallResult_response_time_s
{
public:
  explicit Init_DeviceAPICallResult_response_time_s(::hos_interfaces::msg::DeviceAPICallResult & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::msg::DeviceAPICallResult response_time_s(::hos_interfaces::msg::DeviceAPICallResult::_response_time_s_type arg)
  {
    msg_.response_time_s = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceAPICallResult msg_;
};

class Init_DeviceAPICallResult_request_time_s
{
public:
  explicit Init_DeviceAPICallResult_request_time_s(::hos_interfaces::msg::DeviceAPICallResult & msg)
  : msg_(msg)
  {}
  Init_DeviceAPICallResult_response_time_s request_time_s(::hos_interfaces::msg::DeviceAPICallResult::_request_time_s_type arg)
  {
    msg_.request_time_s = std::move(arg);
    return Init_DeviceAPICallResult_response_time_s(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceAPICallResult msg_;
};

class Init_DeviceAPICallResult_result_jsons
{
public:
  explicit Init_DeviceAPICallResult_result_jsons(::hos_interfaces::msg::DeviceAPICallResult & msg)
  : msg_(msg)
  {}
  Init_DeviceAPICallResult_request_time_s result_jsons(::hos_interfaces::msg::DeviceAPICallResult::_result_jsons_type arg)
  {
    msg_.result_jsons = std::move(arg);
    return Init_DeviceAPICallResult_request_time_s(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceAPICallResult msg_;
};

class Init_DeviceAPICallResult_error
{
public:
  explicit Init_DeviceAPICallResult_error(::hos_interfaces::msg::DeviceAPICallResult & msg)
  : msg_(msg)
  {}
  Init_DeviceAPICallResult_result_jsons error(::hos_interfaces::msg::DeviceAPICallResult::_error_type arg)
  {
    msg_.error = std::move(arg);
    return Init_DeviceAPICallResult_result_jsons(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceAPICallResult msg_;
};

class Init_DeviceAPICallResult_success
{
public:
  explicit Init_DeviceAPICallResult_success(::hos_interfaces::msg::DeviceAPICallResult & msg)
  : msg_(msg)
  {}
  Init_DeviceAPICallResult_error success(::hos_interfaces::msg::DeviceAPICallResult::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_DeviceAPICallResult_error(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceAPICallResult msg_;
};

class Init_DeviceAPICallResult_task_id
{
public:
  Init_DeviceAPICallResult_task_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeviceAPICallResult_success task_id(::hos_interfaces::msg::DeviceAPICallResult::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_DeviceAPICallResult_success(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceAPICallResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::msg::DeviceAPICallResult>()
{
  return hos_interfaces::msg::builder::Init_DeviceAPICallResult_task_id();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__BUILDER_HPP_
