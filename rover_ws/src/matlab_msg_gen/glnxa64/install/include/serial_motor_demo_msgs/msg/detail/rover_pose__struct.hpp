// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from serial_motor_demo_msgs:msg/RoverPose.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ROVER_POSE__STRUCT_HPP_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ROVER_POSE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__serial_motor_demo_msgs__msg__RoverPose __attribute__((deprecated))
#else
# define DEPRECATED__serial_motor_demo_msgs__msg__RoverPose __declspec(deprecated)
#endif

namespace serial_motor_demo_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RoverPose_
{
  using Type = RoverPose_<ContainerAllocator>;

  explicit RoverPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rover_x = 0.0;
      this->rover_y = 0.0;
    }
  }

  explicit RoverPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rover_x = 0.0;
      this->rover_y = 0.0;
    }
  }

  // field types and members
  using _rover_x_type =
    double;
  _rover_x_type rover_x;
  using _rover_y_type =
    double;
  _rover_y_type rover_y;

  // setters for named parameter idiom
  Type & set__rover_x(
    const double & _arg)
  {
    this->rover_x = _arg;
    return *this;
  }
  Type & set__rover_y(
    const double & _arg)
  {
    this->rover_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__serial_motor_demo_msgs__msg__RoverPose
    std::shared_ptr<serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__serial_motor_demo_msgs__msg__RoverPose
    std::shared_ptr<serial_motor_demo_msgs::msg::RoverPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RoverPose_ & other) const
  {
    if (this->rover_x != other.rover_x) {
      return false;
    }
    if (this->rover_y != other.rover_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const RoverPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RoverPose_

// alias to use template instance with default allocator
using RoverPose =
  serial_motor_demo_msgs::msg::RoverPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace serial_motor_demo_msgs

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ROVER_POSE__STRUCT_HPP_
