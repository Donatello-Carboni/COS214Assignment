#include "AboutToLeave.h"
#include "WaitingToOrder.h"

AboutToLeave::AboutToLeave()
{

}

AboutToLeave::~AboutToLeave()
{

}

void AboutToLeave::chooseItems(Customer* customer)
{
    cout << "[ABOUT_TO_LEAVE] - Cannot order new items as the customer will leave soon" << endl;
    customer->leave();
}

void AboutToLeave::callToOrder(Customer* customer)
{
    cout << "[ABOUT_TO_LEAVE] - Please choose items before calling to order..." << endl;
    customer->setState(new WaitingToOrder());
}

void AboutToLeave::idle(Customer* customer)
{
    cout << "[ABOUT_TO_LEAVE] - Customer " << customer->getCustomerNumber() << " is waiting for the bill" << endl;
}

void AboutToLeave::callForBill(Customer* customer)
{
    cout << "[ABOUT_TO_LEAVE] - Customer " << customer->getCustomerNumber() << "is getting more impatient..." << endl;
    changeHappiness(customer);
}

void AboutToLeave::payBill(Customer* customer)
{
    cout << "[ABOUT_TO_LEAVE] - Customer " << customer->getCustomerNumber() << "is getting more impatient..." << endl;
    changeHappiness(customer);
}

void AboutToLeave::review(Customer* customer)
{
    cout << "[ABOUT_TO_LEAVE] - Customer " << customer->getCustomerNumber() << "wants to leave a review..." << endl;
    changeHappiness(customer);
}

void AboutToLeave::changeHappiness(Customer* customer)
{
    //Randomize seed before changing happiness every time
    int num = rand() % 10;
    for (int i = 0; i < num; i++)
    {
        srand(time(NULL));
    }

    int happiness = rand() % 12;

    customer->changeHappiness(happiness);
    cout << "[ABOUT_TO_LEAVE] - Happiness changed..." << endl;
    cout << "[ABOUT_TO_LEAVE] - Happiness:\tCustomer " << customer->getCustomerNumber() << "[" << customer->getHappiness() << "] " << endl;
}

string AboutToLeave::toString()
{
    return "[ABOUT_TO_LEAVE]";
}