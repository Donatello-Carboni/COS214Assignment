#include "ExtrasChef.h"

ExtrasChef::ExtrasChef()
{
    nextChef = nullptr;
}

void ExtrasChef::addToPlate(BurgerOrder *order, Plate *plate)
{
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << yellow << bold << "|  + " << white << "ExtrasChef" << yellow <<  ": inspecting order" << std::endl << "| " << reset;
        std::cin>>read;
    }
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "GHERKIN")
        {
            if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "ExtrasChef" << yellow << ": Adding " << red << "Gherkin" << std::endl << yellow << "| " << reset;
            std::cin>>read;}

            plate->addExtra("GHERKIN");
        }
        else if (tempOrder->toString() == "ONION_SLICE")
        {
            if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "ExtrasChef" << yellow << ": Adding " << red << "Onion slice" << std::endl << yellow << "| " << reset;
            std::cin>>read;}
            plate->addExtra("ONION_SLICE");
        }
        else if (tempOrder->toString() == "LETTUCE")
        {
            if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "ExtrasChef" << yellow << ": Adding " << red <<  "Lettuce" << std::endl << yellow << "| " << reset;
            std::cin>>read;}
            plate->addExtra("LETTUCE");
        }
        else if (tempOrder->toString() == "MUSHROOM")
        {
            if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "ExtrasChef" << yellow << ": Adding " << red << "Mushroom" << std::endl << yellow << "| " << reset;
            std::cin>>read;}
            plate->addExtra("MUSHROOM");
        }
        tempOrder = tempOrder->getNext();
    }
    if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "ExtrasChef" << green << ": Handing to next chef" << std::endl  << "| " << reset;
    std::cin>>read;}
    this->inspected = true;
    BaseChef::addToPlate(order, plate); // Pass to next
}