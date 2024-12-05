#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>

using namespace std;

class Pizza {
    private:
        float price;
        string desc;
    protected:

    public:
        // Ctor
        Pizza();
        Pizza(float price, string desc);

        // Virtual Dtor
        virtual ~Pizza();

        virtual string pizzaDesc() const = 0;
        virtual float pizzaPrice() const = 0;
};

ostream& operator<<(ostream& out, Pizza& p) {
    out << "The Pizza consists of " << p.pizzaDesc() << " and costs $" << p.pizzaPrice() << endl;
    return out;
}

#endif
