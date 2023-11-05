#include "CreateOrder.h"
#include <iostream>
void CreateOrder::execute() {
this->burgerorder=nullptr;
for(int i=0;i<this->orders.size();i++){
  std::cout<<this->orders.at(i)<<std::endl;
}
// Create burger order
std::cout<<"creating burger bun"<<std::endl;
   if (this->orders.at(1) == "RegularBun") {
    this->burgerorder = new RegularBunOrder();
    std::cout<<"Done bun"<<std::endl;
  } else {
    this->burgerorder = new GlutenFreeBunOrder();
  }
 std::cout<<"done burger bun"<<std::endl;
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
  this->orders.clear();
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

void CreateOrder::deleteOrder()
{
  this->orders.clear();
}

BurgerOrder* CreateOrder::getBurgerOrder()
{
  return this->burgerorder;
}
CreateOrder::CreateOrder() {
  this->burgerorder = nullptr;
  this->orders = std::vector<std::string>();
}
