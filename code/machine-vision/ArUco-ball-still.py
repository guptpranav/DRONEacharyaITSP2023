import numpy as np
import matplotlib.pyplot as plt
import tkinter as tk
from tkinter import filedialog
import os
import cv2
import sys
import argparse
import time
import requests
import math

ARUCO_DICT = {
	"DICT_4X4_50": cv2.aruco.DICT_4X4_50,
	"DICT_4X4_100": cv2.aruco.DICT_4X4_100,
	"DICT_4X4_250": cv2.aruco.DICT_4X4_250,
	"DICT_4X4_1000": cv2.aruco.DICT_4X4_1000,
	"DICT_5X5_50": cv2.aruco.DICT_5X5_50,
	"DICT_5X5_100": cv2.aruco.DICT_5X5_100,
	"DICT_5X5_250": cv2.aruco.DICT_5X5_250,
	"DICT_5X5_1000": cv2.aruco.DICT_5X5_1000,
	"DICT_6X6_50": cv2.aruco.DICT_6X6_50,
	"DICT_6X6_100": cv2.aruco.DICT_6X6_100,
	"DICT_6X6_250": cv2.aruco.DICT_6X6_250,
	"DICT_6X6_1000": cv2.aruco.DICT_6X6_1000,
	"DICT_7X7_50": cv2.aruco.DICT_7X7_50,
	"DICT_7X7_100": cv2.aruco.DICT_7X7_100,
	"DICT_7X7_250": cv2.aruco.DICT_7X7_250,
	"DICT_7X7_1000": cv2.aruco.DICT_7X7_1000,
	"DICT_ARUCO_ORIGINAL": cv2.aruco.DICT_ARUCO_ORIGINAL,
	"DICT_APRILTAG_16h5": cv2.aruco.DICT_APRILTAG_16h5,
	"DICT_APRILTAG_25h9": cv2.aruco.DICT_APRILTAG_25h9,
	"DICT_APRILTAG_36h10": cv2.aruco.DICT_APRILTAG_36h10,
	"DICT_APRILTAG_36h11": cv2.aruco.DICT_APRILTAG_36h11
}

def aruco_display(corners, ids, rejected, image):
	if len(corners) > 0:
		# flatten the ArUco IDs list
		ids = ids.flatten()
		# loop over the detected ArUCo corners
		for (markerCorner, markerID) in zip(corners, ids):
			corners = markerCorner.reshape((4, 2))
			(topLeft, topRight, bottomRight, bottomLeft) = corners
			topRight = (int(topRight[0]), int(topRight[1]))
			bottomRight = (int(bottomRight[0]), int(bottomRight[1]))
			bottomLeft = (int(bottomLeft[0]), int(bottomLeft[1]))
			topLeft = (int(topLeft[0]), int(topLeft[1]))

			cv2.line(image, topLeft, topRight, (0, 255, 0), 2)
			cv2.line(image, topRight, bottomRight, (0, 255, 0), 2)
			cv2.line(image, bottomRight, bottomLeft, (0, 255, 0), 2)
			cv2.line(image, bottomLeft, topLeft, (0, 255, 0), 2)

			cX = int((topLeft[0] + bottomRight[0]) / 2.0)
			cY = int((topLeft[1] + bottomRight[1]) / 2.0)
			cv2.circle(image, (cX, cY), 4, (0, 0, 255), -1)
			# draw the ArUco marker ID on the image
			cv2.putText(image, str(markerID),(topLeft[0], topLeft[1] - 10), cv2.FONT_HERSHEY_SIMPLEX,
				0.5, (0, 255, 0), 2)
			print("[Inference] ArUco marker ID: {}".format(markerID))
			# show the output image
	return image

config_file = 'ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt'
frozen_model = 'frozen_inference_graph.pb'
model = cv2.dnn_DetectionModel(frozen_model, config_file)   # Pre-trained model
model.setInputSize(320, 320)    # Set size of image
model.setInputScale(1.0/127.5)
model.setInputMean((127.5, 127.5, 127.5))

classLabels = []    # Labels for the objects
file_name = 'Labels.txt'
with open(file_name, 'rt') as fpt:
    classLabels = fpt.read().rstrip('\n').split('\n')

