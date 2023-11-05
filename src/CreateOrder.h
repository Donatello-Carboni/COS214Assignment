#ifndef CREATEORDER_H
#define CREATEORDER_H
#include "Command.h"
#include <vector>
#include <string>
#include"BurgerOrder.h"
#include"BurgerBunOrder.h"
#include"RegularBunOrder.h"
#include"GlutenFreeBunOrder.h"
#include"BurgerToppingOrder.h"
#include"CheeseOrder.h"
#include"PattyOrder.h"
#include"TomatoSauceOrder.h"
#include"MustardSauceOrder.h"
#include"LettuceOrder.h"
#include"OnionSliceOrder.h"
#include"MushroomOrder.h"
#include"GherkinOrder.h"
class CreateOrder : public Command {
 private:
  std::vector<std::string> orders;
  BurgerOrder *burgerorder;
 public:
  CreateOrder();
  ~CreateOrder();
  void execute();
  void AddOrder(std::string order);
  void RemoveOrder(std::string order);
  std::vector<std::string> getOrders();
  void deleteOrder();
};
#endif