#include "BunChef.h"

BunChef::BunChef()
{
}

void BunChef::addToPlate(std::vector<std::string> order, Plate *plate)
{
    auto it = std::find(order.begin(), order.end(), "bun");
    if (it != order.end())
    {
        std::cout << "Adding Bun to the plate." << std::endl;
        //plate.addSauce(); Todo
    }
    
    order.erase(it); //Remove from order
    BaseChef::addToPlate(order, plate); //Pass to next 
}