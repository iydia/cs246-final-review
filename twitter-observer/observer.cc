import <vector>;
import <iostream>;
import <ifstream>;
import <string>;

using namespace std;

// ABstract Subject
class Subject {
    vector<Observer*> observers;
    public:
        virtual ~Subject() {}
        void notifyObservers() {
            for (auto obs : observers) {
                obs->notify();
            }
        }
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
};

// Abstract Observer
class Observer {

    public:
        virtual ~Observer() {}
        virtual void notify() = 0;
};

// Concrete Subject, the Tweeter, inherits from Subject
class Tweeter : public Subject {
    string tweet;
    ifstream file;
    public:
        Tweeter(string tweet, ifstream file) : tweet{tweet}, file{file} {}
        void notifyObservers() {}
        void attach(Observer* o) {}
        void detach(Observer* o) {}
        string getTweet() {
            return tweet;
        }
};

// Concrete Observer, the Follower, inherits from Observer
class Follower : public Observer {
    string name;
    Tweeter* iFollow;
    public:
        Follower(Tweeter* iFollow, string name) : iFollow{iFollow}, name{name} {
            iFollow->attach(this);
        }
        ~Follower() {
            iFollow->detach(this);
        }
        void notify() override {
            string tweet = iFollow->getTweet();
            // do something
        }
};
