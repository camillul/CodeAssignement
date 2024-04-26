// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:msg/TypedField.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__BUILDER_HPP_
#define HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/msg/detail/typed_field__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace msg
{

namespace builder
{

class Init_TypedField_data
{
public:
  explicit Init_TypedField_data(::hos_interfaces::msg::TypedField & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::msg::TypedField data(::hos_interfaces::msg::TypedField::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::msg::TypedField msg_;
};

class Init_TypedField_type
{
public:
  explicit Init_TypedField_type(::hos_interfaces::msg::TypedField & msg)
  : msg_(msg)
  {}
  Init_TypedField_data type(::hos_interfaces::msg::TypedField::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_TypedField_data(msg_);
  }

private:
  ::hos_interfaces::msg::TypedField msg_;
};

class Init_TypedField_name
{
public:
  Init_TypedField_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TypedField_type name(::hos_interfaces::msg::TypedField::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_TypedField_type(msg_);
  }

private:
  ::hos_interfaces::msg::TypedField msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::msg::TypedField>()
{
  return hos_interfaces::msg::builder::Init_TypedField_name();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__BUILDER_HPP_
