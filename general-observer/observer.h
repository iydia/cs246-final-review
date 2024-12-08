#ifndef O_H
#define O_H

class Observer {
    public:
        virtual void notify() const = 0;
        virtual ~Observer();

        class Iterator {
            Observer *p;

            public:
                Iterator();
                Iterator(Observer* p);
                bool operator!=(const Iterator& other);
                Observer& operator*() const;
                void operator++();

            friend class Observer;
        };

        Iterator& begin();
        Iterator& end();
};

#endif