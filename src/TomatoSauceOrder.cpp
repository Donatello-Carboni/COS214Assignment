#include "TomatoSauceOrder.h"

TomatoSauceOrder::TomatoSauceOrder()
{
    price = 12.00;
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << "Adding Tomatoe Sauce to the order" << std::endl;
        std::cin>>read;
    }
    add(this);
}

TomatoSauceOrder::~TomatoSauceOrder()
{
    
}

std::string TomatoSauceOrder::toString()
{
    if (this != nullptr)
        return "TOMATO_SAUCE";

    return "";
}

double TomatoSauceOrder::getPrice()
{
    return price;
}