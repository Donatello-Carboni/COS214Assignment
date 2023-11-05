#include "WaitingToSit.h"
#include "WaitingToOrder.h"
#include "AboutToLeave.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

WaitingToSit::WaitingToSit()
{
    cout << "New WAITING_TO_SIT State" << endl;
}

WaitingToSit::~WaitingToSit()
{
    cout << "WAITING_TO_SIT destroyed..."  << endl;    
}

void WaitingToSit::chooseItems(Customer* customer)
{
    customer->setState(new WaitingToOrder());
}

void WaitingToSit::callToOrder(Customer* customer)
{
    cout << "[WAITING_TO_SIT] - Customer must first choose items to order.." << endl;
    chooseItems(customer);
}

void WaitingToSit::idle(Customer* customer)
{
    cout << "[WAITING_TO_SIT] - Customer needs to order first..." << endl;
}

void WaitingToSit::callForBill(Customer* customer)
{
    cout << "[WAITING_TO_SIT] - Getting the bill..." << endl;
    changeHappiness(customer);
    cout << "[WAITING_TO_SIT] - Happiness changed..." << endl;
    cout << "[WAITING_TO_SIT] - Happiness:\tCustomer " << customer->getCustomerNumber() << "[" << customer->getHappiness() << "] " << endl;
    
    payBill(customer);
}

void WaitingToSit::payBill(Customer* customer)
{
    customer->setState(new AboutToLeave());
}

void WaitingToSit::review(Customer* customer)
{
    cout << "[WAITING_TO_SIT] - Cannot review yet... Please order the bill first" << endl;
}

void WaitingToSit::changeHappiness(Customer* customer)
{
    //Randomize seed before changing happiness every time
    int num = rand() % 10;
    for (int i = 0; i < num; i++)
    {
        srand(time(NULL));
    }

    int happiness = rand() % 12;

    customer->changeHappiness(happiness);
    cout << "[WAITING_TO_SIT]\t- HAPPINESS: " << customer->getHappiness() << endl;
}

string WaitingToSit::toString()
{
    return "[WAITING_TO_SIT]";
}