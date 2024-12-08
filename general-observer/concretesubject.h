#ifndef CS_H
#define CS_H

#include "subject.h"

using namespace std;

class ConcreteSubject : Subject {
    int state;
    public:
        int getState();
        void setState(int newState);
};

#endif

