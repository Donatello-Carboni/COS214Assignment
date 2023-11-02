#include "PattyOrder.h"

PattyOrder::PattyOrder()
{
    price = 35.00;
    add(this);
}

PattyOrder::~PattyOrder()
{
    
}

std::string PattyOrder::toString()
{
    return "PATTY";
}

double PattyOrder::getPrice()
{
    return price;
}
