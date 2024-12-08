#include "concretesubject.h"

using namespace std;


int ConcreteSubject::getState() {
    return state;
}

void ConcreteSubject::setState(int newState) {
    state = newState;
}
