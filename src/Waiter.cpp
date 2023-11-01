#include "Waiter.h"

Waiter::Waiter(ConcreteMediator *mediator)
{
    this->mediator = mediator;
}

void Waiter::WriteDownOrder(std::string order)
{
    this->mediator->notify(this,1,order);
}

void Waiter::CancelItem(std::string order)
{
    this->mediator->notify(this,2,order);
}

void Waiter::DoneOrder()
{
    this->mediator->NotifyDoneOrder(this);
}
