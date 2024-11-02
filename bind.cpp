#include "_polygon.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

PYBIND11_MODULE(_polygon, m){
    pybind11::class_<polygon>(m, "polygon")
        .def(pybind11::init<std::vector<double>, std::vector<double>>())
        .def(pybind11::init<polygon const &>())
        .def("__setitem__", [](polygon &self, std::size_t i, double val) {
            self.x(i) = val;
        })
        .def("__getitem__", [](polygon &self, std::size_t i) {
            return self.x(i);
        })
        .def("__setitem__", [](polygon &self, std::size_t i, double val) {
            self.y(i) = val;
        })
        .def("__getitem__", [](polygon &self, std::size_t i) {
            return self.y(i);
        })
        .def("set_x", &polygon::set_x)
        .def("get_x", &polygon::get_x)
        .def("set_y", &polygon::set_y)
        .def("get_y", &polygon::get_y)
        .def("print", &polygon::print)
        .def("area", &polygon::area)
        .def_property_readonly("size", &polygon::size);
}