#ifndef CO_H
#define CO_H

#include "observer.h"
#include "concretesubject.h"

class ConcreteObserver : public Observer {
    ConcreteSubject* subject; // the real observer (ie a youtube platform) has a pointer to the real observer (a viewer)
    // typically, a pointer field implies has-a ownership

    public:
        void notify() const override;
};

#endif
