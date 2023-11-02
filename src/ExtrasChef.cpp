#include "ExtrasChef.h"

ExtrasChef::ExtrasChef()
{
    nextChef = nullptr;
}

void ExtrasChef::addToPlate(std::vector<std::string> order, Plate *plate)
{
    if (order.size() <= 0)
    {
        return;
    }
    auto it = std::find(order.begin(), order.end(), "extras");
    if (it != order.end())
    {
        std::cout << "Adding Extras to the plate." << std::endl;
        //plate.addSauce(); Todo
        order.erase(it); //Remove from order
    }
    
    
    BaseChef::addToPlate(order, plate); //Pass to next 
}