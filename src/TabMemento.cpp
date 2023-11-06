#include "TabMemento.h"

void TabMemento::setTabID(int tabID) { this->tabID = tabID; }

int TabMemento::getTabID() { return this->tabID; }

void TabMemento::setTotalPrice(float totalPrice) {
  this->totalPrice = totalPrice;
}

float TabMemento::getTotalPrice() { return this->totalPrice; }

void TabMemento::setItemCost(std::vector<float> itemCost) {
  this->itemCost = itemCost;
}

std::vector<float> TabMemento::getItemCost() { return this->itemCost; }

void TabMemento::setOrderedItems(std::vector<std::string> orderedItems) {
  this->orderedItems = orderedItems;
}

std::vector<std::string> TabMemento::getOrderedItems() {
  return this->orderedItems;
}
