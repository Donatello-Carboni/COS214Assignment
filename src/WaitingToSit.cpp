#include "WaitingToSit.h"
#include "WaitingToOrder.h"
#include "AboutToLeave.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

WaitingToSit::WaitingToSit()
{

}

WaitingToSit::~WaitingToSit()
{

}

void WaitingToSit::chooseItems(Customer* customer)
{
    //cout << "[WAITING_TO_SIT]\t- Choosing items..." << endl;
    customer->setState(new WaitingToOrder());
}

void WaitingToSit::callToOrder(Customer* customer)
{
    cout << "[WAITING_TO_SIT]\t- Customer must first choose items to order.." << endl;
    chooseItems(customer);
}

void WaitingToSit::idle(Customer* customer)
{
    cout << "[WAITING_TO_SIT]\t- Customer needs to order first..." << endl;
}

void WaitingToSit::callForBill(Customer* customer)
{
    cout << "[WAITING_TO_SIT]\t- Getting the bill..." << endl;
    changeHappiness(customer);
    cout << "[WAITING_TO_SIT]\t- Happiness changed..." << endl;
    cout << "[WAITING_TO_SIT]\t- Happiness:\tCustomer " << customer->getCustomerNumber() << "[" << customer->getHappiness() << "] " << endl;
    
    payBill(customer);
}

void WaitingToSit::payBill(Customer* customer)
{
    customer->setState(new AboutToLeave());
}

void WaitingToSit::review(Customer* customer)
{
    cout << "[WAITING_TO_SIT]\t- Cannot review yet... Please order the bill first" << endl;
}

void WaitingToSit::changeHappiness(Customer* customer)
{
    srand(time(NULL));
    int happiness = rand() % 100;
    cout << "[WAITING_TO_SIT]\t- HAPPINESS: " << customer->getHappiness() << endl;
    customer->setHappiness(happiness);
}

string WaitingToSit::toString()
{
    return "[WAITING_TO_SIT]";
}