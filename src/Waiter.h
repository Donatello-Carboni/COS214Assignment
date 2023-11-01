#ifndef WAITER_H
#define WAITER_H
#include <vector>
#include <string>
#include "ConcreteMediator.h"

class Waiter: public Colleague{
    private:
     //Mediator
     ConcreteMediator *mediator;
    
    public:
        Waiter(ConcreteMediator *mediator);
        void WriteDownOrder(std::string order);
        void CancelItem(std::string order);
        void DoneOrder();
};

#endif
