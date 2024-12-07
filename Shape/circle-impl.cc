module circle;

using namespace std;

const float pi = 3.141592f;

circle::circle(float radius) : radius{radius} {}

float circle::getArea() const {
    return pi * radius * radius;
}

float circle::getPerimeter() const {
    return 2 * pi * radius;
}

circle::~circle() {}
