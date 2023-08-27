import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from geometry_msgs.msg import PoseStamped
from mavros_msgs.msg import State
from mavros_msgs.srv import SetMode, CommandBool
from pymavlink import mavutil
from aruco_pose.msg import ArucoMarker
import numpy as np

# ArUco marker dictionary and parameters
aruco_dict = cv2.aruco.Dictionary_get(cv2.aruco.DICT_6X6_250)
aruco_params = cv2.aruco.DetectorParameters_create()

# Initialize ROS node
rospy.init_node('aruco_marker_detection')

# CV bridge for converting ROS images to OpenCV images
bridge = CvBridge()

# ROS publisher for ArUco marker pose
marker_pub = rospy.Publisher('/aruco_marker_pose', ArucoMarker, queue_size=10)

# ROS subscriber for receiving camera images
image_sub = rospy.Subscriber('/camera/image_raw', Image, image_callback)

# ROS subscriber for receiving MAVROS state
state_sub = rospy.Subscriber('/mavros/state', State, state_callback)

# ROS service clients for MAVROS commands
set_mode_client = rospy.ServiceProxy('/mavros/set_mode', SetMode)
arm_client = rospy.ServiceProxy('/mavros/cmd/arming', CommandBool)

# Global variables
current_pose = PoseStamped()
current_state = State()

def image_callback(msg):
    # Convert ROS image to OpenCV image
    cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')

    # Detect ArUco markers
    corners, ids, _ = cv2.aruco.detectMarkers(cv_image, aruco_dict, parameters=aruco_params)

    # Publish detected markers as ROS messages
    if ids is not None:
        for i in range(len(ids)):
            # Calculate marker pose
            rvec, tvec, _ = cv2.aruco.estimatePoseSingleMarkers(corners[i], marker_size, camera_matrix, distortion_coeffs)

            # Convert pose to ROS message
            marker_msg = ArucoMarker()
            marker_msg.marker_id = ids[i][0]
            marker_msg.pose.position.x = tvec[0][0][0]
            marker_msg.pose.position.y = tvec[0][0][1]
            marker_msg.pose.position.z = tvec[0][0][2]
            marker_msg.pose.orientation.x = rvec[0][0][0]
            marker_msg.pose.orientation.y = rvec[0][0][1]
            marker_msg.pose.orientation.z = rvec[0][0][2]
            marker_msg.pose.orientation.w = rvec[0][0][3]

            # Publish marker pose
            marker_pub.publish(marker_msg)

            # Print marker ID and pose
            print(f"Marker ID: {ids[i][0]}")
            print(f"Position (X, Y, Z): {tvec[0][0]}")

def state_callback(msg):
    # Update current MAVROS state
    global current_state
    current_state = msg

def set_mode(mode):
    # Set MAVROS flight mode
    rospy.wait_for_service('/mavros/set_mode')
    try:
        response = set_mode_client(custom_mode=mode)
        return response.mode_sent
    except rospy.ServiceException as e:
        print("Service call failed:", str(e))

def arm(enable):
    # Arm or disarm the vehicle
    rospy.wait_for_service('/mavros/cmd/arming')
    try:
        response = arm_client(value=enable)
        return response.success
    except rospy.ServiceException as e:
        print("Service call failed:", str(e))

if __name__ == '__main__':
    calib_path=" "  #define the pth to the camera file
    cameraMatrix   = np.loadtxt(calib_path+'cameraMatrix.txt', delimiter=',')
    cameraDistortion   = np.loadtxt(calib_path+'cameraDistortion.txt', delimiter=',')

    # Set marker size (in meters)
    marker_size = 0.1

    # Set up Gazebo simulation

    # Set up ROS rate
    rate = rospy.Rate(10)  # 10 Hz

    # Main loop
    while not rospy.is_shutdown():
        # Check if vehicle is armed and in GUIDED mode
        if current_state.armed and current_state.mode == 'GUIDED':
            # Perform control actions based on detected marker pose
            # ...

        rate.sleep()
