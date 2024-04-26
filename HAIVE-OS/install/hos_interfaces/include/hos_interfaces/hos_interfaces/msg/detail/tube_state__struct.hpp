// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hos_interfaces:msg/TubeState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__STRUCT_HPP_
#define HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__msg__TubeState __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__msg__TubeState __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TubeState_
{
  using Type = TubeState_<ContainerAllocator>;

  explicit TubeState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->liquid_level = 0.0f;
      this->tube_id = "";
      this->tube_type = "";
      this->volume = 0.0f;
      this->temperature = 0.0f;
    }
  }

  explicit TubeState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tube_id(_alloc),
    tube_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->liquid_level = 0.0f;
      this->tube_id = "";
      this->tube_type = "";
      this->volume = 0.0f;
      this->temperature = 0.0f;
    }
  }

  // field types and members
  using _liquid_level_type =
    float;
  _liquid_level_type liquid_level;
  using _tube_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tube_id_type tube_id;
  using _tube_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tube_type_type tube_type;
  using _volume_type =
    float;
  _volume_type volume;
  using _temperature_type =
    float;
  _temperature_type temperature;

  // setters for named parameter idiom
  Type & set__liquid_level(
    const float & _arg)
  {
    this->liquid_level = _arg;
    return *this;
  }
  Type & set__tube_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tube_id = _arg;
    return *this;
  }
  Type & set__tube_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tube_type = _arg;
    return *this;
  }
  Type & set__volume(
    const float & _arg)
  {
    this->volume = _arg;
    return *this;
  }
  Type & set__temperature(
    const float & _arg)
  {
    this->temperature = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::msg::TubeState_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::msg::TubeState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::msg::TubeState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::msg::TubeState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::TubeState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::TubeState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::TubeState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::TubeState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::msg::TubeState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::msg::TubeState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__msg__TubeState
    std::shared_ptr<hos_interfaces::msg::TubeState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__msg__TubeState
    std::shared_ptr<hos_interfaces::msg::TubeState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TubeState_ & other) const
  {
    if (this->liquid_level != other.liquid_level) {
      return false;
    }
    if (this->tube_id != other.tube_id) {
      return false;
    }
    if (this->tube_type != other.tube_type) {
      return false;
    }
    if (this->volume != other.volume) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    return true;
  }
  bool operator!=(const TubeState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TubeState_

// alias to use template instance with default allocator
using TubeState =
  hos_interfaces::msg::TubeState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__STRUCT_HPP_
