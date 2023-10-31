#ifndef KITCHENMEDIATOR_H
#define KITCHENMEDIATOR_H
#include "Colleague.h"
#include "Command.h"
class KitchenMediator {
 private:
 //Collection of colleagues
    Colleague *colleague[2];
    Command *command[2];

 public:
    KitchenMediator(Colleague *colleague[], Command *command[]);
    void notify(Colleague *colleague, int choice);
};
#endif