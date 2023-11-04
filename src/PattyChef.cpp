#include "PattyChef.h"

PattyChef::PattyChef()
{
    nextChef = nullptr;
}

void PattyChef::addToPlate(BurgerOrder *order, Plate *plate)
{
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "PATTY")
        {
            plate->addPatty();
        }
        tempOrder = tempOrder->getNext();
    }

    BaseChef::addToPlate(order, plate); // Pass to next
}