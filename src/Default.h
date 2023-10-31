#ifndef DEFAULT_H
#define DEFAULT_H
#include "State.h"

class State;
class Default : public State {
    public:
        Default();
        ~Default();
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