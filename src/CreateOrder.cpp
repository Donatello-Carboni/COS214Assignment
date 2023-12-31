#include "CreateOrder.h"

#include <iostream>
void CreateOrder::execute()
{
  std::string read;
  if(Inspection==false){
    std::cout << yellow << bold << "|  + Order is being created"<< std::endl << "| " << reset;
    std::cin>>read;
  }
  if (this->orders.at(1) == "REGULAR_BUN")
  {
    this->burgerorder = new RegularBunOrder();
  }
  else
  {
    this->burgerorder = new GlutenFreeBunOrder();
  }

  for (int i = 1; i < this->orders.size(); i++)
  {
    if (this->orders.at(i) == "SLICE_OF_CHEESE")
    {
      this->burgerorder->add(new CheeseOrder());
    }
    else if (this->orders.at(i) == "PATTY")
    {
      this->burgerorder->add(new PattyOrder());
    }
    else if (this->orders.at(i) == "TOMATO_SAUCE")
    {

      this->burgerorder->add(new TomatoSauceOrder());
    }
    else if (this->orders.at(i) == "LETTUCE")
    {

      this->burgerorder->add(new LettuceOrder());
    }
    else if (this->orders.at(i) == "ONION_SLICE")
    {

      this->burgerorder->add(new OnionSliceOrder());
    }
    else if (this->orders.at(i) == "MUSHROOMS")
    {

      this->burgerorder->add(new MushroomOrder());
    }
    else if (this->orders.at(i) == "GHERKINS")
    {

      this->burgerorder->add(new GherkinOrder());
    }
    else if (this->orders.at(i) == "MUSTARD_SAUCE")
    {

      this->burgerorder->add(new MustardSauceOrder());
    }
  }
  burgerorder->inspected=true;
  this->orders.clear();
};

void CreateOrder::AddOrder(std::string order)
{
  this->orders.push_back(order);
  return;
};

void CreateOrder::RemoveOrder(std::string order)
{
  // Look for order in orders
  // If found, remove it
  for (auto it = this->orders.rbegin(); it != this->orders.rend(); ++it)
  {
    if (*it == order)
    {
      std::string read;
      if(Inspection==false){
        std::cout << yellow << bold << "|  - " << red << "Order Cancelation: " << white << order << std::endl;
        std::cout << yellow << "|  - " << red << "Cancel out of Order: " << white << order << std::endl << reset;
        std::cin>>read;
        this->Inspection = true;
      }else{
        std::cout << yellow << bold << "|  - " << red << "Cancel out of Order: "<< white << order << std::endl << reset;
      }
      this->orders.erase(std::next(it).base());
      break;
    }
  }
}

std::vector<std::string> CreateOrder::getOrders() { return this->orders; }

void CreateOrder::deleteOrder() { this->orders.clear(); }

BurgerOrder *CreateOrder::getBurgerOrder() { return this->burgerorder; }

CreateOrder::CreateOrder()
{
  this->burgerorder = nullptr;
  this->orders = std::vector<std::string>();
}
