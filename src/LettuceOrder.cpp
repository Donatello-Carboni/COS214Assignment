#include "LettuceOrder.h"

LettuceOrder::LettuceOrder()
{
    price = 8.00;
    add(this);
}

LettuceOrder::~LettuceOrder()
{
    
}

std::string LettuceOrder::toString()
{
    if (this != nullptr)
        return "LETTUCE";
 
    return "";
}

double LettuceOrder::getPrice()
{
    return price;
}
