// Write a C++ program to implement a class called Circle that has private member variables for radius. 
// Include member functions to calculate the circle's area and circumference.

export module circle;

import shape;

using namespace std;

export class circle : public shape {
    float radius;
    public:
        circle(float radius);
        float getArea() const override;
        float getPerimeter() const override;
        ~circle();
};
