import shape;
import circle;
import <iostream>;

using namespace std;

int main() {
    circle c1(1.0f); // Use float literal for the radius
    cout << "Area: " << c1.getArea() << endl;
    cout << "Perimeter: " << c1.getPerimeter() << endl;
    return 0;
}
