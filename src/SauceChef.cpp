#include "SauceChef.h"

SauceChef::SauceChef()
{
    nextChef = nullptr;
}

void SauceChef::addToPlate(BurgerOrder *order, Plate *plate)
{
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << yellow << bold << "|  + " << white << "SauceChef" << yellow << ": inspecting order" << std::endl << "| " << reset;
        std::cin>>read;
    }
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "MUSTARD_SAUCE")
        {
            if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "SauceChef" << yellow << ": Adding mustard sauce" << std::endl << "| " << reset;
            std::cin>>read;}
            plate->addSauce("MUSTARD_SAUCE");
        }
        else if (tempOrder->toString() == "TOMATO_SAUCE")
        {
            if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "SauceChef" << yellow << ": Adding tomato sauce"<< std::endl << "| " << reset;
            std::cin>>read;}
            plate->addSauce("TOMATO_SAUCE");
        }
        tempOrder = tempOrder->getNext();
    }
    if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "SauceChef" << green << ": handing to next chef" << std::endl << "| " << reset;
    std::cin>>read;}
    this->inspected = true;
    BaseChef::addToPlate(order, plate); // Pass to next
}
