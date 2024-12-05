#ifndef CRUST_AND_SAUCE_H
#define CRUST_AND_SAUCE_H

#include "Pizza.h"
#include <iostream>
#include <string>

using namespace std;

class CrustAndSauce : public Pizza {
    // pizzaPrice in CrustAndSauce will override the Pizza price
    float pizzaPrice() const override;
    string pizzaDesc() const override;
};

#endif
