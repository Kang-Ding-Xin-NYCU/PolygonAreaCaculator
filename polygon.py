import _polygon
import cv2
import numpy as np

class polygon:
    def __init__(self, vertice):
        self.polygon = _polygon.polygon(vertice)
    
    def __getitem__(self, index):
        return self.polygon.get_vertices()[index]

    def __setitem__(self, index, value):
        self.polygon[index] = value

    def set_vertices(self, vertice):
        self.polygon.set_vertices(vertice)

    def get_vertices(self):
        return self.polygon.get_vertices()
    
    def set_islands(self, island):
        if isinstance(island[0], list):
            island = [_polygon.polygon(pts) for pts in island]
        self.polygon.set_islands(island)

    def get_islands(self):
        return self.polygon.get_islands()

    def size(self):
        return self.polygon.size
    
    def area(self):
        return self.polygon.get_area()
    
    def plot(self):
        img = np.zeros((300,300,3), dtype='uint8')
        points = np.array(self.polygon.get_vertices(), dtype=np.int32)
        points = points.reshape((-1, 1, 2))
        cv2.polylines(img, [points], True, (0, 0, 255), 5)
        cv2.imshow('polygon', img)
        cv2.waitKey(0)
        cv2.destroyAllWindows()