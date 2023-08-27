from Detector import *
import tkinter as tk
from tkinter import filedialog
import os
import time
import cv2
import numpy as np
import sys
import math
import requests
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

def pose_estimation(frame, aruco_dict_type):
    # gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
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
        leninpix = np.subtract(aruco2, origin)
    return leninpix, origin, len_of_aruco_in_pix, origin_id



#modelURL = 'http://download.tensorflow.org/models/object_detection/tf2/20200711/efficientdet_d7_coco17_tpu-32.tar.gz'
#modelURL = 'http://download.tensorflow.org/models/object_detection/tf2/20200713/centernet_hg104_512x512_coco17_tpu-8.tar.gz'
#modelURL = 'http://download.tensorflow.org/models/object_detection/tf2/20200711/ssd_resnet101_v1_fpn_1024x1024_coco17_tpu-8.tar.gz'
#modelURL = 'http://download.tensorflow.org/models/object_detection/tf2/20200711/faster_rcnn_resnet152_v1_800x1333_coco17_gpu-8.tar.gz'
modelURL = 'http://download.tensorflow.org/models/object_detection/tf2/20200713/centernet_hg104_1024x1024_coco17_tpu-32.tar.gz'
classFile = 'coco.names'

detector = Detector()
detector.readClasses(classFile)
detector.downloadModel(modelURL)
detector.loadModel()

while True:
    f = open('bool.txt', 'r')
    boolean = f.read()
    f.close()
    if boolean == 'True':
        root = tk.Tk()  # Next 4 lines are for getting file. Have accepted input from user for now
        root.withdraw()
        file_path = filedialog.askopenfilename()
        file_name = os.path.basename(file_path)
        
        # r = requests.get('http://192.168.0.160:8080/snapshot')      # Sending http request to server to get image. 
        # with open('image.jpg', 'wb') as f:
        #     f.write(r.content)
        # file_name = 'image.jpg'
        file_name = file_name.strip()
        frame = cv2.imread(file_name)
        
        # cap = cv2.VideoCapture('http://192.168.111.15:8080/stream')
        # ret, frame = cap.read()
        leninpix, origin, len_of_aruco_in_pix, origin_id = pose_estimation(frame, ARUCO_DICT['DICT_ARUCO_ORIGINAL'])
    
        detector.predictImage(frame, origin, leninpix, len_of_aruco_in_pix, origin_id)
        text_file = open("bool.txt", "w")
        text_file.write('False')
        text_file.close()
    time.sleep(0.5)
