#ifndef TABMEMENTO_H
#define TABMEMENTO_H
#include <string>
#include <vector>

#include "BurgerOrder.h"

class TabMemento {
 private:
  int tabID;
  float totalPrice;
  std::vector<BurgerOrder*> orderedItems;  // Change to pointer

 public:
  TabMemento() {
    tabID = 0;
    totalPrice = 0;
  };

  void setTabID(int tabID);

  int getTabID();

  void setTotalPrice(float totalPrice);

  float getTotalPrice();

  void setOrderedItems(
      const std::vector<BurgerOrder*>& orderedItems);  // Pass by pointer

  std::vector<BurgerOrder*> getOrderedItems();  // Change to pointer
};

#endif
