#include "GherkinOrder.h"

GherkinOrder::GherkinOrder()
{
    price = 12.00;
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << yellow << bold << "|  + Adding " << white << "Gherkin" << yellow << " to the order" << std::endl << "| " << reset;
        std::cin>>read;
    }
    add(this);
}

GherkinOrder::~GherkinOrder()
{
    
}

std::string GherkinOrder::toString()
{
    if (this != nullptr)
        return "GHERKIN";

    return "";
}

double GherkinOrder::getPrice()
{
    return price;
}
