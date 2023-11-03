#include "CreateOrder.h"

void CreateOrder::execute() {
// Create burger order
// "RegularBunOrder.h"
//"GlutenFreeBunOrder.h"
   if (this->orders.at(1) == "RegularBun") {
    this->burgerorder = new RegularBunOrder();
  } else {
    this->burgerorder = new GlutenFreeBunOrder();
  }
// Add toppings
// "CheeseOrder.h"
// "PattyOrder.h"
// "TomatoSauceOrder.h"
// "MustardSauceOrder.h"
// "LettuceOrder.h"
// "OnionSliceOrder.h"
// "MushroomOrder.h"
// "GherkinOrder.h"
  for(int i=2;i<this->orders.size();i++){
    if (this->orders.at(i) == "Cheese") {
      this->burgerorder->add(new CheeseOrder());
    } else if (this->orders.at(i) == "Patty") {
      this->burgerorder->add(new CheeseOrder());
    }else if(this->orders.at(i) == "TomatoSauce"){
      this->burgerorder->add(new TomatoSauceOrder());
  }else if(this->orders.at(i) == "Lettuce"){
      this->burgerorder->add(new LettuceOrder());
  }
  else if(this->orders.at(i) == "OnionSlice"){
      this->burgerorder->add(new OnionSliceOrder());
  }
  else if(this->orders.at(i) == "Mushroom"){
      this->burgerorder->add(new MushroomOrder());
  }
  else if(this->orders.at(i) == "Gherkin"){
      this->burgerorder->add(new GherkinOrder());
  }else if(this->orders.at(i)== "MustardSauce"){
      this->burgerorder->add(new MustardSauceOrder());
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
