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

void BaseChef::addToPlate(BurgerOrder* order, Plate *plate)
{

    if (nextChef != nullptr)
    {
        nextChef->addToPlate(order, plate);
    }
    else
    {
        std::cout << yellow << bold << "|  + " << green << "Order Complete." << std::endl << reset;
    }
}
