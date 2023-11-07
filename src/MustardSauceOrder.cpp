#include "MustardSauceOrder.h"

MustardSauceOrder::MustardSauceOrder()
{
    price = 8.00;
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << yellow << bold << "|  + Adding " << white << "Mustard" << yellow << " to the order" << std::endl << "| " << reset;
        std::cin>>read;
    }
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
