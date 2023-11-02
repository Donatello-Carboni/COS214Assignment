#include "CheeseChef.h"

CheeseChef::CheeseChef()
{
    nextChef = nullptr;
}

void CheeseChef::addToPlate(std::vector<std::string> order, Plate *plate)
{
    
    if (order.size() <= 0)
    {
        return;
    }
    
    auto it = std::find(order.begin(), order.end(), "cheese");

    if (it != order.end())
    {
        std::cout << "Adding Cheese to the plate." << std::endl;
        //plate.addSauce(); Todo
        order.erase(it); //Remove from order
    }
    
    
    BaseChef::addToPlate(order, plate); //Pass to next 
}