def pose_esitmation(frame, aruco_dict_type):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    aruco_dict = cv2.aruco.getPredefinedDictionary(aruco_dict_type)
    parameters =  cv2.aruco.DetectorParameters()
    detector = cv2.aruco.ArucoDetector(aruco_dict, parameters)

    corners, ids, rejected_img_points = detector.detectMarkers(frame)
    x_coordinates = []
    y_coordinates = []
    if len(corners) > 0:
        ids = ids.flatten()
        for (markerCorner, markerID) in zip(corners, ids):
            corner = markerCorner.reshape((4, 2))
            (topLeft, topRight, bottomRight, bottomLeft) = corner
            x_coordinates.append(topLeft[0])
            y_coordinates.append(topLeft[1])
        x_coordinates.sort()
        y_coordinates.sort()
        print(x_coordinates)
        for i in range(len(ids)):
            if (corners[i][0][0][0] == x_coordinates[0] or corners[i][0][0][0] == x_coordinates[1]) and (corners[i][0][0][1] == y_coordinates[-2] or corners[i][0][0][1] == y_coordinates[-1]):
                origin = (np.add(corners[i][0][0], corners[i][0][2]))/2
                origin_id = ids[i]
                len_of_aruco_in_pix = math.sqrt((corners[i][0][0][0] - corners[i][0][1][0])*(corners[i][0][0][0] - corners[i][0][1][0]) + (corners[i][0][0][1] - corners[i][0][1][1])*(corners[i][0][0][1] - corners[i][0][1][1]))
            if (corners[i][0][0][0] == x_coordinates[-2] or corners[i][0][0][0] == x_coordinates[-1]) and (corners[i][0][0][1] == y_coordinates[-2] or corners[i][0][0][1] == y_coordinates[-1]):
                aruco2 = (np.add(corners[i][0][0], corners[i][0][2]))/2
    #if len(corners) > 0:
    #    for i in range(len(ids)):
    #        if ids[i] == 1:
    #            origin = (np.add(corners[i][0][0], corners[i][0][2]))/2
    #        if ids[i] == 2:
    #            aruco2 = (np.add(corners[i][0][0], corners[i][0][2]))/2
        leninpix = np.subtract(aruco2, origin)
        leninpix_scalar = math.sqrt((leninpix[0])*(leninpix[0]) + (leninpix[1])*(leninpix[1]))
    #objPoints = np.array([[0., 0., 0.], [1., 0., 0.], [1., 1., 0.], [0., 1., 0.]])
    #if len(corners) > 0:
    #    for i in range(0, len(ids)):
    #        markerPoints, rvec, tvec = cv2.solvePnP(objPoints, corners[i], matrix_coefficients, distortion_coefficients)
    #        cv2.aruco.drawDetectedMarkers(frame, corners) 
    #        cv2.drawFrameAxes(frame, matrix_coefficients, distortion_coefficients, rvec, tvec, 1)
    return leninpix, leninpix_scalar, origin, len_of_aruco_in_pix, corners, origin_id

def check_if_ball_in_aruco(corners, xposinit, yposinit):
    y = True
    for i in range(len(corners)):
        if (corners[i][0][0][0] - 100) < xposinit < (corners[i][0][1][0] + 100) and (corners[i][0][1][1] - 100) < yposinit < (corners[i][0][2][1] + 100):
            y = False
    return y

