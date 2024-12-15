CXX = g++
CXXFLAGS =  -O3 -Wall -shared -std=c++17 -fPIC $(shell python3 -m pybind11 --includes) $(shell python3-config --includes --ldflags)
TARGET = _polygon.so

default: $(TARGET)

$(TARGET): src/bind.cpp src/_polygon.cpp include/_polygon.hpp
	$(CXX) $(CXXFLAGS) src/_polygon.cpp src/bind.cpp -I include -o $(TARGET)

test: $(TARGET)
	python -m pytest -v

_polygon.o: src/_polygon.cpp include/_polygon.hpp
	g++ -c src/_polygon.cpp -I include -o _polygon.o

clean:
	rm -r __pycache__ test *.o *.so .pytest_cache