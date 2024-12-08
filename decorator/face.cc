#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Abstract class Face has functions speak() and desc()
class Face {
    string looks;
    public:
        virtual string desc() const = 0;
        virtual ~Face() {}
};

// Concrete class EyesNoseLips is the ConcreteComponent
class EyesNoseLips : public Face {

    public:
        string desc() const override {
            return "This one has eyes, nose, and lips of course.";
        }
};

// Decorator class
class Decorator : public Face {
    shared_ptr<Face> face;
    public:
        Decorator(shared_ptr<Face> face) : face{face} {}
        string desc() const override {
            return face->desc(); // Delegate to the wrapped object's desc()
        }
};

// ConcreteDecoratorA
class Glasses : public Decorator {
    string frames;
    public:
        Glasses(string frames, shared_ptr<Face> face) : Decorator(face), frames{frames} {}
        string desc() const override {
            Decorator::desc();
            return Decorator::desc() + " and glasses with frames of type " + frames + ".";
        }
};

// Wish me the best.
int main() {
    shared_ptr<Face> someone = make_shared<EyesNoseLips>();
    cout << someone->desc() << endl; // Output description of basic Face
    shared_ptr<Face> someoneWithGlasses = make_shared<Glasses>("sunglasses", someone);
    cout << someoneWithGlasses->desc() << endl; // Output description of basic Face
}
