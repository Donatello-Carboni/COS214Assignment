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
        std::cout << "Extras chef is inspecting order" << std::endl;
        std::cin>>read;
    }
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "GHERKIN")
        {
            if(this->inspected == false){std::cout<<"ExtrasChef: Adding gherkin"<<std::endl;std::cin>>read;}

            plate->addExtra("GHERKIN");
        }
        else if (tempOrder->toString() == "ONION_SLICE")
        {
            if(this->inspected == false){std::cout<<"ExtrasChef: Adding onion slice"<<std::endl;std::cin>>read;}
            plate->addExtra("ONION_SLICE");
        }
        else if (tempOrder->toString() == "LETTUCE")
        {
            if(this->inspected == false){std::cout<<"ExtrasChef: Adding lettuce"<<std::endl;std::cin>>read;}
            plate->addExtra("LETTUCE");
        }
        else if (tempOrder->toString() == "MUSHROOM")
        {
            if(this->inspected == false){std::cout<<"ExtrasChef: Adding mushroom"<<std::endl;std::cin>>read;}
            plate->addExtra("MUSHROOM");
        }
        tempOrder = tempOrder->getNext();
    }
    if(this->inspected == false){std::cout<<"ExtrasChef: handing to next chef"<<std::endl;std::cin>>read;}
    this->inspected = true;
    BaseChef::addToPlate(order, plate); // Pass to next
}