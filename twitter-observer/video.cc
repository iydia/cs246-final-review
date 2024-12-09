import <vector>;
import <string>;
using namespace std;

class Subject {
    vector<Observer*> observers; // or: vector<shared_ptr Observers> observers.
    public:
        virtual ~Subject = 0;
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

class Observer {
    public:
        virtual void notify() = 0; // abstract class
};

class Video : public Subject {
    string title;
    int length;
    string notification;
    public: 
        Video(string title, int length) : title{title}, length{length}, notification{notification} {}
        string getState() {
            return notification; // informs the user a video has been released
        }
};

class Viewer : public Observer {
    Video* video;
    public:
        Viewer(Video* video) : video{video} {
            video->attach(this); // watching this video i guess
        }
        ~Viewer() {
            video->detach(this);
        }
        void notify() { // tells iteself how to notify itself
            string notif = video->getState();
            // if notif contains cooking video, watch the video.
        }
};

