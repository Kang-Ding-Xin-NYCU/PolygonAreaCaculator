import pytest
import polygon

def test_creation():
    vertice = [[0, 0], [4, 0], [4, 4], [0, 4]]
    polygon_a = polygon.polygon(vertice)
    assert (polygon_a.area() == 16.)