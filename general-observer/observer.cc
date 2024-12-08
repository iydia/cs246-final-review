#include "observer.h"

Observer::~Observer() {}

Observer::Iterator::Iterator() : p{nullptr} {}

Observer::Iterator::Iterator(Observer* p) : p{p} {}

bool Observer::Iterator::operator!=(const Observer::Iterator& other) {
    return p != other.p;
}

Observer& Observer::Iterator::operator*() const {
    return *p;
}

void Observer::Iterator::operator++() {
 // idk man
}

/*
Observer::Iterator Observer::begin() {
    return Observer::Iterator(observers.data()); // Return an iterator pointing to the first element
}

Observer::Iterator Observer::end() {
    return Observer::Iterator(observers.data() + observers.size()); // Return an iterator pointing past the last element
}*/
