#include<queue>

#ifndef POLYGON
#define POLYGON

class polygon {
public:
    void input(std::queue<float> in_x, std::queue<float> in_y);
    void print();
    float area();

private:
    std::queue<float> x, y;
};

#endif