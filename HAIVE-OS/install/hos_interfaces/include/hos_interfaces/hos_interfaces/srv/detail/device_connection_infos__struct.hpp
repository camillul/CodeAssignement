// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hos_interfaces:srv/DeviceConnectionInfos.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__STRUCT_HPP_
#define HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__srv__DeviceConnectionInfos_Request __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__srv__DeviceConnectionInfos_Request __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeviceConnectionInfos_Request_
{
  using Type = DeviceConnectionInfos_Request_<ContainerAllocator>;

  explicit DeviceConnectionInfos_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit DeviceConnectionInfos_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__srv__DeviceConnectionInfos_Request
    std::shared_ptr<hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__srv__DeviceConnectionInfos_Request
    std::shared_ptr<hos_interfaces::srv::DeviceConnectionInfos_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeviceConnectionInfos_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeviceConnectionInfos_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeviceConnectionInfos_Request_

// alias to use template instance with default allocator
using DeviceConnectionInfos_Request =
  hos_interfaces::srv::DeviceConnectionInfos_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hos_interfaces


// Include directives for member types
// Member 'device_infos'
#include "hos_interfaces/msg/detail/connection_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hos_interfaces__srv__DeviceConnectionInfos_Response __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__srv__DeviceConnectionInfos_Response __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeviceConnectionInfos_Response_
{
  using Type = DeviceConnectionInfos_Response_<ContainerAllocator>;

  explicit DeviceConnectionInfos_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DeviceConnectionInfos_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _device_infos_type =
    std::vector<hos_interfaces::msg::ConnectionInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hos_interfaces::msg::ConnectionInfo_<ContainerAllocator>>>;
  _device_infos_type device_infos;

  // setters for named parameter idiom
  Type & set__device_infos(
    const std::vector<hos_interfaces::msg::ConnectionInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hos_interfaces::msg::ConnectionInfo_<ContainerAllocator>>> & _arg)
  {
    this->device_infos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__srv__DeviceConnectionInfos_Response
    std::shared_ptr<hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__srv__DeviceConnectionInfos_Response
    std::shared_ptr<hos_interfaces::srv::DeviceConnectionInfos_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeviceConnectionInfos_Response_ & other) const
  {
    if (this->device_infos != other.device_infos) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeviceConnectionInfos_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeviceConnectionInfos_Response_

// alias to use template instance with default allocator
using DeviceConnectionInfos_Response =
  hos_interfaces::srv::DeviceConnectionInfos_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hos_interfaces

namespace hos_interfaces
{

namespace srv
{

struct DeviceConnectionInfos
{
  using Request = hos_interfaces::srv::DeviceConnectionInfos_Request;
  using Response = hos_interfaces::srv::DeviceConnectionInfos_Response;
};

}  // namespace srv

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__STRUCT_HPP_
