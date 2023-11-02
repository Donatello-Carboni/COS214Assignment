#ifndef CREATEORDER_H
#define CREATEORDER_H
#include "Command.h"
class CreateOrder : public Command {
 private:
 public:
  Burger *burger;
  CreateOrder();
  ~CreateOrder();
  void execute();
  void AddOrder(std::string order);
  void RemoveOrder(std::string order);
};
#endif