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
    return "GLUTEN_FREE_BUN";
}

double GlutenFreeBunOrder::getPrice()
{
    return price;
}
