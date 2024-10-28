#include <vector>
#include <iostream>

#ifndef POLYGON
#define POLYGON

class polygon {
public:
    polygon();
    polygon(std::vector<double> in_x, std::vector<double> in_y);
    ~polygon();
    polygon & operator=(polygon const & );
    double const & x(std::size_t it) const;
    double       & x(std::size_t it);
    double const & y(std::size_t it) const;
    double       & y(std::size_t it);
    void                set_x(std::vector<double> in_x);
    std::vector<double> get_x();
    void                set_y(std::vector<double> in_y);
    std::vector<double> get_y();
    void                print();
    double              area();

private:
    std::vector<double> datax, datay;
};

#endif