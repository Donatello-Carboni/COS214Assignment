#include "OnionSliceOrder.h"

OnionSliceOrder::OnionSliceOrder()
{
    price = 7.00;
    add(this);
}

OnionSliceOrder::~OnionSliceOrder()
{
    
}

std::string OnionSliceOrder::toString()
{
    return "ONION_SLICE";
}

double OnionSliceOrder::getPrice()
{
    return price;
}
