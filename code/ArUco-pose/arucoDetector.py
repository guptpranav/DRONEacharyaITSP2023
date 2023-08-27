import numpy as np
import cv2 as cv 
from cv2 import aruco

cam = cv.VideoCapture(0)

while True:
    ret, frame = cam.read()

    #grayscale conversion
    gray = cv.cvtColor(frame,cv.COLOR_BGR2GRAY)

    aruco_dict = aruco.Dictionary_get(aruco.DICT_4X4_100)
    parameters = aruco.DetectorParameters_create()
    corners, ids, rejectedPoints = aruco.detectMarkers(gray, aruco_dict, parameters = parameters)
    frame_markers = aruco.drawDetectedMarkers(frame.copy(),corners, ids)

    cv.imshow('frame_marker',frame_markers)
      
    k = cv.waitKey(1)

    if(k%256 == 27):
        print("Escape hit, closing the app")
        break

cam.release()
cam.destroyAllWindows()