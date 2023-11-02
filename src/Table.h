#ifndef TABLE_H
#define TABLE_H


#include "Observer.h"
#include "Customer.h"
#include <vector>

class Table {
    private:
        Observer* myWaiter;
        bool isAvailable = true;
    public:
        Table();
        ~Table();
        virtual bool AddCustomer(Customer* customer) = 0;
        virtual bool RemoveCustomer(Customer* customer) = 0;
        void attach(Observer* waiter);
        void detach(Observer* waiter);
        void notify();
        bool getState();
        void setState(bool state);
};

#endif

