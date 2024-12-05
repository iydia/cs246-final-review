#include "Decorator.h"

// Constructor initializes pointer to new Pizza p and links it on the linked list.
Decorator::Decorator(Pizza* p) : next{p} {}

// Destructor destroys linked list of Pizzas
Decorator::~Decorator() {
    delete next;
}
