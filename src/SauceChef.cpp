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
        std::cout << "Sauce chef is inspecting order" << std::endl;
        std::cin>>read;
    }
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "MUSTARD_SAUCE")
        {
            if(this->inspected == false){std::cout<<"SauceChef: Adding mustard sauce"<<std::endl;std::cin>>read;}
            plate->addSauce("MUSTARD_SAUCE");
        }
        else if (tempOrder->toString() == "TOMATO_SAUCE")
        {
            if(this->inspected == false){std::cout<<"SauceChef: Adding tomato sauce"<<std::endl;std::cin>>read;}
            plate->addSauce("TOMATO_SAUCE");
        }
        tempOrder = tempOrder->getNext();
    }
    if(this->inspected == false){std::cout<<"SauceChef: handing to next chef"<<std::endl;std::cin>>read;}
    this->inspected = true;
    BaseChef::addToPlate(order, plate); // Pass to next
}
