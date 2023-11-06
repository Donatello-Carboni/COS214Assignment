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
        std::cout << "Patty chef is inspecting order" << std::endl;
        std::cin>>read;
    }
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "PATTY")
        {
            if(this->inspected == false){std::cout<<"PattyChef: Adding patty"<<std::endl;std::cin>>read;}
            plate->addPatty();
        }
        tempOrder = tempOrder->getNext();
    }
    if(this->inspected == false){std::cout<<"PattyChef: handing to next chef"<<std::endl;std::cin>>read;}
    this->inspected = true;
    BaseChef::addToPlate(order, plate); // Pass to next
}