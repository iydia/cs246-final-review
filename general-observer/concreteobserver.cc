#include "concreteobserver.h"

void ConcreteObserver::notify() const {
    int n = subject->getState();
    // do something
}
