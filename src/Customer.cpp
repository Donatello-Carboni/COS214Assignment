#include "Customer.h"
#include "WaitingToSit.h"

Customer::Customer()
{

}

Customer::Customer(int num)
{
    customerNumber = num;
    happiness = 60;
    cout << "New customer created (" << num << ")" << endl;
    state = new WaitingToSit();
}

Customer::~Customer()
{
    cout << "Customer deleted (" << customerNumber << ")" << endl;    
}

int Customer::getHappiness()
{
    return happiness;
}

void Customer::setHappiness(int happy)
{
    if (happiness - happy < 0)
    {
        happiness = 20;
    }
    else
    {
        happiness -= happy;
    }
}

State* Customer::getState()
{
    return state;
}

void Customer::setState(State* newState)
{
    if (newState != this->state)
    {
        if (this->state != NULL)
            delete this->state;
        this->state = newState;
    }
}

void Customer::setOrder(vector<string> extras)
{
    //First item is the bun-type, the rest are toppings
    order = extras;
}

vector<string> Customer::getOrder()
{
    return order;
}

void Customer::placeOrder()
{
    state->chooseItems(this);
}

void Customer::getTheBill()
{
    state->callForBill(this);
    state->payBill(this);
    state->review(this);
}

int Customer::getCustomerNumber()
{
    return customerNumber;
}

void Customer::leave()
{
    this->~Customer();
}

void Customer::printOrder()
{
    std::vector<std::string>::iterator it;
    for (it = order.begin(); it != order.end(); it++)
    {
        cout << *(it) << endl;
    }
}