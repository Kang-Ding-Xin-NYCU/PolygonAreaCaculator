CXX = g++
CXXFLAGS =  -O3 -Wall -shared -std=c++11 -fPIC $(shell python3 -m pybind11 --includes) $(shell python3-config --includes --ldflags)
TARGET = _polygon.so

default: $(TARGET)

$(TARGET): bind.cpp _polygon.cpp _polygon.hpp
	$(CXX) $(CXXFLAGS) _polygon.cpp bind.cpp -o $(TARGET)

test: test

test: _polygon.o test.o
	g++ _polygon.o test.o -o test

_polygon.o: _polygon.cpp _polygon.hpp
	g++ -c _polygon.cpp -o _polygon.o

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -r __pycache__ test *.o *.so 