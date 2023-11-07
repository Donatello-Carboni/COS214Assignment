#include "LettuceOrder.h"

LettuceOrder::LettuceOrder()
{
    price = 8.00;
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << yellow << bold << "|  + Adding " << white << "Lettuce" << yellow << " to the order" << std::endl << "| " << reset;
        std::cin>>read;
    }
    add(this);
}

LettuceOrder::~LettuceOrder()
{
    
}

std::string LettuceOrder::toString()
{
    if (this != nullptr)
        return "LETTUCE";
 
    return "";
}

double LettuceOrder::getPrice()
{
    return price;
}
