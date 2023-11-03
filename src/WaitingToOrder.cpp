#include "WaitingToOrder.h"
#include "AboutToLeave.h"
#include "Default.h"
#include <iostream>
#include <random>

using namespace std;

WaitingToOrder::WaitingToOrder()
{

}

WaitingToOrder::~WaitingToOrder()
{

}

void WaitingToOrder::chooseItems(Customer* customer)
{
    vector<string> order;
    int topping;

    random_device ran;
    mt19937 op(ran());
    mt19937 total(ran());
    
    std::uniform_int_distribution<int> totalToppings(2, 9);
    int loop = totalToppings(total);

    std::uniform_int_distribution<int> optionChoice(1, 2);
    int option = optionChoice(op);

    switch (option)
    {
        case 1:
        {
            order.push_back("REGULAR_BUN");            
            break;
        }
        case 2:
        {
            order.push_back("GLUTEN_FREE_BUN");            
            break;
        }
    }

    //2nd While loop to add extra toppings
    for (int i = 0; i < loop; i++)
    {
        //Creating a new random object to ensure more randomness
        mt19937 top(ran());
        std::uniform_int_distribution<int> topp(1, 8);
        int topping = topp(top);
        if (i == 1)                                                             //Ensures every customer will order a patty, and not have an awkward order
            topping = i;

        switch(topping)
        {
            case 1:
            {
                order.push_back("PATTY");
                break;
            }
            case 2:
            {   
                order.push_back("MUSTARD_SAUCE");
                break;
            }
            case 3:
            {
                order.push_back("TOMATO_SAUCE");
                break;
            }
            case 4:
            {
                order.push_back("SLICE_OF_CHEESE");
                break;
            }
            case 5:
            {
                order.push_back("LETTUCE");
                break;
            }
            case 6:
            {
                order.push_back("GHERKINS");
                break;
            }
            case 7:
            {
                order.push_back("ONION_SLICE");
                break;
            }
            case 8:
            {
                order.push_back("MUSHROOMS");
                break;
            }
        }
    }

    customer->setOrder(order);
    customer->setState(new Default());
}

void WaitingToOrder::callToOrder(Customer* customer)
{
    cout << "[WAITING_TO_ORDER]\t- Calling waiter to order..." << endl;
    customer->setState(new WaitingToOrder());
}

void WaitingToOrder::idle(Customer* customer)
{
    cout << "[WAITING_TO_ORDER]\t- Customer " << customer->getCustomerNumber() << " is idle" << endl;
}

void WaitingToOrder::callForBill(Customer* customer)
{
    cout << "[WAITING_TO_ORDER]\t- There is no bill as of yet, please place an order" << endl;
}

void WaitingToOrder::payBill(Customer* customer)
{
    cout << "[WAITING_TO_ORDER]\t- There is no bill, leaving the restaurant" << endl;
    customer->setState(new AboutToLeave());
}

void WaitingToOrder::review(Customer* customer)
{
    cout << "[WAITING_TO_ORDER]\t- Leaving a review before leaving the restaurant" << endl;
    customer->setState(new AboutToLeave());
}

void WaitingToOrder::changeHappiness(Customer* customer)
{
    cout << "[WAITING_TO_ORDER]\t- Happiness changed..." << endl;
    cout << "[WAITING_TO_ORDER]\t- Happiness:\tCustomer " << customer->getCustomerNumber() << "[" << customer->getHappiness() << "] " << endl;
}

string WaitingToOrder::toString()
{
    return "[WAITING_TO_ORDER]";
}