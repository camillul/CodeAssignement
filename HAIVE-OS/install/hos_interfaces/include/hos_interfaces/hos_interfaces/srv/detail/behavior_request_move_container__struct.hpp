// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hos_interfaces:srv/BehaviorRequestMoveContainer.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__STRUCT_HPP_
#define HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__srv__BehaviorRequestMoveContainer_Request __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__srv__BehaviorRequestMoveContainer_Request __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BehaviorRequestMoveContainer_Request_
{
  using Type = BehaviorRequestMoveContainer_Request_<ContainerAllocator>;

  explicit BehaviorRequestMoveContainer_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->container_id = "";
      this->haive_id = "";
      this->slot = 0;
    }
  }

  explicit BehaviorRequestMoveContainer_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : container_id(_alloc),
    haive_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->container_id = "";
      this->haive_id = "";
      this->slot = 0;
    }
  }

  // field types and members
  using _container_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _container_id_type container_id;
  using _haive_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _haive_id_type haive_id;
  using _slot_type =
    uint8_t;
  _slot_type slot;

  // setters for named parameter idiom
  Type & set__container_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->container_id = _arg;
    return *this;
  }
  Type & set__haive_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->haive_id = _arg;
    return *this;
  }
  Type & set__slot(
    const uint8_t & _arg)
  {
    this->slot = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__srv__BehaviorRequestMoveContainer_Request
    std::shared_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__srv__BehaviorRequestMoveContainer_Request
    std::shared_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BehaviorRequestMoveContainer_Request_ & other) const
  {
    if (this->container_id != other.container_id) {
      return false;
    }
    if (this->haive_id != other.haive_id) {
      return false;
    }
    if (this->slot != other.slot) {
      return false;
    }
    return true;
  }
  bool operator!=(const BehaviorRequestMoveContainer_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BehaviorRequestMoveContainer_Request_

// alias to use template instance with default allocator
using BehaviorRequestMoveContainer_Request =
  hos_interfaces::srv::BehaviorRequestMoveContainer_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hos_interfaces


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__srv__BehaviorRequestMoveContainer_Response __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__srv__BehaviorRequestMoveContainer_Response __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BehaviorRequestMoveContainer_Response_
{
  using Type = BehaviorRequestMoveContainer_Response_<ContainerAllocator>;

  explicit BehaviorRequestMoveContainer_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error = "";
    }
  }

  explicit BehaviorRequestMoveContainer_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _error_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_type error;

  // setters for named parameter idiom
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

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__srv__BehaviorRequestMoveContainer_Response
    std::shared_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__srv__BehaviorRequestMoveContainer_Response
    std::shared_ptr<hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BehaviorRequestMoveContainer_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const BehaviorRequestMoveContainer_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BehaviorRequestMoveContainer_Response_

// alias to use template instance with default allocator
using BehaviorRequestMoveContainer_Response =
  hos_interfaces::srv::BehaviorRequestMoveContainer_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hos_interfaces

namespace hos_interfaces
{

namespace srv
{

struct BehaviorRequestMoveContainer
{
  using Request = hos_interfaces::srv::BehaviorRequestMoveContainer_Request;
  using Response = hos_interfaces::srv::BehaviorRequestMoveContainer_Response;
};

}  // namespace srv

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__STRUCT_HPP_
