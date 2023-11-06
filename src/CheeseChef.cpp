#include "CheeseChef.h"

CheeseChef::CheeseChef()
{
    nextChef = nullptr;
}

void CheeseChef::addToPlate(BurgerOrder *order, Plate *plate)
{
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << "This is the beginning of the chain" << std::endl;
        std::cin>>read;
    }
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "CHEESE_SLICE")
        {
            if(this->inspected == false){std::cout<<"CheeseChef: Adding cheese"<<std::endl;std::cin>>read;}
    
            plate->addCheese();
        }
        tempOrder = tempOrder->getNext();
    }
    if(this->inspected == false){std::cout<<"CheeseChef: handing to next chef"<<std::endl;std::cin>>read;}
    this->inspected = true;
    BaseChef::addToPlate(order, plate); // Pass to next
}
