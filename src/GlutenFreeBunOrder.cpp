#include "GlutenFreeBunOrder.h"

GlutenFreeBunOrder::GlutenFreeBunOrder()
{
    price = 10.00;
    add(this);
}

GlutenFreeBunOrder::~GlutenFreeBunOrder()
{
    
}

std::string GlutenFreeBunOrder::toString()
{
    if (this != nullptr)
        return "GLUTEN_FREE_BUN";

    return "";
}

double GlutenFreeBunOrder::getPrice()
{
    return price;
}
