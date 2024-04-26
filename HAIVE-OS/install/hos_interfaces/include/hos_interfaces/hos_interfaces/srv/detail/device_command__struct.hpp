// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hos_interfaces:srv/DeviceCommand.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__DEVICE_COMMAND__STRUCT_HPP_
#define HOS_INTERFACES__SRV__DETAIL__DEVICE_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'args'
#include "hos_interfaces/msg/detail/typed_field__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hos_interfaces__srv__DeviceCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__srv__DeviceCommand_Request __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeviceCommand_Request_
{
  using Type = DeviceCommand_Request_<ContainerAllocator>;

  explicit DeviceCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_id = 0ul;
      this->function_name = "";
      this->num_args = 0;
    }
  }

  explicit DeviceCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : function_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_id = 0ul;
      this->function_name = "";
      this->num_args = 0;
    }
  }

  // field types and members
  using _cmd_id_type =
    uint32_t;
  _cmd_id_type cmd_id;
  using _function_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _function_name_type function_name;
  using _num_args_type =
    uint8_t;
  _num_args_type num_args;
  using _args_type =
    std::vector<hos_interfaces::msg::TypedField_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hos_interfaces::msg::TypedField_<ContainerAllocator>>>;
  _args_type args;

  // setters for named parameter idiom
  Type & set__cmd_id(
    const uint32_t & _arg)
  {
    this->cmd_id = _arg;
    return *this;
  }
  Type & set__function_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->function_name = _arg;
    return *this;
  }
  Type & set__num_args(
    const uint8_t & _arg)
  {
    this->num_args = _arg;
    return *this;
  }
  Type & set__args(
    const std::vector<hos_interfaces::msg::TypedField_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hos_interfaces::msg::TypedField_<ContainerAllocator>>> & _arg)
  {
    this->args = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__srv__DeviceCommand_Request
    std::shared_ptr<hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__srv__DeviceCommand_Request
    std::shared_ptr<hos_interfaces::srv::DeviceCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeviceCommand_Request_ & other) const
  {
    if (this->cmd_id != other.cmd_id) {
      return false;
    }
    if (this->function_name != other.function_name) {
      return false;
    }
    if (this->num_args != other.num_args) {
      return false;
    }
    if (this->args != other.args) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeviceCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeviceCommand_Request_

// alias to use template instance with default allocator
using DeviceCommand_Request =
  hos_interfaces::srv::DeviceCommand_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hos_interfaces


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__srv__DeviceCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__srv__DeviceCommand_Response __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeviceCommand_Response_
{
  using Type = DeviceCommand_Response_<ContainerAllocator>;

  explicit DeviceCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_valid = false;
      this->error = "";
    }
  }

  explicit DeviceCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_valid = false;
      this->error = "";
    }
  }

  // field types and members
  using _is_valid_type =
    bool;
  _is_valid_type is_valid;
  using _error_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_type error;

  // setters for named parameter idiom
  Type & set__is_valid(
    const bool & _arg)
  {
    this->is_valid = _arg;
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
    hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__srv__DeviceCommand_Response
    std::shared_ptr<hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__srv__DeviceCommand_Response
    std::shared_ptr<hos_interfaces::srv::DeviceCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeviceCommand_Response_ & other) const
  {
    if (this->is_valid != other.is_valid) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeviceCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeviceCommand_Response_

// alias to use template instance with default allocator
using DeviceCommand_Response =
  hos_interfaces::srv::DeviceCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hos_interfaces

namespace hos_interfaces
{

namespace srv
{

struct DeviceCommand
{
  using Request = hos_interfaces::srv::DeviceCommand_Request;
  using Response = hos_interfaces::srv::DeviceCommand_Response;
};

}  // namespace srv

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__DEVICE_COMMAND__STRUCT_HPP_
