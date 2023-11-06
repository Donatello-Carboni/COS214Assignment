#include "MushroomOrder.h"

MushroomOrder::MushroomOrder()
{
    price = 18.00;
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << "Adding Mushrooms to the order" << std::endl;
        std::cin>>read;
    }
    add(this);
}

MushroomOrder::~MushroomOrder()
{
    
}

std::string MushroomOrder::toString()
{
    if (this != nullptr)
        return "MUSHROOM";

    return "";
}

double MushroomOrder::getPrice()
{
    return price;
}
