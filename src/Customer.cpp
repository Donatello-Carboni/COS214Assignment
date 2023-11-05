#include "Customer.h"
#include "WaitingToSit.h"
#include "WaitingToOrder.h"

Customer::Customer()
{
    paid = false;
}

Customer::Customer(int num)
{
    customerNumber = num;
    happiness = 60;
    //may need to start at waiting to order
    state = new WaitingToSit();

}

Customer::~Customer()
{
    cout << "Customer (" << customerNumber << ") left the restaurant..." << endl;    
}

int Customer::getHappiness()
{
    return happiness;
}

void Customer::changeHappiness(int happy)
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
    cout << "[CUSTOMER]\t\t- Customer (" << customerNumber << ") is ready to order!" << endl;
    order = extras;
}

vector<string> Customer::getOrder()
{
    return order;
}

void Customer::placeOrder()
{
    //need to make sure its strings just being pushed
    cout << "[CUSTOMER]\t\t- Customer (" << customerNumber << ") is deciding what to order..." << endl;
    state->chooseItems(this);

}

void Customer::cancelOrder(string item)
{
    order.push_back(item);
}

void Customer::getTheBill()
{
    state->callForBill(this);
    state->payBill(this);               //Should change state to "AboutToLeave"
    state->review(this);
    paid = true;
}

int Customer::getCustomerNumber()
{
    return customerNumber;
}

void Customer::printOrder()
{
    cout << "======CUSTOMER(" << customerNumber << ")======" << endl;
    std::vector<std::string>::iterator it;
    for (it = order.begin(); it != order.end(); it++)
    {
        cout << *(it) << endl;
    }
}


void Customer::sitDown()
{
    cout << "[CUSTOMER]\t\t- Customer (" << customerNumber << ") is sitting down at a table" << endl;
    setState(new WaitingToOrder());
}


void Customer::leave()
{
    this->~Customer();
}

bool Customer::didPay()
{
    return paid;
}