#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H
#include "KitchenMediator.h"  // Mediator
#include "Command.h"
#include "CreateOrder.h"
class ConcreteMediator : public KitchenMediator {
 private:
 public:
  ConcreteMediator(){};
  ConcreteMediator(Colleague *colleague[], Command *command[])
      : KitchenMediator(colleague, command){};
  void notify(Colleague *colleague, int choice, std::vector<std::string> order);
  void notifyOrder(Colleague *colleague, int choice, std::string order);
  void notifyDone(Colleague *colleague);
  void HandleCommand(int choice);
};

#endif