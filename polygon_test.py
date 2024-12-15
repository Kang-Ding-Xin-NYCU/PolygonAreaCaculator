import pytest
import polygon

def test_creation_area_calculate():
    vertice = [[1, 1], [4, 1], [4, 4], [1, 4]]
    polygon_test = polygon.polygon(vertice)
    assert (polygon_test.area() == 9.)

def test_assign_area_calculate():
    vertice = [[1, 1], [4, 1], [4, 4], [1, 4]]
    polygon_test = polygon.polygon(vertice)
    assert (polygon_test.area() == 9.)
    polygon_test[1] = [2, 1]
    assert polygon_test.area() == 6.0

def test_area_calculate_1():
    vertice = [[1, 1], [4, 1], [4, 2], [2, 2], [2, 3], [4, 3], [4, 4], [1, 4]]
    polygon_test = polygon.polygon(vertice)
    assert (polygon_test.area() == 7.)

def test_area_calculate_2():
    vertice = [[1, 1], [4, 1], [4, 2], [5, 2], [5, 3], [4, 3], [4, 4], [1, 4]]
    polygon_test = polygon.polygon(vertice)
    assert (polygon_test.area() == 10.)

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
    vertice1 = [[150, 150], [250, 150], [250, 250], [150, 250]] 
    vertice2 = [[300, 300], [350, 300], [350, 350], [300, 350]] 
    
    polygon_test = polygon.polygon(vertice)
    polygon_test.set_islands([vertice1, vertice2])
    
    savefile = "polygon.png"
    polygon_test.plot(savefile, 500, 500)
    assert (polygon_test.area() == 77500.)

