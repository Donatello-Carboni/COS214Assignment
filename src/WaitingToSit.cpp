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
    cout << "[WAITING_TO_SIT] - Choosing items..." << endl;
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
    srand(time(NULL));
    int happiness = rand() % 100;
    cout << "[WAITING_TO_SIT] - HAPPINESS: " << customer->getHappiness() << endl;
    customer->setHappiness(happiness);
}

string WaitingToSit::toString()
{
    return "[WAITING_TO_SIT]";
}