// Generated by gencpp from file dynamixel_controllers/RestartController.msg
// DO NOT EDIT!


#ifndef DYNAMIXEL_CONTROLLERS_MESSAGE_RESTARTCONTROLLER_H
#define DYNAMIXEL_CONTROLLERS_MESSAGE_RESTARTCONTROLLER_H

#include <ros/service_traits.h>


#include <dynamixel_controllers/RestartControllerRequest.h>
#include <dynamixel_controllers/RestartControllerResponse.h>


namespace dynamixel_controllers
{

struct RestartController
{

typedef RestartControllerRequest Request;
typedef RestartControllerResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct RestartController
} // namespace dynamixel_controllers


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dynamixel_controllers::RestartController > {
  static const char* value()
  {
    return "94c76c2df56346fcaa2611bdac54f434";
  }

  static const char* value(const ::dynamixel_controllers::RestartController&) { return value(); }
};

template<>
struct DataType< ::dynamixel_controllers::RestartController > {
  static const char* value()
  {
    return "dynamixel_controllers/RestartController";
  }

  static const char* value(const ::dynamixel_controllers::RestartController&) { return value(); }
};


// service_traits::MD5Sum< ::dynamixel_controllers::RestartControllerRequest> should match 
// service_traits::MD5Sum< ::dynamixel_controllers::RestartController > 
template<>
struct MD5Sum< ::dynamixel_controllers::RestartControllerRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dynamixel_controllers::RestartController >::value();
  }
  static const char* value(const ::dynamixel_controllers::RestartControllerRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dynamixel_controllers::RestartControllerRequest> should match 
// service_traits::DataType< ::dynamixel_controllers::RestartController > 
template<>
struct DataType< ::dynamixel_controllers::RestartControllerRequest>
{
  static const char* value()
  {
    return DataType< ::dynamixel_controllers::RestartController >::value();
  }
  static const char* value(const ::dynamixel_controllers::RestartControllerRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dynamixel_controllers::RestartControllerResponse> should match 
// service_traits::MD5Sum< ::dynamixel_controllers::RestartController > 
template<>
struct MD5Sum< ::dynamixel_controllers::RestartControllerResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dynamixel_controllers::RestartController >::value();
  }
  static const char* value(const ::dynamixel_controllers::RestartControllerResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dynamixel_controllers::RestartControllerResponse> should match 
// service_traits::DataType< ::dynamixel_controllers::RestartController > 
template<>
struct DataType< ::dynamixel_controllers::RestartControllerResponse>
{
  static const char* value()
  {
    return DataType< ::dynamixel_controllers::RestartController >::value();
  }
  static const char* value(const ::dynamixel_controllers::RestartControllerResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DYNAMIXEL_CONTROLLERS_MESSAGE_RESTARTCONTROLLER_H