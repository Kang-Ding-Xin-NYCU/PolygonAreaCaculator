import pytest
import polygon

def test_creation():
    vertice = [[1, 1], [4, 1], [4, 4], [1, 4]]
    polygon_test = polygon.polygon(vertice)
    assert (polygon_test.area() == 9.)

def test_assign():
    vertice = [[1, 1], [4, 1], [4, 4], [1, 4]]
    polygon_test = polygon.polygon(vertice)
    assert (polygon_test.area() == 9.)
    polygon_test[1] = [2, 1]
    assert polygon_test.area() == 6.0

def test_islands():
    vertice = [[0, 0], [4, 0], [4, 4], [0, 4]]
    vertice1 = [[0, 0], [1, 0], [1, 1], [0, 1]]
    vertice2 = [[3, 3], [4, 3], [4, 4], [3, 4]]
    polygon_a = polygon.polygon(vertice1)
    polygon_b = polygon.polygon(vertice2)
    island = [polygon_a, polygon_b]
    polygon_test = polygon.polygon(vertice)
    polygon_test.set_islands(island)
    assert (polygon_test.area() == 14.)

def test_plot():
    vertice = [[100, 100], [400, 100], [400, 400], [100, 400]] 
    vertice1 = [[150, 150], [200, 150], [200, 200], [150, 200]] 
    vertice2 = [[200, 200], [350, 200], [350, 350], [200, 350]]
    vertice3 = [[325, 325], [345, 325], [345, 345], [325, 345]]
    vertice4 = [[330, 330], [340, 330], [340, 340], [330, 340]]
    polygon_a = polygon.polygon(vertice1)
    polygon_b = polygon.polygon(vertice2)
    polygon_c = polygon.polygon(vertice3)
    polygon_d = polygon.polygon(vertice4)

    polygon_b.set_islands([polygon_c, polygon_d])
    
    polygon_test = polygon.polygon(vertice)
    polygon_test.set_islands([polygon_a, polygon_b])

    
    savefile = "polygon.png"
    polygon_test.plot(savefile, 500, 500)

