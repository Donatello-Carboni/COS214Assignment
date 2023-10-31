#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H
#include "KitchenMediator.h" // Mediator

class ConcreteMediator : public KitchenMediator
{
private:
    Colleague *colleague;
    Command *command;
public:
    ConcreteMediator();
    void notify(Colleague *colleague, int choice);
    void HandleCommand(int choice);
    void setColleague(Colleague *colleague);
    void setCommand(Command *command);
};

#endif