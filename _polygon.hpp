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
    std::vector<double> const & operator() (std::size_t it) const;
    std::vector<double>       & operator() (std::size_t it);
    void                set(std::vector<std::vector<double>> input);
    std::vector<std::vector<double>> get() const;
    void                print();
    double              area();
    size_t              size();

private:
    std::vector<std::vector<double>> data;
    std::size_t num;
};

#endif