// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:msg/DeviceStream.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__DEVICE_STREAM__BUILDER_HPP_
#define HOS_INTERFACES__MSG__DETAIL__DEVICE_STREAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/msg/detail/device_stream__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace msg
{

namespace builder
{

class Init_DeviceStream_data
{
public:
  explicit Init_DeviceStream_data(::hos_interfaces::msg::DeviceStream & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::msg::DeviceStream data(::hos_interfaces::msg::DeviceStream::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceStream msg_;
};

class Init_DeviceStream_uid
{
public:
  Init_DeviceStream_uid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeviceStream_data uid(::hos_interfaces::msg::DeviceStream::_uid_type arg)
  {
    msg_.uid = std::move(arg);
    return Init_DeviceStream_data(msg_);
  }

private:
  ::hos_interfaces::msg::DeviceStream msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::msg::DeviceStream>()
{
  return hos_interfaces::msg::builder::Init_DeviceStream_uid();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__DEVICE_STREAM__BUILDER_HPP_
