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
  totalPrice = 0;
  for (int i = 0; i < orderedItems.size(); i++) {
    BurgerOrder* curr = orderedItems[i];
    while (curr != NULL) {
      totalPrice += curr->getPrice();
      curr = curr->getNext();
    }
  }
  setTotalPrice(totalPrice);
  return totalPrice;
}

void Tab::printBill() {
  std::cout << blue << bold << "Tab ID: " << white << tabID << std::endl;
  calculateTotalPrice();
  std::cout << yellow << bold << "|  + " << blue << "Total Price: " << white << totalPrice << std::endl;
  std::cout << yellow << bold << "|  + " << blue << "Ordered Items: " << std::endl;
  for (int i = 0; i < orderedItems.size(); i++) {
    BurgerOrder* curr = orderedItems[i];
    while (curr != NULL) {
      std::cout << cyan << "\t Item: " << white << curr->toString() << green <<"\t\t Price: " << white << "R"
                << curr->getPrice() << std::endl;
      curr = curr->getNext();
    }
  }
}