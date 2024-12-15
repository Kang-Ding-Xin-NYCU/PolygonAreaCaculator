#include <vector>
#include <iostream>
#include <optional>

#ifndef POLYGON
#define POLYGON

class polygon {
public:
    polygon();
    polygon(std::vector<std::vector<double>> input);
    polygon(const polygon& other);
    ~polygon();
    polygon & operator=(const polygon& other);
    std::vector<double> const &         operator() (std::size_t it) const;
    std::vector<double>       &         operator() (std::size_t it);
    void                                set_vertices(std::vector<std::vector<double>> input);
    std::vector<std::vector<double>>    get_vertices()    const;
    void                                set_islands(std::vector<polygon> input);
    std::optional<std::vector<polygon>> get_islands()     const;
    double                              get_area()        const;
    void                                print_vertices()  const;
    void                                print_area()      const;
    void                                calculate_area();
    size_t                              size();

private:
    std::vector<std::vector<double>> vertices;
    std::size_t num;
    double area = 0;
    std::optional<std::vector<polygon>> islands;
};

#endif