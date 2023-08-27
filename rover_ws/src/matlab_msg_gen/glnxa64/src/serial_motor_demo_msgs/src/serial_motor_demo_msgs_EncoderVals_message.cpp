// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for serial_motor_demo_msgs/EncoderVals
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
#include "serial_motor_demo_msgs/msg/encoder_vals.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class SERIAL_MOTOR_DEMO_MSGS_EXPORT ros2_serial_motor_demo_msgs_msg_EncoderVals_common : public MATLABROS2MsgInterface<serial_motor_demo_msgs::msg::EncoderVals> {
  public:
    virtual ~ros2_serial_motor_demo_msgs_msg_EncoderVals_common(){}
    virtual void copy_from_struct(serial_motor_demo_msgs::msg::EncoderVals* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const serial_motor_demo_msgs::msg::EncoderVals* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_serial_motor_demo_msgs_msg_EncoderVals_common::copy_from_struct(serial_motor_demo_msgs::msg::EncoderVals* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //mot_1_enc_val
        const matlab::data::TypedArray<int32_t> mot_1_enc_val_arr = arr["mot_1_enc_val"];
        msg->mot_1_enc_val = mot_1_enc_val_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'mot_1_enc_val' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'mot_1_enc_val' is wrong type; expected a int32.");
    }
    try {
        //mot_2_enc_val
        const matlab::data::TypedArray<int32_t> mot_2_enc_val_arr = arr["mot_2_enc_val"];
        msg->mot_2_enc_val = mot_2_enc_val_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'mot_2_enc_val' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'mot_2_enc_val' is wrong type; expected a int32.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_serial_motor_demo_msgs_msg_EncoderVals_common::get_arr(MDFactory_T& factory, const serial_motor_demo_msgs::msg::EncoderVals* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","mot_1_enc_val","mot_2_enc_val"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("serial_motor_demo_msgs/EncoderVals");
    // mot_1_enc_val
    auto currentElement_mot_1_enc_val = (msg + ctr)->mot_1_enc_val;
    outArray[ctr]["mot_1_enc_val"] = factory.createScalar(currentElement_mot_1_enc_val);
    // mot_2_enc_val
    auto currentElement_mot_2_enc_val = (msg + ctr)->mot_2_enc_val;
    outArray[ctr]["mot_2_enc_val"] = factory.createScalar(currentElement_mot_2_enc_val);
    }
    return std::move(outArray);
  } 
class SERIAL_MOTOR_DEMO_MSGS_EXPORT ros2_serial_motor_demo_msgs_EncoderVals_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_serial_motor_demo_msgs_EncoderVals_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_serial_motor_demo_msgs_EncoderVals_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<serial_motor_demo_msgs::msg::EncoderVals,ros2_serial_motor_demo_msgs_msg_EncoderVals_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_serial_motor_demo_msgs_EncoderVals_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<serial_motor_demo_msgs::msg::EncoderVals,ros2_serial_motor_demo_msgs_msg_EncoderVals_common>>();
  }
  std::shared_ptr<void> ros2_serial_motor_demo_msgs_EncoderVals_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<serial_motor_demo_msgs::msg::EncoderVals>();
    ros2_serial_motor_demo_msgs_msg_EncoderVals_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_serial_motor_demo_msgs_EncoderVals_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_serial_motor_demo_msgs_msg_EncoderVals_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (serial_motor_demo_msgs::msg::EncoderVals*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_serial_motor_demo_msgs_msg_EncoderVals_common, MATLABROS2MsgInterface<serial_motor_demo_msgs::msg::EncoderVals>)
CLASS_LOADER_REGISTER_CLASS(ros2_serial_motor_demo_msgs_EncoderVals_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER