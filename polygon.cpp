#include"polygon.hpp"
#include<iostream>

void polygon::input(std::queue<float> in_x, std::queue<float> in_y){
    x = in_x;
    y = in_y;
}

void polygon::print(){
    std::queue<float> printx = x;
    std::queue<float> printy = y;
    for(int i = 0; i < x.size(); i++){
        std::cout<<"("<< printx.front()<<","<<printy.front()<<")";
        printx.pop();
        printy.pop();
    }
    std::cout<<"\n";
}

float polygon::area(){
    float sum = 0;
    std::queue<float> areax = x;
    std::queue<float> areay = y;
    float x1, x2, y1, y2;
    x1 = areax.front(); areax.push(x1); areax.pop();
    y1 = areay.front(); areay.push(y1); areay.pop();
    for(int i = 0; i < x.size(); i++){
        x2 = areax.front(); areax.push(x2); areax.pop();
        y2 = areay.front(); areay.push(y2); areay.pop();
        sum += x1 * y2 - x2 * y1;
        x1 = x2;
        y1 = y2;
    }
    return sum/2;
}
