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
    return "MUSHROOM";
}

double MushroomOrder::getPrice()
{
    return price;
}
