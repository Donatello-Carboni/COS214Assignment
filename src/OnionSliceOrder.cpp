#include "OnionSliceOrder.h"

OnionSliceOrder::OnionSliceOrder()
{
    price = 7.00;
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << yellow << bold << "|  + Adding " << white << "Onions" << yellow << " to the order" << std::endl << "| " << reset;
        std::cin>>read;
    }
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
