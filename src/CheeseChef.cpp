#include "CheeseChef.h"

CheeseChef::CheeseChef()
{
    nextChef = nullptr;
}

void CheeseChef::addToPlate(BurgerOrder *order, Plate *plate)
{
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "CHEESE_SLICE")
        {
            plate->addCheese();
        }
        tempOrder = tempOrder->getNext();
    }

    BaseChef::addToPlate(order, plate); // Pass to next
}
