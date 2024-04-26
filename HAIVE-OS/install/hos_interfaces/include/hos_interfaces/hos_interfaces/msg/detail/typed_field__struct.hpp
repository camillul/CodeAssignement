// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hos_interfaces:msg/TypedField.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__STRUCT_HPP_
#define HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__msg__TypedField __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__msg__TypedField __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TypedField_
{
  using Type = TypedField_<ContainerAllocator>;

  explicit TypedField_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->type = "";
      this->data = "";
    }
  }

  explicit TypedField_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    type(_alloc),
    data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->type = "";
      this->data = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_type type;
  using _data_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__data(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::msg::TypedField_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::msg::TypedField_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::msg::TypedField_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::msg::TypedField_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::TypedField_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::TypedField_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::TypedField_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::TypedField_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::msg::TypedField_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::msg::TypedField_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__msg__TypedField
    std::shared_ptr<hos_interfaces::msg::TypedField_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__msg__TypedField
    std::shared_ptr<hos_interfaces::msg::TypedField_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TypedField_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const TypedField_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TypedField_

// alias to use template instance with default allocator
using TypedField =
  hos_interfaces::msg::TypedField_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__STRUCT_HPP_
