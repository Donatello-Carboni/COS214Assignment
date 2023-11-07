#include "Default.h"
#include "WaitingToOrder.h"
#include "AboutToLeave.h"

Default::Default()
{

}

Default::~Default()
{
    
}

void Default::chooseItems(Customer* customer)
{
    cout << "[DEFAULT]\t\t- Choosing items..." << endl;
    customer->setState(new WaitingToOrder());
}

void Default::callToOrder(Customer* customer)
{
    cout << "[DEFAULT]\t\t- Customer must first choose items to order.." << endl;
    chooseItems(customer);
}

void Default::idle(Customer* customer)
{
    cout << "[DEFAULT]\t\t- Customer needs to order first..." << endl;
}

void Default::callForBill(Customer* customer)
{
    cout << "[DEFAULT]\t\t- Getting the bill..." << endl;
    changeHappiness(customer);
    cout << "[DEFAULT]\t\t- Happiness changed..." << endl;
    cout << "[DEFAULT]\t\t- Happiness:\tCustomer " << customer->getCustomerNumber() << "[" << customer->getHappiness() << "] " << endl;

    payBill(customer);
}

void Default::payBill(Customer* customer)
{
    customer->setState(new AboutToLeave());
}

void Default::review(Customer* customer)
{
    cout << "[DEFAULT]\t\t- Cannot review yet... Please order the bill first" << endl;
}

void Default::changeHappiness(Customer* customer)
{
    //Randomize seed before changing happiness every time
    int num = rand() % 10;
    for (int i = 0; i < num; i++)
    {
        srand(time(NULL));
    }

    int happiness = rand() % 6 + 3;
    
    customer->changeHappiness(happiness);
    cout << "[DEFAULT]\t\t- HAPPINESS: " << customer->getHappiness() << endl;

}

string Default::toString()
{
    return "[DEFAULT]";
}