#include "Tab.h"

TabMemento Tab::createMemento() {
  TabMemento memento = TabMemento();
  memento.setTabID(tabID);
  memento.setTotalPrice(totalPrice);
  memento.setOrderedItems(orderedItems);  // Pass vector pointer

  return memento;
}

void Tab::setMemento(TabMemento& memento) {
  tabID = memento.getTabID();
  totalPrice = memento.getTotalPrice();
  orderedItems = memento.getOrderedItems();  // Copy vector pointer
}

void Tab::setTabID(int tabID) { this->tabID = tabID; }

int Tab::getTabID() { return this->tabID; }

void Tab::setTotalPrice(float totalPrice) { this->totalPrice = totalPrice; }

float Tab::getTotalPrice() { return this->totalPrice; }

void Tab::setOrderedItems(const std::vector<BurgerOrder*>& orderedItems) {
  this->orderedItems = orderedItems;
}

std::vector<BurgerOrder*> Tab::getOrderedItems() { return this->orderedItems; }

void Tab::addOrderedItem(BurgerOrder* orderedItem) {
  orderedItems.push_back(orderedItem);
  calculateTotalPrice();
}

float Tab::calculateTotalPrice() {
  float totalPrice = 0;
  // for (int i = 0; i < orderedItems.size(); i++) {
  //   BurgerOrder* curr = orderedItems[i];
  //   while (curr != NULL) {
  //     totalPrice += curr->getPrice();
  //     curr = curr->getNext();
  //   }
  // }
  setTotalPrice(totalPrice);
  return totalPrice;
}

void Tab::printBill() {
  std::cout << "Tab ID: " << tabID << std::endl;
  std::cout << "Total Price: " << totalPrice << std::endl;
  std::cout << "Ordered Items: " << std::endl;
  // for (int i = 0; i < orderedItems.size(); i++) {
  //   std::cout << "\t Item " << i + 1 << ": " << orderedItems[i]->toString()
  //             << std::endl;
  //   std::cout << "\t Price: " << orderedItems[i]->getPrice() << std::endl;
  // }
}
