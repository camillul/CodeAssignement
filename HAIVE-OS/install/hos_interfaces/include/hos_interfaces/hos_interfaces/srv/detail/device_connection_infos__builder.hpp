// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:srv/DeviceConnectionInfos.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__BUILDER_HPP_
#define HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/srv/detail/device_connection_infos__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::DeviceConnectionInfos_Request>()
{
  return ::hos_interfaces::srv::DeviceConnectionInfos_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace hos_interfaces


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_DeviceConnectionInfos_Response_device_infos
{
public:
  Init_DeviceConnectionInfos_Response_device_infos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hos_interfaces::srv::DeviceConnectionInfos_Response device_infos(::hos_interfaces::srv::DeviceConnectionInfos_Response::_device_infos_type arg)
  {
    msg_.device_infos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceConnectionInfos_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::DeviceConnectionInfos_Response>()
{
  return hos_interfaces::srv::builder::Init_DeviceConnectionInfos_Response_device_infos();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__BUILDER_HPP_
