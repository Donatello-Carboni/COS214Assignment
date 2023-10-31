#ifndef WAITINGTOSIT_H
#define WAITINGTOSIT_H
#include "State.h"

class State;
class WaitingToSit : public State {
    public:
        WaitingToSit();
        ~WaitingToSit();
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