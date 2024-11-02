#include "_polygon.hpp"

polygon::polygon()
{

}

polygon::polygon(std::vector<double> in_x, std::vector<double> in_y)
{
    datax = in_x;
    datay = in_y;
    num = datax.size();
}

polygon::polygon(polygon const & other)
{
    this->datax = other.get_x();
    this->datay = other.get_y();
    num = datax.size();
}

polygon::~polygon()
{
    datax.clear();
    datay.clear();
}

polygon & polygon::operator=(polygon const & other){
    for(size_t i = 0; i < datax.size(); ++i){
        datax.push_back(other.x(i));
        datay.push_back(other.y(i));
    }
    num = datax.size();
    return *this;
}

double const & polygon::x(std::size_t t) const{
    if(t > datax.size() - 1){
        throw std::out_of_range("Line index out of range");
    }
    return datax[t];
}

double & polygon::x(std::size_t t){
    if(t > datax.size() - 1){
        throw std::out_of_range("Line index out of range");
    }
    return datax[t];
}

double const & polygon::y(std::size_t t) const{
    if(t > datay.size() - 1){
        throw std::out_of_range("Line index out of range");
    }
    return datay[t];
}

double & polygon::y(std::size_t t){
    if(t > datay.size() - 1){
        throw std::out_of_range("Line index out of range");
    }
    return datay[t];
}

void polygon::set_x(std::vector<double> in_x)
{
    datax = in_x;
    num = datax.size();
}

std::vector<double> polygon::get_x() const
{
    return datax;
}

void polygon::set_y(std::vector<double> in_y)
{
    datay = in_y;
    num = datax.size();
}

std::vector<double> polygon::get_y() const
{
    return datay;
}

void polygon::print()
{
    for(size_t i = 0; i < datax.size(); ++i)
    {
        std::cout << "(" << datax[i] << "," << datay[i] << ")";
    }
    std::cout << "\n" << num << "\n";
}

double polygon::area()
{
    double sum = 0;
    std::vector<double> areax = datax;
    std::vector<double> areay = datay;
    for(size_t i = 0; i <= datax.size(); ++i)
    {
        sum += datax[i] * datay[i + 1] - datax[i + 1] * datay[i];
    }
    return sum/2;
}

size_t polygon::size()
{
    return num;
}

