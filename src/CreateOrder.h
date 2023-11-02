#ifndef CREATEORDER_H
#define CREATEORDER_H
#include "Command.h"
#include <vector>
#include <string>
class CreateOrder : public Command {
 private:
  std::vector<std::string> orders;
  Burger *burger;
 public:
  CreateOrder();
  ~CreateOrder();
  void execute();
  void AddOrder(std::string order);
  void RemoveOrder(std::string order);
  std::vector<std::string> getOrders();
};
#endif