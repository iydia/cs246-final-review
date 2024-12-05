#include "Pizza.h"
#include "Decorator.h"
#include "CrustAndSauce.h"
#include "Topping.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    Pizza* p = new CrustAndSauce();

    p = new Topping(" onions ", p);
    p = new Topping(" anchovies ", p);

    cout << p << endl;
}
