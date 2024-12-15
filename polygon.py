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
        islands = self.polygon.get_islands()
        if islands is None:
            return []
        return [polygon(island.get_vertices()) for island in islands]

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
        
        def draw(img, polygon_obj, color, height, level=0):
            print(f"Drawing level {level} polygon with vertices: {polygon_obj.get_vertices()} polygon with islands: {polygon_obj.get_islands()} ")
            points = np.array(flip(polygon_obj.get_vertices(), height), dtype=np.int32)
            points = points.reshape((-1, 1, 2))
            cv2.polylines(img, [points], True, color, 5)

            islands = polygon_obj.get_islands()
            print(f"islands name {islands}")
            if islands:
                for idx, island in enumerate(islands):
                    print(f"Drawing island {idx + 1} islands name {islands} at level {level + 1} island name {island}")
                    draw(img, island, (0, 255, 0), height, level+1)
    
        img = np.zeros((width, height, 3), dtype='uint8')
        draw(img, self, (0, 0, 255), height)  

        if not cv2.imwrite(filename, img):
            print(f"Failed to save image: {filename}")
        else:
            print(f"Image saved to: {filename}")