#include "_polygon.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

PYBIND11_MODULE(_polygon, m){
    pybind11::class_<polygon>(m, "polygon")
        .def(pybind11::init<std::vector<std::vector<double>>>())
        .def(pybind11::init<polygon const &>())
        .def("__setitem__", [](polygon &self, std::size_t i, std::vector<double> val) {
             if (i >= self.size()) {
                throw std::out_of_range("Index out of range");
            }
            self(i) = val;
            self.calculate_area();
        })
        .def("__getitem__", [](polygon &self, std::size_t i) {
            if (i >= self.size()) {
                throw std::out_of_range("Index out of range");
            }
            return self(i);
        })
        .def("set_vertices"  , &polygon::set_vertices)
        .def("get_vertices"  , &polygon::get_vertices)
        .def("set_islands"   , &polygon::set_islands)
        .def("get_islands"   , &polygon::get_islands)
        /*.def("get_islands", [](const polygon& self) -> std::optional<std::vector<polygon>> {
            return self.get_islands();
        }, pybind11::return_value_policy::reference)*/
        .def("get_area"      , &polygon::get_area)
        .def("print_vertices", &polygon::print_vertices)
        .def("print_area"    , &polygon::print_area)
        .def("calculate_area", &polygon::calculate_area)
        .def_property_readonly("size", &polygon::size);
}