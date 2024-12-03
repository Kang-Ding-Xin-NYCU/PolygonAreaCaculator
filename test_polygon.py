import pytest
import polygon

def test_creation():
    vertice = [[0, 0], [4, 0], [4, 4], [0, 4]]
    polygon_a = polygon.polygon(vertice)
    assert (polygon_a.area() == 16.)
    polygon_a[1] = [2, 0]
    assert polygon_a.area() == 12.0