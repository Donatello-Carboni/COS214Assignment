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
    if (this != nullptr)
        return "CHEESE_SLICE";

    return "";
}

double CheeseOrder::getPrice()
{
    return price;
}

BurgerOrder* CheeseOrder::getNext()
{
    return getNext();
}