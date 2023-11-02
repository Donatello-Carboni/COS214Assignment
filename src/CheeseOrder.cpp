#include "CheeseOrder.h"

CheeseOrder::CheeseOrder()
{
    price = 10.00;
    add(this);
}

CheeseOrder::~CheeseOrder()
{
    
}

std::string CheeseOrder::toString()
{
    return "CHEESE_SLICE";
}

double CheeseOrder::getPrice()
{
    return price;
}

