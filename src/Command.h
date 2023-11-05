#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include "Burger.h"
class Command {
 private:
 public:
  Command(){};
  virtual void execute() = 0;
};
#endif