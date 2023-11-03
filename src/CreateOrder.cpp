#include "CreateOrder.h"

void CreateOrder::execute() { 
  
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
CreateOrder::CreateOrder()
{
  this->burger = new Burger();
  this->orders = std::vector<std::string>();
}
