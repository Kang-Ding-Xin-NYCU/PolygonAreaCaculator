import _polygon
import cv2
import numpy as np

class polygon:
    def __init__(self, vertice):
        self.polygon = _polygon.polygon(vertice)

    def input(self, vertice):
        self.polygon.set(vertice)

    def plot(self):
        img = np.zeros((300,300,3), dtype='uint8')
        points = np.array(self.polygon.get(), dtype=np.int32)
        points = points.reshape((-1, 1, 2))
        cv2.polylines(img, [points], True, (0, 0, 255), 5)
        cv2.imshow('polygon', img)
        cv2.waitKey(0)
        cv2.destroyAllWindows()

    def vertice(self):
        return self.polygon.get()

    def size(self):
        return self.polygon.size
    
    def area(self):
        return self.polygon.area()