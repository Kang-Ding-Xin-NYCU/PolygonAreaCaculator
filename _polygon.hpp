#include <vector>
#include <iostream>

#ifndef POLYGON
#define POLYGON

class polygon {
public:
    polygon();
    polygon(std::vector<std::vector<double>> input);
    polygon(polygon const & other);
    ~polygon();
    polygon & operator=(polygon const & );
    std::vector<double> const &      operator() (std::size_t it) const;
    std::vector<double>       &      operator() (std::size_t it);
    void                             set_vertices(std::vector<std::vector<double>> input);
    std::vector<std::vector<double>> get_vertices() const;
    double                           get_area()     const;
    void                             print_vertices();
    void                             print_area();
    void                             calculate_area();
    size_t                           size();

private:
    std::vector<std::vector<double>> vertices;
    std::size_t num;
    double area = 0;
};

#endif