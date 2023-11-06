#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H
#include "KitchenMediator.h"  // Mediator
#include "Command.h"
#include "CreateOrder.h"
#include "CreateComplaint.h"
class ConcreteMediator : public KitchenMediator {
 private:
 public:
  ConcreteMediator(){};
  ConcreteMediator(Colleague *colleague[], Command *command[],Chef* chef)
      : KitchenMediator(colleague, command,chef){};
  void notify(Colleague *colleague, int choice, std::vector<std::string> order);
  void notifyOrder(Colleague *colleague, int choice, std::string order);
  void notifyDone(Colleague *colleague);
  void notifyReport(Colleague *colleague);
};

#endif