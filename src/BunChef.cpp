#include "BunChef.h"

BunChef::BunChef()
{
}

void BunChef::addToPlate(BurgerOrder *order, Plate *plate)
{
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << "Bun chef is inspecting order" << std::endl;
        std::cin>>read;
    }
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "GLUTEN_FREE_BUN")
        {
            if(this->inspected == false){std::cout<<"BunChef: Adding gluten free bun"<<std::endl;std::cin>>read;}
            plate->addBun("GLUTEN_FREE_BUN");
        }
        else if (tempOrder->toString() == "REGULAR_BUN")
        {
            if(this->inspected == false){std::cout<<"BunChef: Adding regular bun"<<std::endl;std::cin>>read;}
            plate->addBun("REGULAR_BUN");
        }
        tempOrder = tempOrder->getNext();
    }
    if(this->inspected == false){std::cout<<"BunChef: handing to next chef"<<std::endl;std::cin>>read;}
    this->inspected = true;
    BaseChef::addToPlate(order, plate); // Pass to next
}