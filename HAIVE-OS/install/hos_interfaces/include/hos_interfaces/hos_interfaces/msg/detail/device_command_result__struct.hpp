// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hos_interfaces:msg/DeviceCommandResult.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__DEVICE_COMMAND_RESULT__STRUCT_HPP_
#define HOS_INTERFACES__MSG__DETAIL__DEVICE_COMMAND_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__msg__DeviceCommandResult __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__msg__DeviceCommandResult __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DeviceCommandResult_
{
  using Type = DeviceCommandResult_<ContainerAllocator>;

  explicit DeviceCommandResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uid = 0ul;
      this->cmd_id = 0ul;
      this->success = false;
      this->error = "";
      this->result_str = "";
    }
  }

  explicit DeviceCommandResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc),
    result_str(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uid = 0ul;
      this->cmd_id = 0ul;
      this->success = false;
      this->error = "";
      this->result_str = "";
    }
  }

  // field types and members
  using _uid_type =
    uint32_t;
  _uid_type uid;
  using _cmd_id_type =
    uint32_t;
  _cmd_id_type cmd_id;
  using _success_type =
    bool;
  _success_type success;
  using _error_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_type error;
  using _result_str_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_str_type result_str;

  // setters for named parameter idiom
  Type & set__uid(
    const uint32_t & _arg)
  {
    this->uid = _arg;
    return *this;
  }
  Type & set__cmd_id(
    const uint32_t & _arg)
  {
    this->cmd_id = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__error(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error = _arg;
    return *this;
  }
  Type & set__result_str(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result_str = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__msg__DeviceCommandResult
    std::shared_ptr<hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__msg__DeviceCommandResult
    std::shared_ptr<hos_interfaces::msg::DeviceCommandResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeviceCommandResult_ & other) const
  {
    if (this->uid != other.uid) {
      return false;
    }
    if (this->cmd_id != other.cmd_id) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    if (this->result_str != other.result_str) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeviceCommandResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeviceCommandResult_

// alias to use template instance with default allocator
using DeviceCommandResult =
  hos_interfaces::msg::DeviceCommandResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__DEVICE_COMMAND_RESULT__STRUCT_HPP_
