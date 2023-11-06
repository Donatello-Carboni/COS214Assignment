#include "CheeseOrder.h"

CheeseOrder::CheeseOrder()
{
    price = 10.00;
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << "Adding Cheese to the order" << std::endl;
        std::cin>>read;
    }
    add(this);
}

CheeseOrder::~CheeseOrder()
{
    
}

std::string CheeseOrder::toString()
{
    if (this != nullptr)
        return "CHEESE_SLICE";

    return "";
}

double CheeseOrder::getPrice()
{
    return price;
}
