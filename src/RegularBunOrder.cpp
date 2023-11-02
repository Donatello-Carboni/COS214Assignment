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
    return "REGULAR_BUN";
}

double RegularBunOrder::getPrice()
{
    return price;
}
