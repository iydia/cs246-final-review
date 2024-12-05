#include "Topping.h"

using namespace std;

Topping::Topping(string toppingName, Pizza* p) : Decorator(p), toppingName{toppingName} {}

float Topping::pizzaPrice() const {
    return 0.99 + next->pizzaPrice(); // adds $0.99 to the price of the "next" pizza (which represents THE pizza)
}

string Topping::pizzaDesc() const {
    return next->pizzaDesc() + " and a topping " + toppingName;
}
