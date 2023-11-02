#include "BaseChef.h"

BaseChef::BaseChef() : nextChef(nullptr)
{
}

BaseChef *BaseChef::add(BaseChef *chef)
{
    if (nextChef)
    {
        nextChef->add(chef);
    }
    else
    {
        nextChef = chef;
        
    }
    return chef;
}

void BaseChef::addToPlate(std::vector<std::string> order, Plate *plate)
{

    if (nextChef)
    {
        nextChef->addToPlate(order, plate);
    }
    else
    {
        std::cout << "Order Complete." << std::endl;
    }
}
