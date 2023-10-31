#ifndef STATE_H
#define STATE_H
#include "Customer.h"
#include <string>
#include <iostream>

using namespace std;

class Customer;
class State {
    public:
        State();
        virtual ~State();
        virtual void chooseItems(Customer*) =0;
        virtual void callToOrder(Customer*) =0;
        virtual void idle(Customer*) =0;
        virtual void callForBill(Customer*) =0;
        virtual void payBill(Customer*) =0;
        virtual void review(Customer*) =0;
        virtual void changeHappiness(Customer*) =0;
        virtual string toString() =0;
    private:
        Customer* customer;
};

#endif