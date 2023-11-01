#ifndef TABLE_H
#define TABLE_H
#include "Observer.h"

class Table {
    private:
        Observer* myWaiter;
        bool isAvailable = true;
    public:
        Table();
        ~Table();
        void attach(Observer* waiter);
        void detach(Observer* waiter);
        void notify();
        bool getState();
        void setState(bool state);
};

#endif