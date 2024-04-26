// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hos_interfaces:msg/TypedField.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__TRAITS_HPP_
#define HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hos_interfaces/msg/detail/typed_field__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hos_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TypedField & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TypedField & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TypedField & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace hos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use hos_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hos_interfaces::msg::TypedField & msg,
  std::ostream & out, size_t indentation = 0)
{
  hos_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hos_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const hos_interfaces::msg::TypedField & msg)
{
  return hos_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hos_interfaces::msg::TypedField>()
{
  return "hos_interfaces::msg::TypedField";
}

template<>
inline const char * name<hos_interfaces::msg::TypedField>()
{
  return "hos_interfaces/msg/TypedField";
}

template<>
struct has_fixed_size<hos_interfaces::msg::TypedField>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hos_interfaces::msg::TypedField>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hos_interfaces::msg::TypedField>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__TRAITS_HPP_
