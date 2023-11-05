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