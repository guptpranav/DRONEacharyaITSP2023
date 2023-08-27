import cv2, time, os, tensorflow as tf
import numpy as np
import math
import matplotlib.pyplot as plt

from tensorflow.python.keras.utils.data_utils import get_file

np.random.seed(123)

class Detector:
    def __init__(self):
        pass

    def readClasses(self, classesFilePath):
        with open(classesFilePath, 'r') as f:
            self.classesList = f.read().splitlines()
        
    def downloadModel(self, modelURL):
        fileName = os.path.basename(modelURL)
        self.modelName = fileName[:fileName.index('.')]
        
        self.cacheDir = './pretrained_models'

        os.makedirs(self.cacheDir, exist_ok = True)
        
        get_file(fname = fileName, origin = modelURL, cache_dir = self.cacheDir, cache_subdir = 'checkpoints', extract = True)

    def loadModel(self):
        print('Loading model ' + self.modelName)
        tf.keras.backend.clear_session()
        self.model = tf.saved_model.load(os.path.join(self.cacheDir, 'checkpoints', self.modelName, 'saved_model'))

        print('Model ' + self.modelName + ' loaded successfully...')

    def createBoundingBox(self, image, origin, leninpix, len_of_aruco_in_pix):
        inputTensor = cv2.cvtColor(image.copy(), cv2.COLOR_BGR2RGB)
        inputTensor = tf.convert_to_tensor(inputTensor, dtype = tf.uint8)
        inputTensor = inputTensor[tf.newaxis,...]

        detections = self.model(inputTensor)
        bboxs = detections['detection_boxes'][0].numpy()
        classIndexes = detections['detection_classes'][0].numpy().astype(np.int32)
        classScores = detections['detection_scores'][0].numpy()
        
        imH, imW, imC = image.shape
        len_of_aruco_in_metres = 0.3
        positions = []
        if len(bboxs) != 0:
            for i in range(0, len(bboxs)):
                bbox = tuple(bboxs[i].tolist())
                classConfidence = round(100*classScores[i])
                classIndex = classIndexes[i]
                classLabelText = self.classesList[classIndex]
                classScore = classScores[i]

                displayText = '{}: {}%'.format(classLabelText, classConfidence)
                ymin, xmin, ymax, xmax = bbox
                xmin, xmax, ymin, ymax = (xmin*imW, xmax*imW, ymin*imH, ymax*imH)
                if classLabelText == 'sports ball' and classScore > 0.1:
                    cv2.rectangle(image, (int(xmin), int(ymin)), (int(xmax), int(ymax)), (255, 0, 0), 3)
                    cv2.putText(image, displayText, (int(xmin), int(ymin) - 10), cv2.FONT_HERSHEY_PLAIN, 1, (0, 255, 0), 1)
                    xpos = abs((xmin + xmax)/2 - origin[0])
                    ypos = abs((ymin + ymax)/2 - origin[1])
                    dot_product = xpos*leninpix[0] + ypos*leninpix[1]
                    mods = math.sqrt(xpos*xpos + ypos*ypos)*math.sqrt(leninpix[0]*leninpix[0] + leninpix[1]*leninpix[1])
                    cos = dot_product/mods
                    angle = math.acos(cos)
                    r = math.sqrt(xpos*xpos + ypos*ypos)
                    xpos = r*math.cos(angle)
                    ypos = r*math.sin(angle)
                    positions.append(xpos*len_of_aruco_in_metres/len_of_aruco_in_pix)
                    positions.append(ypos*len_of_aruco_in_metres/len_of_aruco_in_pix)
        return image, positions

    def predictImage(self, frame, origin, leninpix, len_of_aruco_in_pix, origin_id):
        # b = 1.25
        # frame = cv2.convertScaleAbs(frame, 1.5, b)
        shape = frame.shape   # Dimensions of array
        x = 200
        for i in range(shape[0]):   # Turning image into black and white for better detection
            for j in range(shape[1]):
                if frame[i][j][0] > x and frame[i][j][1] > x and frame[i][j][2] > x:
                    frame[i][j][0] = 0
                    frame[i][j][1] = 0
                    frame[i][j][2] = 0
                else:
                    frame[i][j][0] = 255
                    frame[i][j][1] = 255
                    frame[i][j][2] = 255
        bboxImage, positions = self.createBoundingBox(frame, origin, leninpix, len_of_aruco_in_pix)

        cv2.imshow('Result', bboxImage)
        print('No. of balls: ', len(positions)/2)
        
        len_of_aruco_in_metres = 0.3
        length = leninpix[0]*len_of_aruco_in_metres/len_of_aruco_in_pix
        positions = np.asarray(positions)
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
        
        print('Coordinates: ', positions)
        id_string = str(origin_id)
        positions.tofile(id_string + '.csv', sep = ',')
        cv2.waitKey(0)
        cv2.destroyAllWindows()