#include "KitchenMediator.h"
#include <vector>

KitchenMediator::~KitchenMediator()
{
    for (int i = 0; i < colleagues.size(); i++)
    {
        delete colleagues[i];
    }
    for (int i = 0; i < commands.size(); i++)
    {
        delete commands[i];
    }
}

KitchenMediator::KitchenMediator(Colleague *colleague[], Command *command[])
{
    for (int i = 0; i < 3; i++)
    {
        colleagues.push_back(colleague[i]);// colleague 1 is for waiter colleague 2 is for chef 
        commands.push_back(command[i]); // command 1 is for adding to order and canceling from the order second is for complaints
    }
}

void KitchenMediator::addColleague(Colleague *colleague)
{
     colleagues.push_back(colleague);
}

void KitchenMediator::addCommand(Command *command)
{
    commands.push_back(command);
}

void KitchenMediator::removeColleague(Colleague *colleague)
{
    bool bfound = false;
    int i = 0;
    while(!bfound&&i<colleagues.size())
    {
        if (colleagues[i] == colleague)
        {
            colleagues.erase(colleagues.begin() + i);
            bfound = true;
        }
        i++;
    }
}

void KitchenMediator::removeCommand(Command *command)
{
    bool bfound = false;
    int i = 0;
    while(!bfound&&i<commands.size())
    {
        if (commands[i] == command)
        {
            commands.erase(commands.begin() + i);
            bfound = true;
        }
        i++;
    }
    
}

std::vector<Colleague*> KitchenMediator::getColleagues()
{
    return colleagues;
}

std::vector<Command*> KitchenMediator::getCommands()
{
    return commands;
}

