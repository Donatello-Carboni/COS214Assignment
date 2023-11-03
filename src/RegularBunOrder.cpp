#include "RegularBunOrder.h"

RegularBunOrder::RegularBunOrder()
{
    price = 15.00;
    add(this);
}

RegularBunOrder::~RegularBunOrder()
{
    
}

std::string RegularBunOrder::toString()
{
    if (this != nullptr)
        return "REGULAR_BUN";

    return "";
}

double RegularBunOrder::getPrice()
{
    return price;
}
