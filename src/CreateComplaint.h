#ifndef CREATECOMPLAINT_H
#define CREATECOMPLAINT_H
#include "Command.h"
#include <vector>
#include <string>
class CreateComplaint : public Command {
 private:
  std::vector<std::string> orders;
  Burger *burger;
 public:
  CreateComplaint();
  ~CreateComplaint();
  void execute();
};
#endif