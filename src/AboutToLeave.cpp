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
    cout << "[ABOUT_TO_LEAVE]\t- Cannot order new items as the customer will leave soon" << endl;
    customer->leave();
}

void AboutToLeave::callToOrder(Customer* customer)
{
    cout << "[ABOUT_TO_LEAVE]\t- Please choose items before calling to order..." << endl;
    customer->setState(new WaitingToOrder());
}

void AboutToLeave::idle(Customer* customer)
{
    cout << "[ABOUT_TO_LEAVE]\t- Customer (" << customer->getCustomerNumber() << ") is waiting for the bill" << endl;
}

void AboutToLeave::callForBill(Customer* customer)
{
    idle(customer);
    changeHappiness(customer);
}

void AboutToLeave::payBill(Customer* customer)
{
    cout << "[ABOUT_TO_LEAVE]\t- Customer (" << customer->getCustomerNumber() << ") has payed the bill" << endl;
}

void AboutToLeave::review(Customer* customer)
{
    cout << "[ABOUT_TO_LEAVE]\t- Customer (" << customer->getCustomerNumber() << ") wants to leave a review..." << endl;
    changeHappiness(customer);
}

void AboutToLeave::changeHappiness(Customer* customer)
{
    //Randomize seed before changing happiness every time
    int num = rand() %10;
    for (int i = 0; i < num; i++)
    {
        srand(time(NULL));
    }

    int happiness = customer->getHappiness();

    if (happiness < 50)
        happiness = rand() %10;
    else if (happiness < 75 && happiness > 50)
        happiness = rand() % 10 + rand() %16;

    customer->setHappiness(happiness);

    cout << "[ABOUT_TO_LEAVE]\t- Happiness changed..." << endl;
    cout << "[ABOUT_TO_LEAVE]\t- Happiness:\tCustomer " << customer->getCustomerNumber() << "[" << customer->getHappiness() << "] " << endl;
}

string AboutToLeave::toString()
{
    return "[ABOUT_TO_LEAVE]";
}