#include "GherkinOrder.h"

GherkinOrder::GherkinOrder()
{
    price = 12.00;
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
