#ifndef TABMEMENTO_H
#define TABMEMENTO_H
#include <string>
#include <vector>

class TabMemento {
 private:
  int tabID;
  float totalPrice;
  std::vector<float> itemCost;
  std::vector<std::string> orderedItems;

 public:
  void setTabID(int tabID);

  int getTabID();

  void setTotalPrice(float totalPrice);

  float getTotalPrice();

  void setItemCost(std::vector<float> itemCost);

  std::vector<float> getItemCost();

  void setOrderedItems(std::vector<std::string> orderedItems);

  std::vector<std::string> getOrderedItems();
};

#endif
