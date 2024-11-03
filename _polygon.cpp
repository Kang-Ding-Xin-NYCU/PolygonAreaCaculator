#include "_polygon.hpp"

polygon::polygon()
{

}

polygon::polygon(std::vector<std::vector<double>> input)
{
    data = input;
    num = data.size();
}

polygon::polygon(polygon const & other)
{
    this->data = other.get();
    num = data.size();
}

polygon::~polygon()
{
    data.clear();
}

polygon & polygon::operator=(polygon const & other){
    for(size_t i = 0; i < num; ++i){
        data[i] = other(i);
    }
    num = data.size();
    return *this;
}

std::vector<double> const & polygon::operator() (std::size_t t) const{
    if(t > data.size() - 1){
        throw std::out_of_range("Line index out of range");
    }
    return data[t];
}

std::vector<double> & polygon::operator() (std::size_t t){
    if(t > data.size() - 1){
        throw std::out_of_range("Line index out of range");
    }
    return data[t];
}

void polygon::set(std::vector<std::vector<double>> input)
{
    data = input;
    num = data.size();
}

std::vector<std::vector<double>> polygon::get() const
{
    return data;
}

void polygon::print()
{
    for(size_t i = 0; i < num; ++i)
    {
        std::cout << "(" << data[i][0] << "," << data[i][1] << ")";
    }
    std::cout << "\n" << num << "\n";
}

double polygon::area()
{
    double sum = 0;
    for(size_t i = 0; i <= num; ++i)
    {
        sum += data[i % num][0] * data[(i + 1) % num][1] - data[(i + 1) % num][0] * data[i % num][1];
    }
    return sum/2;
}

size_t polygon::size()
{
    return int(num);
}

