#include <iostream>
#include <memory>

// Base character class
class Character {
public:
    virtual ~Character() = default;
    virtual void action() const = 0;
};

// Concrete Character class representing Kirby
class Kirby : public Character {
public:
    void action() const override {
        std::cout << "Kirby performs a basic action." << std::endl;
    }
};

// Base decorator class
class Decorator : public Character {
protected:
    std::shared_ptr<Character> character;

public:
    Decorator(std::shared_ptr<Character> c) : character(c) {}

    virtual void action() const override {
        character->action();
    }
};

// Fill in concrete decorator for Fire ability

// Fill in oncrete decorator for Ice ability

int main() {
    // Fill in with action() commands
}