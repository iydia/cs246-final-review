#include "Pizza.h"

using namespace std;

// Ctor
Pizza::Pizza() : price{0}, desc{""} {}
Pizza::Pizza(float price, string desc) : price{price}, desc{desc} {}

// Dtor
Pizza::~Pizza() {}
