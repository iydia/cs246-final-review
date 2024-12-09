import <memory>;
import <iostream>;
import <string>;

using namespace std;

// Abstract Component
class Character {

    public:
        virtual void attack() const = 0;
        virtual ~Character() = default;

};

// Concrete Component
class Kirby : public Character {

    public:
        virtual ~Kirby() {}
        void attack() const override {
            cout << "Pow" << endl;
        }
};

// Abstract Decorator
class Decorator : public Character {
    protected:
        shared_ptr<Character> character; // recall: the second half make_unique<Character>(...) is like the initaliziation. you only want int a;, not also int a = 5
    public:
        Decorator(shared_ptr<Character> character) : character{character} {}
        ~Decorator() {}
        virtual void attack() const override {
            character->attack(); // decorator must implement the call to attack
        }
};

// concrete DecoratorA, the Ice Kirby
class IceKirby : public Decorator {
    public:
        IceKirby();
        IceKirby(shared_ptr<Character> p) : Decorator(p) {

        }
        void attack() const override {
            // calls current attack, then ice attack
            Decorator::attack(); // if you want to use decorator attack, the decorator must have an attack dude...
            // we do it like this because our attack is void. otherwise, we would call the Pizza::desc(), remember? returns a string.
            cout << " with Ice! " << endl;
        }

};

// concrete DecoratorB, the Fire Kirby
class FireKirby : public Decorator {
    public:
        FireKirby(shared_ptr<Character> p) : Decorator(p) {

        }
        void attack() override {
            // calls current attack, then ice attack
            Decorator::attack();
            cout << " with Fire! " << endl;
        }
};


int main () {
    // Fill in with action() commands
    std::shared_ptr<Character> kirby = std::make_shared<FireKirby>();
    std::shared_ptr<Character> fireKirby = std::make_shared<FireKirby>(kirby);
    std::shared_ptr<Character> iceKirby = std::make_shared<IceKirby>(kirby);
    std::shared_ptr<Character> fireIceKirby = std::make_shared<IceKirby>(std::make_shared<FireKirby>(kirby)); // nested fire and ice kirby
    std::shared_ptr<Character> fireIceKirby2 = std::make_shared<IceKirby>(fireKirby); // nested fire and ice kirby
    kirby->action();
    fireKirby->action();
    iceKirby->action();
    fireIceKirby->action();
    fireIceKirby2->action();
    
}