if __name__ == '__main__':

    ap = argparse.ArgumentParser()
    ap.add_argument("-t", "--type", type=str, default="DICT_ARUCO_ORIGINAL", help="Type of ArUCo tag to detect")
    args = vars(ap.parse_args())

    
    if ARUCO_DICT.get(args["type"], None) is None:
        print(f"ArUCo tag type '{args['type']}' is not supported")
        sys.exit(0)

    aruco_dict_type = ARUCO_DICT[args["type"]]
    
    # accept manual selection of image file from user
    root = tk.Tk()
    root.withdraw()
    file_path = filedialog.askopenfilename()
    file_name = os.path.basename(file_path)
    file_name = file_name.strip()
    print(file_name)
    frame = cv2.imread(file_name)     # Taking image from file in the form of array

    ap = argparse.ArgumentParser()
    ap.add_argument("-a", "--alpha", type = float, default = 1, help = "< 1 to decrease contrast, > 1 to increase contrast")
    ap.add_argument("-b", "--beta", type = float, default = 1, help = "brightness [-127, 127]")
    args = vars(ap.parse_args())
    alpha = args['alpha']
    beta = args['beta']
    frame = cv2.convertScaleAbs(frame, alpha, beta)
    copy = frame

    leninpix, leninpix_scalar, origin, len_of_aruco_in_pix, corners, origin_id = pose_esitmation(frame, aruco_dict_type)

    len_of_aruco_in_metres = 0.3

    shape = frame.shape   # Dimensions of array
    for i in range(shape[0]):   # Turning image into black and white for better detection
        for j in range(shape[1]):
            if frame[i][j][0] > 150 and frame[i][j][1] > 150 and frame[i][j][2] > 150:
                frame[i][j][0] = 0
                frame[i][j][1] = 0
                frame[i][j][2] = 0
            else:
                frame[i][j][0] = 255
                frame[i][j][1] = 255
                frame[i][j][2] = 255
    ClassIndex, confidence, bbox = model.detect(frame, confThreshold = 0.1)   # Detecting bounding boxes
    
    x_positions = []      # Array where x coordinates are stored. 
    y_positions = []      # Array where y coordinates are stored. 
    positions = []
    font_scale = 3
    font = cv2.FONT_HERSHEY_PLAIN
    for ClassInd, conf, boxes in zip(ClassIndex.flatten(), confidence.flatten(), bbox):     # Drawing bounding boxes in image. Have commented the part where image is actually shown, as we don't need it.
        if len_of_aruco_in_pix*0.16 < boxes[2] < len_of_aruco_in_pix*0.4 and len_of_aruco_in_pix*0.16 < boxes[3] < len_of_aruco_in_pix*0.4:
            if ClassInd == 38 or ClassInd == 10:    # Condition for detected object to be ball. Dataset is a bit messed up, hence some jugaad. 
                y = 0
                for i in range(len(x_positions)):     # Model was detecting same balls multiple times, so I put this check in place. 
                    if abs(x_positions[i] - abs(((boxes[0] + boxes[2]/2) - origin[0]))) < 25 and abs(y_positions[i] - abs(((boxes[1] + boxes[3]/2) - origin[1]))) < 25:
                        y = 1
                if y == 0:
                    xposinit = (boxes[0] + boxes[2]/2)
                    yposinit = (boxes[1] + boxes[3]/2)
                    xpos = abs((boxes[0] + boxes[2]/2) - origin[0])
                    ypos = abs((boxes[1] + boxes[3]/2) - origin[1])
                    if check_if_ball_in_aruco(corners, xposinit, yposinit):
                        cv2.rectangle(copy, boxes, (255, 0, 0), 2)
                        cv2.putText(copy, 'Ball', (boxes[0]+10, boxes[1]+40), font, fontScale=font_scale, color=(0, 255, 0), thickness=3)
                        x_positions.append(xpos)     # Appending coordinates to array. 
                        y_positions.append(ypos)
                        ball_vec = [xpos, ypos]
                        dot_product = xpos*leninpix[0] + ypos*leninpix[1]
                        mods = math.sqrt(xpos*xpos + ypos*ypos)*math.sqrt(leninpix[0]*leninpix[0] + leninpix[1]*leninpix[1])
                        cos = dot_product/mods
                        angle = math.acos(cos)
                        r = math.sqrt(xpos*xpos + ypos*ypos)
                        xpos = r*math.cos(angle)
                        ypos = r*math.sin(angle)
                        positions.append(round((xpos*len_of_aruco_in_metres/len_of_aruco_in_pix), 2))
                        positions.append(round((ypos*len_of_aruco_in_metres/len_of_aruco_in_pix), 2))

    plt.imshow(copy)
    plt.show()
    positions = np.asarray(positions)
    
    length = leninpix_scalar*len_of_aruco_in_metres/len_of_aruco_in_pix
    n = 1
    q = int(origin_id/n)
    if origin_id/n - q > 0:
        pass
    else:
        q -= 1
    
    y_transform = q*length
    r = (q + 1)*n - origin_id
    x_transform = r*length
    for i in range(len(positions)):
        if i % 2 == 0:
            positions[i] = round((positions[i] + x_transform), 2)
        elif i % 2 == 1:
            positions[i] = round((positions[i] + y_transform), 2)
    id_string = str(origin_id)
    # positions.tofile(id_string + '.csv', sep = ',')
    file = open(id_string + '.csv', 'r+')
    for i in range(len(x_positions)):
        file.write('{}'.format(positions[2*i]))
        file.write(',')
        file.write('{}'.format(positions[2*i + 1]))
        file.write('\n')
    file.close()
    print(positions)
    print("No. of balls: ", len(x_positions))

    cv2.waitKey(0)
    cv2.destroyAllWindows()
