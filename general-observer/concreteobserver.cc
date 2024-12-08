#include "concreteobserver.h"

void ConcreteObserver::notify() const {
    int n = subject->getState();
    // do something
}

ConcreteObserver::ConcreteObserver(ConcreteSubject* s) {
    subject->attach(this); // subscribe
}

ConcreteObserver::~ConcreteObserver() {
    subject->detach(this);
}