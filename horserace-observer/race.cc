import <iostream>;
import <memory>;
import <vector>;
import <string>;

using namespace std;

// Abstract Observer
class Observer {
    public:
        virtual void notify() = 0; // abstract notify class
        virtual ~Observer() {} // abstrat virtual pure method public
};

// Abstract Subject
class Subject {
    vector<Observer*> observers;
    public:
        Subject(); // ctor
        virtual ~Subject() {} // for abstraction
        void attach(Observer* o) {
            observers.emplace_back(o);
        }
        void detach(Observer* o) {
            for (auto it = observers.begin(); it != observers.end(); ++it) {
                if (*it == o) {
                    observers.erase(it);
                }
            }
        }
        void notifyObservers() {
            for (auto obs : observers) {
                obs->notify();
            }
        }
};

// Concrete Observer, a Bettor
class Bettor : public Observer {
    HorseRace* subject;
    string name, myhorse;
    public:
    Bettor(HorseRace* subject, string name, string myhorse) : subject{subject}, name{name}, myhorse{myhorse} {
        subject->attach(this);
    }
        void notify() override {
            cout << "winnter" << endl;
        }
};

// Concrete Subject, a HorseRace 
class HorseRace : public Subject {
    Bettor* bettor;
    bool winState;
    public:
        HorseRace() {
            bettor->attach(this);
        }
        ~HorseRace() {
            bettor->detach(this);
        }
        bool getWinState() const {
            return true;
        }
};
