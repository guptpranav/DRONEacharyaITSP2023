function ros1msg = serial_motor_demo_msgs_msg_RoverPose_2To1_Converter(message,ros1msg)
%serial_motor_demo_msgs_msg_RoverPose_2To1_Converter passes data of ROS 2 message to ROS message.
% Copyright 2019 The MathWorks, Inc.    
ros1msg.RoverX = message.rover_x;
ros1msg.RoverY = message.rover_y;
end