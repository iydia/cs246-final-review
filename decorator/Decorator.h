#ifndef DECO_H
#define DECO_H

#include <iostream>
#include <string>

#include "Pizza.h"

using namespace std;

// Decorator also inherits from Pizza
class Decorator : public Pizza {
    protected: 
        Pizza *next; // Decorator chains on a linked list of Pizzas in protected
    public:
        Decorator(Pizza* p);
        ~Decorator();
};

#endif
