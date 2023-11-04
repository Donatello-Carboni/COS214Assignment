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
    if (this != nullptr)
        return "TOMATO_SAUCE";

    return "";
}

double TomatoSauceOrder::getPrice()
{
    return price;
}