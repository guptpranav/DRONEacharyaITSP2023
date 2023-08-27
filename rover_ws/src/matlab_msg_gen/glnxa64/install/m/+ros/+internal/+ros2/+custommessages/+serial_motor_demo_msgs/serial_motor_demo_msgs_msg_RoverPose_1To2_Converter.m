function ros2msg = serial_motor_demo_msgs_msg_RoverPose_1To2_Converter(message,ros2msg)
%serial_motor_demo_msgs_msg_RoverPose_1To2_Converter passes data of ROS message to ROS 2 message.
% Copyright 2019 The MathWorks, Inc.
ros2msg.rover_x = message.RoverX;
ros2msg.rover_y = message.RoverY;
end