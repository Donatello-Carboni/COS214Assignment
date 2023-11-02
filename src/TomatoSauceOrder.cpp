#include "TomatoSauceOrder.h"

TomatoSauceOrder::TomatoSauceOrder()
{
    price = 12.00;
    add(this);
}

TomatoSauceOrder::~TomatoSauceOrder()
{
    
}

std::string TomatoSauceOrder::toString()
{
    return "TOMATO_SAUCE";
}

double TomatoSauceOrder::getPrice()
{
    return price;
}