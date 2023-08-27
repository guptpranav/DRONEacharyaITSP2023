function ros2msg = serial_motor_demo_msgs_msg_EncoderVals_1To2_Converter(message,ros2msg)
%serial_motor_demo_msgs_msg_EncoderVals_1To2_Converter passes data of ROS message to ROS 2 message.
% Copyright 2019 The MathWorks, Inc.
ros2msg.mot_1_enc_val = message.Mot1EncVal;
ros2msg.mot_2_enc_val = message.Mot2EncVal;
end