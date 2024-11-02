import _polygon
import cv2
import numpy as np

def plot(p):
    img = np.zeros((300,300,3), dtype='uint8')
    points = np.array(p.get(), dtype=np.int32)
    points = points.reshape((-1, 1, 2))
    cv2.polylines(img, [points], True, (0, 0, 255), 5)
    cv2.imshow('polygon', img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

def vertice(p):
    p.print()

def size(p):
    p.size()