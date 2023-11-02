#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include "ConcreteMediator.h"
#include "Burger.h"

class Command {
 private:
  ConcreteMediator *mediator;
 public:
  Command(){};
  virtual void execute() = 0;
};
#endif