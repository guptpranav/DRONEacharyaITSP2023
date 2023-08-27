// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for serial_motor_demo_msgs/MotorCommand
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4100)
#pragma warning(disable : 4265)
#pragma warning(disable : 4456)
#pragma warning(disable : 4458)
#pragma warning(disable : 4946)
#pragma warning(disable : 4244)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif //_MSC_VER
#include "rclcpp/rclcpp.hpp"
#include "serial_motor_demo_msgs/msg/motor_command.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class SERIAL_MOTOR_DEMO_MSGS_EXPORT ros2_serial_motor_demo_msgs_msg_MotorCommand_common : public MATLABROS2MsgInterface<serial_motor_demo_msgs::msg::MotorCommand> {
  public:
    virtual ~ros2_serial_motor_demo_msgs_msg_MotorCommand_common(){}
    virtual void copy_from_struct(serial_motor_demo_msgs::msg::MotorCommand* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const serial_motor_demo_msgs::msg::MotorCommand* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_serial_motor_demo_msgs_msg_MotorCommand_common::copy_from_struct(serial_motor_demo_msgs::msg::MotorCommand* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //is_pwm
        const matlab::data::TypedArray<bool> is_pwm_arr = arr["is_pwm"];
        msg->is_pwm = is_pwm_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'is_pwm' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'is_pwm' is wrong type; expected a logical.");
    }
    try {
        //mot_1_req_rad_sec
        const matlab::data::TypedArray<float> mot_1_req_rad_sec_arr = arr["mot_1_req_rad_sec"];
        msg->mot_1_req_rad_sec = mot_1_req_rad_sec_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'mot_1_req_rad_sec' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'mot_1_req_rad_sec' is wrong type; expected a single.");
    }
    try {
        //mot_2_req_rad_sec
        const matlab::data::TypedArray<float> mot_2_req_rad_sec_arr = arr["mot_2_req_rad_sec"];
        msg->mot_2_req_rad_sec = mot_2_req_rad_sec_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'mot_2_req_rad_sec' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'mot_2_req_rad_sec' is wrong type; expected a single.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_serial_motor_demo_msgs_msg_MotorCommand_common::get_arr(MDFactory_T& factory, const serial_motor_demo_msgs::msg::MotorCommand* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","is_pwm","mot_1_req_rad_sec","mot_2_req_rad_sec"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("serial_motor_demo_msgs/MotorCommand");
    // is_pwm
    auto currentElement_is_pwm = (msg + ctr)->is_pwm;
    outArray[ctr]["is_pwm"] = factory.createScalar(currentElement_is_pwm);
    // mot_1_req_rad_sec
    auto currentElement_mot_1_req_rad_sec = (msg + ctr)->mot_1_req_rad_sec;
    outArray[ctr]["mot_1_req_rad_sec"] = factory.createScalar(currentElement_mot_1_req_rad_sec);
    // mot_2_req_rad_sec
    auto currentElement_mot_2_req_rad_sec = (msg + ctr)->mot_2_req_rad_sec;
    outArray[ctr]["mot_2_req_rad_sec"] = factory.createScalar(currentElement_mot_2_req_rad_sec);
    }
    return std::move(outArray);
  } 
class SERIAL_MOTOR_DEMO_MSGS_EXPORT ros2_serial_motor_demo_msgs_MotorCommand_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_serial_motor_demo_msgs_MotorCommand_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_serial_motor_demo_msgs_MotorCommand_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<serial_motor_demo_msgs::msg::MotorCommand,ros2_serial_motor_demo_msgs_msg_MotorCommand_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_serial_motor_demo_msgs_MotorCommand_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<serial_motor_demo_msgs::msg::MotorCommand,ros2_serial_motor_demo_msgs_msg_MotorCommand_common>>();
  }
  std::shared_ptr<void> ros2_serial_motor_demo_msgs_MotorCommand_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<serial_motor_demo_msgs::msg::MotorCommand>();
    ros2_serial_motor_demo_msgs_msg_MotorCommand_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_serial_motor_demo_msgs_MotorCommand_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_serial_motor_demo_msgs_msg_MotorCommand_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (serial_motor_demo_msgs::msg::MotorCommand*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_serial_motor_demo_msgs_msg_MotorCommand_common, MATLABROS2MsgInterface<serial_motor_demo_msgs::msg::MotorCommand>)
CLASS_LOADER_REGISTER_CLASS(ros2_serial_motor_demo_msgs_MotorCommand_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER