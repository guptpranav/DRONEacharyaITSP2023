function ros1msg = serial_motor_demo_msgs_msg_EncoderVals_2To1_Converter(message,ros1msg)
%serial_motor_demo_msgs_msg_EncoderVals_2To1_Converter passes data of ROS 2 message to ROS message.
% Copyright 2019 The MathWorks, Inc.    
ros1msg.Mot1EncVal = message.mot_1_enc_val;
ros1msg.Mot2EncVal = message.mot_2_enc_val;
end