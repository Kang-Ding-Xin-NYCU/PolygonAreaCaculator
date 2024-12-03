CXX = g++
CXXFLAGS =  -O3 -Wall -shared -std=c++11 -fPIC $(shell python3 -m pybind11 --includes) $(shell python3-config --includes --ldflags)
TARGET = _polygon.so

default: $(TARGET)

$(TARGET): bind.cpp _polygon.cpp _polygon.hpp
	$(CXX) $(CXXFLAGS) _polygon.cpp bind.cpp -o $(TARGET)

test: $(TARGET)
	python -m pytest -v

_polygon.o: _polygon.cpp _polygon.hpp
	g++ -c _polygon.cpp -o _polygon.o

clean:
	rm -r __pycache__ test *.o *.so .pytest_cache