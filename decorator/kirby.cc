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
class Fire : public Decorator {
    public:
    Fire(std::shared_ptr<Character> c) : Decorator{c} {}
    void action() const override {
        Decorator::action();
        std::cout << "Kirby uses Fire ability!" << std::endl;
    }
};

// Fill in concrete decorator for Ice ability
class Ice : public Decorator {
    public:
    Ice();
    Ice(std::shared_ptr<Character> c) : Decorator{c} {}
    void action() const override {
        Decorator::action();
        std::cout << "Kirby uses Ice ability!" << std::endl;
    }
};

int main() {
    // Fill in with action() commands
    std::shared_ptr<Character> kirby = std::make_shared<Kirby>();
    std::shared_ptr<Character> fireKirby = std::make_shared<Fire>(kirby);
    std::shared_ptr<Character> iceKirby = std::make_shared<Ice>(kirby);
    std::shared_ptr<Character> fireIceKirby = std::make_shared<Ice>(std::make_shared<Fire>(kirby)); // nested fire and ice kirby
    std::shared_ptr<Character> fireIceKirby2 = std::make_shared<Ice>(fireKirby); // nested fire and ice kirby
    kirby->action();
    fireKirby->action();
    iceKirby->action();
    fireIceKirby->action();
    fireIceKirby2->action();
}
