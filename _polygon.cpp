#include "_polygon.hpp"

polygon::polygon()
{

}

polygon::polygon(std::vector<std::vector<double>> input)
{
    vertices = input;
    num = vertices.size();
    calculate_area();
}

polygon::polygon(polygon const & other)
{
    this->vertices = other.get_vertices();
    num = vertices.size();
    calculate_area();
}

polygon::~polygon()
{
    vertices.clear();
}

polygon & polygon::operator=(polygon const & other)
{
    for(size_t i = 0; i < num; ++i)
    {
        vertices.at(i) = other(i);
    }
    num = vertices.size();
    return *this;
}

std::vector<double> const & polygon::operator() (std::size_t t) const
{
    if(t > vertices.size() - 1)
    {
        throw std::out_of_range("Line index out of range");
    }
    return vertices.at(t);
}

std::vector<double> & polygon::operator() (std::size_t t){
    if(t > vertices.size() - 1)
    {
        throw std::out_of_range("Line index out of range");
    }
    calculate_area();
    return vertices.at(t);
}

void polygon::set_vertices(std::vector<std::vector<double>> input)
{
    vertices = input;
    num = vertices.size();
    calculate_area();
    return;
}

std::vector<std::vector<double>> polygon::get_vertices() const
{
    return vertices;
}

double polygon::get_area() const
{
    return area;
}

void polygon::print_vertices()
{
    for(size_t i = 0; i < num; ++i)
    {
        std::cout << "(" << vertices[i][0] << "," << vertices[i][1] << ")";
    }
    std::cout << "\n" << num << "\n";
    return;
}

void polygon::print_area()
{
    std::cout << area << "\n";
    return;
}

void polygon::calculate_area()
{
    double sum = 0;
    for(size_t i = 0; i <= num; ++i)
    {
        sum += vertices[i % num][0] * vertices[(i + 1) % num][1] - vertices[(i + 1) % num][0] * vertices[i % num][1];
    }
    area = sum/2;
    return;
}

size_t polygon::size()
{
    return int(num);
}