#ifndef TAB_H
#define TAB_H
#include <iostream>
#include <string>
#include <vector>

#include "TabMemento.h"

class Tab {
 private:
  int tabID;
  float totalPrice;
  std::vector<float> itemCost;
  std::vector<std::string> orderedItems;

 public:
  TabMemento createMemento();

  void setMemento(TabMemento memento);

  void addOrderedItem(std::string orderedItem, float price);

  void setTabID(int tabID);

  int getTabID();

  void setTotalPrice(float totalPrice);

  float getTotalPrice();

  void setItemCost(std::vector<float> itemCost);

  std::vector<float> getItemCost();

  void setOrderedItems(std::vector<std::string> orderedItems);

  std::vector<std::string> getOrderedItems();

  float calculateTotalPrice();

  void printBill();
};

#endif
