#ifndef CS_H
#define CS_H

#include "subject.h"

using namespace std;

class ConcreteSubject : Subject {
    int state;
    public:
        void notifyObservers();
        void attach(Observer* o);
        void detach(Observer* o);
        int getState();
        void setState(int newState);
};

#endif

