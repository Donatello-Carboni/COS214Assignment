#include "BunChef.h"

BunChef::BunChef()
{
}

void BunChef::addToPlate(BurgerOrder *order, Plate *plate)
{
    std::string read="";
    if(this->inspected == false)
    {
        std::cout << yellow << bold << "|  + "<< white << "Bun chef" << yellow << ": inspecting order" << std::endl << yellow << "| " << reset;
        std::cin>>read;
    }
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "GLUTEN_FREE_BUN")
        {
            if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "BunChef" << yellow << ": Adding " << red << "Gluten Free Bun" << std::endl << yellow <<  "| " << reset;
            std::cin>>read;}
            plate->addBun("GLUTEN_FREE_BUN");
        }
        else if (tempOrder->toString() == "REGULAR_BUN")
        {
            if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "BunChef" << yellow << ": Adding " << red << "Regular Bun" << std::endl << yellow <<  "| " << reset; 
            std::cin>>read;}
            plate->addBun("REGULAR_BUN");
        }
        tempOrder = tempOrder->getNext();
    }
    if(this->inspected == false){std::cout << yellow << bold << "|  + "<< white << "BunChef" << yellow << ": handing to next chef" << std::endl << yellow <<  "| " << reset;
    std::cin>>read;}
    this->inspected = true;
    BaseChef::addToPlate(order, plate); // Pass to next
}