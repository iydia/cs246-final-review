#include "subject.h"

Subject::Subject() {}
Subject::~Subject() {}

void Subject::add(Observer *o) {  // i.e. the attach() method
    /* ----- FILL IN ----- */    
    observers.emplace_back(o);
}

void Subject::drop(Observer *o) {  // i.e. the detach() method
    /* ----- FILL IN ----- */
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            break; // prevents iterator from doing weird shit
        }
    }
}

void Subject::notifyObservers() const {
    /* ----- FILL IN ----- */
    for (auto o : observers) {
        o->doHomework();
    }
}

