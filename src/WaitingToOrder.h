#ifndef WAITINGTOORDER_H
#define WAITINGTOORDER_H
#include "State.h"

class State;
class WaitingToOrder : public State {
    public:
        WaitingToOrder();
        ~WaitingToOrder();
        void chooseItems(Customer*);
        void callToOrder(Customer*);
        void idle(Customer*);
        void callForBill(Customer*);
        void payBill(Customer*);
        void review(Customer*);
        void changeHappiness(Customer*);
        string toString();
};

#endif