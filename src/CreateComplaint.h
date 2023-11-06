#ifndef CREATECOMPLAINT_H
#define CREATECOMPLAINT_H
#include "Command.h"
#include "BurgerOrder.h"
#include <vector>
#include <string>
class CreateComplaint : public Command {
 private:
  std::vector<std::string> complaint;
  BurgerOrder *burgerorder;
 public:
  CreateComplaint();
  ~CreateComplaint();
  void execute();
};
#endif