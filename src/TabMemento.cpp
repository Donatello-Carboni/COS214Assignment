#include "TabMemento.h"

void TabMemento::setTabID(int tabID) { this->tabID = tabID; }

int TabMemento::getTabID() { return this->tabID; }

void TabMemento::setTotalPrice(float totalPrice) {
  this->totalPrice = totalPrice;
}

float TabMemento::getTotalPrice() { return this->totalPrice; }

void TabMemento::setOrderedItems(
    const std::vector<BurgerOrder*>& orderedItems) {
  this->orderedItems = orderedItems;
}

std::vector<BurgerOrder*> TabMemento::getOrderedItems() {
  return this->orderedItems;
}
