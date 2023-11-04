#include "ExtrasChef.h"

ExtrasChef::ExtrasChef()
{
    nextChef = nullptr;
}

void ExtrasChef::addToPlate(BurgerOrder *order, Plate *plate)
{
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "GHERKIN")
        {
            plate->addExtra("GHERKIN");
        }
        else if (tempOrder->toString() == "ONION_SLICE")
        {
            plate->addExtra("ONION_SLICE");
        }
        else if (tempOrder->toString() == "LETTUCE")
        {
            plate->addExtra("LETTUCE");
        }
        else if (tempOrder->toString() == "MUSHROOM")
        {
            plate->addExtra("MUSHROOM");
        }
        tempOrder = tempOrder->getNext();
    }

    BaseChef::addToPlate(order, plate); // Pass to next
}