#ifndef TOPPING_H
#define TOPPING_H

#include "Decorator.h"

#include <iostream>
#include <string>

using namespace std;

// Topping inherits from the Decorator base class
class Topping : public Decorator {
    string toppingName;
    public:
        Topping(string toppingName, Pizza* p);

        float pizzaPrice() const override;
        string pizzaDesc() const override;
};

#endif
