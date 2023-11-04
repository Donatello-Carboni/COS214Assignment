#include "Customer.h"
#include "WaitingToSit.h"
#include "WaitingToOrder.h"
Customer::Customer()
{

}

Customer::Customer(int num)
{
    customerNumber = num;
    happiness = 60;
    cout << "New customer created (" << num << ")" << endl;
    //state = new WaitingToSit();
    state = new WaitingToOrder();
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
    cout<<"Placing order"<<endl;
    // state->chooseItems(this);
    std::vector<std::string> order;
    std::string bun = "RegularBun";
    std::string patty = "Patty";
    std::string cheese = "Cheese";
    std::string cCheese = "cancel-Cheese";
    std::string id = "1";
    order.push_back(id);
    order.push_back(bun);
    order.push_back(patty);
    order.push_back(cheese);
    order.push_back(cCheese);
    this->setOrder(order);
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