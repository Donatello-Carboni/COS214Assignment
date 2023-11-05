#ifndef CREATEORDER_H
#define CREATEORDER_H
#include <string>
#include <vector>

#include "BurgerBunOrder.h"
#include "BurgerOrder.h"
#include "BurgerToppingOrder.h"
#include "CheeseOrder.h"
#include "Command.h"
#include "GherkinOrder.h"
#include "GlutenFreeBunOrder.h"
#include "LettuceOrder.h"
#include "MushroomOrder.h"
#include "MustardSauceOrder.h"
#include "OnionSliceOrder.h"
#include "PattyOrder.h"
#include "RegularBunOrder.h"
#include "TomatoSauceOrder.h"
class CreateOrder : public Command {
 private:
  std::vector<std::string> orders;
  BurgerOrder* burgerorder;

 public:
  CreateOrder();
  ~CreateOrder();
  void execute();
  void AddOrder(std::string order);
  void RemoveOrder(std::string order);
  std::vector<std::string> getOrders();
  void deleteOrder();
  BurgerOrder* getBurgerOrder();
};
#endif