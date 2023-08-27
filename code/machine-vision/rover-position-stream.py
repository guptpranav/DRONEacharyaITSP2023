import matplotlib.pyplot as plt
import cv2
import math
import argparse
import sys
import tkinter as tk
from tkinter import filedialog
import os
import requests
import numpy as np
import time
import imutils
from imutils.video import WebcamVideoStream

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

streamIP = 'http://192.168.167.241:4747/video?640x480'  # customize to your needs

def pose_esitmation(frame, aruco_dict_type):
    aruco_dict = cv2.aruco.getPredefinedDictionary(aruco_dict_type)
    parameters =  cv2.aruco.DetectorParameters()
    detector = cv2.aruco.ArucoDetector(aruco_dict, parameters)
    ids = []
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
            if ids[i] == 2:
                rover = (np.add(corners[i][0][0], corners[i][0][2]))/2

        leninpix = np.subtract(aruco2, origin)
        leninpix_scalar = math.sqrt((leninpix[0])*(leninpix[0]) + (leninpix[1])*(leninpix[1]))
    return rover, leninpix, leninpix_scalar, origin, len_of_aruco_in_pix, corners, origin_id

if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    ap.add_argument("-t", "--type", type=str, default="DICT_ARUCO_ORIGINAL", help="Type of ArUCo tag to detect")
    args = vars(ap.parse_args())

    if ARUCO_DICT.get(args["type"], None) is None:
        print(f"ArUCo tag type '{args['type']}' is not supported")
        sys.exit(0)

    aruco_dict_type = ARUCO_DICT[args["type"]]

    width=640
    height=480
    cap = cv2.VideoCapture(streamIP)
    while True:
            ret, frame = cap.read()
            copy = frame

            rover, leninpix, leninpix_scalar, origin, len_of_aruco_in_pix, corners, origin_id = pose_esitmation(frame, aruco_dict_type)
            len_of_aruco_in_metres = 0.185

            xpos = abs(rover[0] - origin[0])
            ypos = abs(rover[1] - origin[1])

            dot_product = abs(xpos*leninpix[0] + ypos*leninpix[1])
            mods = math.sqrt(xpos*xpos + ypos*ypos)*math.sqrt(leninpix[0]*leninpix[0] + leninpix[1]*leninpix[1])
            cos = dot_product/mods
            angle = math.acos(cos)
            r = math.sqrt(xpos*xpos + ypos*ypos)
            xpos_rot = r*math.cos(angle)
            ypos_rot = r*math.sin(angle)

            positions = []
            positions.append(round((xpos_rot*len_of_aruco_in_metres/len_of_aruco_in_pix), 2))
            positions.append(round((ypos_rot*len_of_aruco_in_metres/len_of_aruco_in_pix), 2))
            positions = np.asarray(positions)

            length = leninpix[0]*len_of_aruco_in_metres/len_of_aruco_in_pix
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

            positions.tofile('rover.csv', sep = ',')
            print(rover, leninpix, leninpix_scalar, origin, len_of_aruco_in_pix, corners, origin_id, positions)
            time.sleep(0.005)
