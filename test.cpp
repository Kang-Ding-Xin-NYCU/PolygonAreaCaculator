#include "_polygon.hpp"

int main(){
    std::vector<std::vector<double>> a;
    std::vector<double> b;
    b.resize(2);
    b[0] = 0; b[1] = 0;
    a.push_back(b);
    b[0] = 0; b[1] = 3;
    a.push_back(b);
    b[0] = 3; b[1] = 3;
    a.push_back(b);
    b[0] = 3; b[1] = 0;
    a.push_back(b);
    polygon A;
    A.polygon::set(a);
    A.polygon::print();
    polygon B = A;
    B.print();
    std::cout << A.area() << "\n";
    std::cout << B.area() << "\n";
     
    return 0;
}