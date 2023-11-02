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
    return "GHERKIN";
}

double GherkinOrder::getPrice()
{
    return price;
}
