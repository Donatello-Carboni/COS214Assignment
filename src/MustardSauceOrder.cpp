#include "MustardSauceOrder.h"

MustardSauceOrder::MustardSauceOrder()
{
    price = 8.00;
    add(this);
}

MustardSauceOrder::~MustardSauceOrder()
{
    
}

std::string MustardSauceOrder::toString()
{
    if (this != nullptr)
        return "MUSTARD_SAUCE";

    return "";
}

double MustardSauceOrder::getPrice()
{
    return price;
}
