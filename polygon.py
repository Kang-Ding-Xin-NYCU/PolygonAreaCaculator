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
        if isinstance(island[0], polygon):
            island = [i.polygon for i in island]
        elif isinstance(island[0], list):
            island = [_polygon.polygon(pts) for pts in island]
        self.polygon.set_islands(island)

    def get_islands(self):
        return self.polygon.get_islands()

    def size(self):
        return self.polygon.size
    
    def area(self):
        return self.polygon.get_area()
    
    def plot(self, filename, width, height):
        def flip(points, height):
            flipped = points.copy()
            for p in flipped:
                p[1] = height - p[1]
            return flipped
        
        def draw(img, polygon, color, height):
            points = np.array(flip(polygon.get_vertices(), height), dtype=np.int32)
            points = points.reshape((-1, 1, 2))
            cv2.polylines(img, [points], True, color, 5)
        
            if polygon.get_islands():
                for island in polygon.get_islands():
                    draw(img, island, (0, 255, 0), height)
    
        img = np.zeros((width, height, 3), dtype='uint8')
    
        draw(img, self.polygon, (0, 0, 255), height)  

        if not cv2.imwrite(filename, img):
            print(f"Failed to save image: {filename}")
        else:
            print(f"Image saved to: {filename}")