#include "CreateOrder.h"

void CreateOrder::execute() {
  // Create burger order
   if (this->orders.at(0) == "RegularBun") {
    this->burgerorder = new RegularBunOrder();
  } else {
    this->burgerorder = new GlutenFreeBunOrder();
  }
  // Add toppings
  for(int i=1;i<this->orders.size();i++){
    if (this->orders.at(i) == "Cheese") {
      this->burgerorder->add(new CheeseOrder());
    } else if (this->orders.at(i) == "Patty") {
      this->burgerorder->add(new CheeseOrder());
    }
  }
};

void CreateOrder::AddOrder(std::string order) {
  this->orders.push_back(order);
  return;
};

void CreateOrder::RemoveOrder(std::string order) {
  // Look for order in orders
  // If found, remove it
  for (auto it = this->orders.rbegin(); it != this->orders.rend(); ++it) {
    if (*it == order) {
      this->orders.erase(std::next(it).base());
      break;
    }
  }
}

std::vector<std::string> CreateOrder::getOrders() { return this->orders; }
CreateOrder::CreateOrder() {
  this->burgerorder = nullptr;
  this->orders = std::vector<std::string>();
}
