#include "GlutenFreeBunOrder.h"

GlutenFreeBunOrder::GlutenFreeBunOrder()
{
    price = 10.00;
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << yellow << bold << "|  + Adding " << white << "Gluten Free Bun" << yellow << " to the order" << std::endl << "| " << reset;
        std::cin>>read;
    }
    add(this);
}

GlutenFreeBunOrder::~GlutenFreeBunOrder()
{
    
}

std::string GlutenFreeBunOrder::toString()
{
    if (this != nullptr)
        return "GLUTEN_FREE_BUN";

    return "";
}

double GlutenFreeBunOrder::getPrice()
{
    return price;
}
