#ifndef S_H
#define S_H

#include <vector> // for list of obseversre
#include "observer.h"

using namespace std;

class Subject {
    vector<Observer*> observers; // subject has a list of observers

    public:
        Subject();
        ~Subject();
        void notifyObservers();
        void attach(Observer* o);
        void detach(Observer* o);
};

#endif