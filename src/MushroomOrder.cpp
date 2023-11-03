#include "MushroomOrder.h"

MushroomOrder::MushroomOrder()
{
    price = 18.00;
    add(this);
}

MushroomOrder::~MushroomOrder()
{
    
}

std::string MushroomOrder::toString()
{
    if (this != nullptr)
        return "MUSHROOM";

    return "";
}

double MushroomOrder::getPrice()
{
    return price;
}
