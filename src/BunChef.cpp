#include "BunChef.h"

BunChef::BunChef()
{
}

void BunChef::addToPlate(BurgerOrder *order, Plate *plate)
{
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "GLUTEN_FREE_BUN")
        {
            plate->addBun("GLUTEN_FREE_BUN");
        }
        else if (tempOrder->toString() == "REGULAR_BUN")
        {
            plate->addBun("REGULAR_BUN");
        }
        tempOrder = tempOrder->getNext();
    }

    BaseChef::addToPlate(order, plate); // Pass to next
}