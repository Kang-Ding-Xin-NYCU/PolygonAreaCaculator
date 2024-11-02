#include "_polygon.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

PYBIND11_MODULE(_polygon, m){
    pybind11::class_<polygon>(m, "polygon")
        .def(pybind11::init<std::vector<std::vector<double>>>())
        .def(pybind11::init<polygon const &>())
        .def("__setitem__", [](polygon &self, std::size_t i, std::vector<double> val) {
            self(i) = val;
        })
        .def("__getitem__", [](polygon &self, std::size_t i) {
            return self(i);
        })
        .def("set_x", &polygon::set)
        .def("get_x", &polygon::get)
        .def("print", &polygon::print)
        .def("area", &polygon::area)
        .def_property_readonly("size", &polygon::size);
}