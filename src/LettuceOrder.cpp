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
    return "LETTUCE";
}

double LettuceOrder::getPrice()
{
    return price;
}
