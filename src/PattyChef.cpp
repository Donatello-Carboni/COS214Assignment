#include "PattyChef.h"

PattyChef::PattyChef()
{
    nextChef = nullptr;
}

void PattyChef::addToPlate(BurgerOrder *order, Plate *plate)
{
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << yellow << bold << "|  + " << white << "PattyChef" << yellow << ": inspecting order" << std::endl << "| " << reset;
        std::cin>>read;
    }
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "PATTY")
        {
            if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "PattyChef" << yellow << ": Adding " << red << "patty" << std::endl << yellow << "| " << reset;
            std::cin>>read;}
            plate->addPatty();
        }
        tempOrder = tempOrder->getNext();
    }
    if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "PattyChef" << green << ": handing to next chef" << std::endl << "| " << reset;
    std::cin>>read;}
    this->inspected = true;
    BaseChef::addToPlate(order, plate); // Pass to next
}