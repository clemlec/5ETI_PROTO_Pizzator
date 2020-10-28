// Generated by gencpp from file dynamixel_controllers/RestartControllerResponse.msg
// DO NOT EDIT!


#ifndef DYNAMIXEL_CONTROLLERS_MESSAGE_RESTARTCONTROLLERRESPONSE_H
#define DYNAMIXEL_CONTROLLERS_MESSAGE_RESTARTCONTROLLERRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dynamixel_controllers
{
template <class ContainerAllocator>
struct RestartControllerResponse_
{
  typedef RestartControllerResponse_<ContainerAllocator> Type;

  RestartControllerResponse_()
    : success(false)
    , reason()  {
    }
  RestartControllerResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , reason(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _reason_type;
  _reason_type reason;





  typedef boost::shared_ptr< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> const> ConstPtr;

}; // struct RestartControllerResponse_

typedef ::dynamixel_controllers::RestartControllerResponse_<std::allocator<void> > RestartControllerResponse;

typedef boost::shared_ptr< ::dynamixel_controllers::RestartControllerResponse > RestartControllerResponsePtr;
typedef boost::shared_ptr< ::dynamixel_controllers::RestartControllerResponse const> RestartControllerResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dynamixel_controllers

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a4d50a34d34f18de48e2436ff1472594";
  }

  static const char* value(const ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa4d50a34d34f18deULL;
  static const uint64_t static_value2 = 0x48e2436ff1472594ULL;
};

template<class ContainerAllocator>
struct DataType< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dynamixel_controllers/RestartControllerResponse";
  }

  static const char* value(const ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n\
string reason\n\
\n\
";
  }

  static const char* value(const ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.reason);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RestartControllerResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dynamixel_controllers::RestartControllerResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "reason: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.reason);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DYNAMIXEL_CONTROLLERS_MESSAGE_RESTARTCONTROLLERRESPONSE_H
