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
    if (this != nullptr)
        return "ONION_SLICE";

    return "";
}

double OnionSliceOrder::getPrice()
{
    return price;
}
