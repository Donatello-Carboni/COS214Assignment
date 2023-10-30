#include "Tab.h"

TabMemento Tab::createMemento() {
  TabMemento memento = TabMemento();
  memento.setTabID(tabID);
  memento.setTotalPrice(totalPrice);
  memento.setItemCost(itemCost);
  memento.setOrderedItems(orderedItems);
  return memento;
}

void Tab::setMemento(TabMemento memento) {
  tabID = memento.getTabID();
  totalPrice = memento.getTotalPrice();
  itemCost = memento.getItemCost();
  orderedItems = memento.getOrderedItems();
}

void Tab::addOrderedItem(std::string orderedItem, float price) {
  orderedItems.push_back(orderedItem);
  itemCost.push_back(price);
  calculateTotalPrice();
}

void Tab::setTabID(int tabID) { this->tabID = tabID; }

int Tab::getTabID() { return this->tabID; }

void Tab::setTotalPrice(float totalPrice) { this->totalPrice = totalPrice; }

float Tab::getTotalPrice() { return this->totalPrice; }

void Tab::setItemCost(std::vector<float> itemCost) {
  this->itemCost = itemCost;
}

std::vector<float> Tab::getItemCost() { return this->itemCost; }

void Tab::setOrderedItems(std::vector<std::string> orderedItems) {
  this->orderedItems = orderedItems;
}

std::vector<std::string> Tab::getOrderedItems() { return this->orderedItems; }

float Tab::calculateTotalPrice() {
  totalPrice = 0;
  for (int i = 0; i < itemCost.size(); i++) {
    totalPrice += itemCost[i];
  }

  return totalPrice;
}

void Tab::printBill() {
  std::cout << "Tab ID: " << tabID << std::endl;
  for (int i = 0; i < orderedItems.size(); i++) {
    std::cout << orderedItems[i] << " - " << itemCost[i] << std::endl;
  }
  std::cout << "Total: " << calculateTotalPrice() << std::endl;
}
