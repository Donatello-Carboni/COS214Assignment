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
    if (this != nullptr)
        return "PATTY";

    return "";
}

double PattyOrder::getPrice()
{
    return price;
}
