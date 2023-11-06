#include "PattyOrder.h"

PattyOrder::PattyOrder()
{
    price = 35.00;
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << "Adding Patty to the order" << std::endl;
        std::cin>>read;
    }
    add(this);
}

PattyOrder::~PattyOrder()
{
    
}

std::string PattyOrder::toString()
{
    if (this != nullptr)
        return "PATTY";

    return "";
}

double PattyOrder::getPrice()
{
    return price;
}
