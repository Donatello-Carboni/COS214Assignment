#include "SauceChef.h"

SauceChef::SauceChef()
{
    nextChef = nullptr;
}

void SauceChef::addToPlate(BurgerOrder *order, Plate *plate)
{

    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "MUSTARD_SAUCE")
        {
            plate->addSauce("MUSTARD_SAUCE");
        }
        else if (tempOrder->toString() == "TOMATO_SAUCE")
        {
            plate->addSauce("TOMATO_SAUCE");
        }
        tempOrder = tempOrder->getNext();
    }

    BaseChef::addToPlate(order, plate); // Pass to next
}
