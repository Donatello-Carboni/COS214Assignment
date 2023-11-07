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
        std::cout << yellow << bold << "|  + This is the beginning of the chain" << std::endl << yellow <<  "| " << reset;
        std::cin >> read;
    }
    BurgerOrder *tempOrder = order;
    while (tempOrder != nullptr)
    {
        if (tempOrder->toString() == "CHEESE_SLICE")
        {
            if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "CheeseChef" << ": Adding " << blue << "cheese" << yellow << std::endl << yellow << "| " << reset;
            std::cin >> read;}
    
            plate->addCheese();
        }
        tempOrder = tempOrder->getNext();
    }
    if(this->inspected == false){std::cout << yellow << bold << "|  + " << white << "CheeseChef" << ": " << green << "Handing to next chef" << yellow << std::endl << yellow <<  "| " << reset;
    std::cin>>read;}
    this->inspected = true;
    BaseChef::addToPlate(order, plate); // Pass to next
}
