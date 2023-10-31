#ifndef ABOUTTOLEAVE_H
#define ABOUTTOLEAVE_H
#include "State.h"


class State;
class AboutToLeave : public State {
    public:
        AboutToLeave();
        ~AboutToLeave();
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