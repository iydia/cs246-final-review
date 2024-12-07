export module shape;

using namespace std;

// Abstract base class shape
export class shape {
    protected:
    float area;
    float perimeter;
    public:
        virtual float getArea() const = 0;
        virtual float getPerimeter() const = 0;
        virtual ~shape();
};
