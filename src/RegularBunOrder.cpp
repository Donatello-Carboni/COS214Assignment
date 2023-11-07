#include "RegularBunOrder.h"

RegularBunOrder::RegularBunOrder()
{
    price = 15.00;
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << yellow << bold << "|  + Adding " << white << "Regular Bun" << yellow << " to the order" << std::endl << "| " << reset;
        std::cin>>read;
    }
    add(this);
    // std::cout << "done creating burger bun" << std::endl;
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
