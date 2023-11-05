#ifndef TAB_H
#define TAB_H
#include <iostream>
#include <string>
#include <vector>

#include "BurgerOrder.h"
#include "TabMemento.h"

class Tab {
 private:
  int tabID;
  float totalPrice;
  std::vector<BurgerOrder*> orderedItems;  // Change to pointer

 public:
  TabMemento createMemento();

  void setMemento(TabMemento& memento);  // Pass by const reference

  void setTabID(int tabID);

  int getTabID();

  void setTotalPrice(float totalPrice);

  float getTotalPrice();

  void setOrderedItems(
      const std::vector<BurgerOrder*>& orderedItems);  // Pass by pointer

  std::vector<BurgerOrder*> getOrderedItems();  // Change to pointer

  void addOrderedItem(BurgerOrder* orderedItem);

  float calculateTotalPrice();

  void printBill();
};

#endif
