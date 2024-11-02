#include "_polygon.hpp"

int main(){
    std::vector<double> a;
    std::vector<double> b;
    a.push_back(0);
    a.push_back(3);
    a.push_back(3);
    a.push_back(0);
    b.push_back(0);
    b.push_back(0);
    b.push_back(3);
    b.push_back(3);
    polygon A;
    A.set_x(a);
    A.set_y(b);
    A.print();
    polygon B = A;
    B.print();
    std::cout << A.area() << "\n";
    std::cout << B.area() << "\n"; 
    return 0;
}