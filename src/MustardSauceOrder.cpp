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
    return "MUSTARD_SAUCE";
}

double MustardSauceOrder::getPrice()
{
    return price;
}
