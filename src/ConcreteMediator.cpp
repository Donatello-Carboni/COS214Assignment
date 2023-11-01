#include "ConcreteMediator.h"
#include <iostream>

void ConcreteMediator::notify(Colleague *colleague, int choice, std::vector<std::string> order)
{
    if(choice == 1)
    {
        std::cout << "Waiter: Notifying the kitchen..." << std::endl;
        
        
    }
    else if(choice == 2)
    {
         std::cout << "kicthen" << std::endl;

    }else if(choice == 3)
    {

    }
    else
    {
        std::cout << "Mediator: Invalid choice." << std::endl;
    }
}

void ConcreteMediator::HandleCommand(int choice)
{
    
}
