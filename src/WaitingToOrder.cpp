#include "WaitingToOrder.h"
#include "AboutToLeave.h"
#include "Default.h"
#include <iostream>

using namespace std;

WaitingToOrder::WaitingToOrder()
{
    cout << "The customer is WAITING_TO_ORDER" << endl;
}

WaitingToOrder::~WaitingToOrder()
{
    cout << "Deleting WAITING_TO_ORDER state" << endl;
}

void WaitingToOrder::chooseItems(Customer* customer)
{
    cout << "|======================================|" << endl;
    cout << "|$-          BURGER CREATION         -$|" << endl;
    cout << "|======================================|" << endl;
    int option = 0, topping;
    bool done = false;
    vector<string> order;

    //1st While loop to enter Bun Type
    while (option != 1 && option != 2)
    {
        cout << "Please choose a bun type:" << endl;
        cout << "1) Regular Bun" << endl;
        cout << "2) Gluten-Free Bun" << endl;
        cin >> option;
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
            default:
            {
                cout << "That is not a valid option... Please enter either '1' or '2'" << endl;
                break;
            }
        }
    }

    //2nd While loop to add extra toppings
    while (!done)
    {
        cout << "|--------------------------------------|" << endl;
        cout << "Please add toppings to the burger:" << endl;
        cout << "1) Beef Patty" << endl;
        cout << "2) Mustard sauce" << endl;
        cout << "3) Tomato sauce" << endl;
        cout << "4) Slice of Cheese" << endl;
        cout << "5) Lettuce" << endl;
        cout << "6) Gherkins" << endl;
        cout << "7) Onion slice" << endl;
        cout << "8) Mushrooms" << endl;
        cout << "9) DONE" << endl;
        
        cin >> topping;
        switch(topping)
        {
            case 1:
            {
                cout << "Added a Beef patty to your order :)" << endl;
                order.push_back("PATTY");
                break;
            }
            case 2:
            {   
                cout << "Added Mustard sauce to your order :)" << endl;
                order.push_back("MUSTARD_SAUCE");
                break;
            }
            case 3:
            {
                cout << "Added a Tomato sauce to your order :)" << endl;
                order.push_back("TOMATO_SAUCE");
                break;
            }
            case 4:
            {
                cout << "Added a slice of cheese to your order :)" << endl;
                order.push_back("SLICE_OF_CHEESE");
                break;
            }
            case 5:
            {
                cout << "Added lettuce to your order :)" << endl;
                order.push_back("LETTUCE");
                break;
            }
            case 6:
            {
                cout << "Added gherkins to your order :)" << endl;
                order.push_back("GHERKINS");
                break;
            }
            case 7:
            {
                cout << "Added an onion slice to your order :)" << endl;
                order.push_back("ONION_SLICE");
                break;
            }
            case 8:
            {
                cout << "Added mushrooms to your order :)" << endl;
                order.push_back("MUSHROOMS");
                break;
            }
            case 9:
            {
                cout << "Moving on to the next phase" << endl;
                done = true;
                //Signal the command object to create toppings...
                customer->setOrder(order);
                customer->setState(new Default());
                break;
            }
            default:
            {
                cout << "That is not a valid topping option..." << endl;
                cout << "Please enter a number between 1 and 8" << endl;
            }
        }
    }
}

void WaitingToOrder::callToOrder(Customer* customer)
{
    cout << "[WAITING_TO_ORDER] - Calling waiter to order..." << endl;
    customer->setState(new WaitingToOrder());
}

void WaitingToOrder::idle(Customer* customer)
{
    cout << "[WAITING_TO_ORDER] - Customer " << customer->getCustomerNumber() << " is idle" << endl;
}

void WaitingToOrder::callForBill(Customer* customer)
{
    cout << "[WAITING_TO_ORDER] - There is no bill as of yet, please place an order" << endl;
}

void WaitingToOrder::payBill(Customer* customer)
{
    cout << "[WAITING_TO_ORDER] - There is no bill, leaving the restaurant" << endl;
    customer->setState(new AboutToLeave());
}

void WaitingToOrder::review(Customer* customer)
{
    cout << "[WAITING_TO_ORDER] - Leaving a review before leaving the restaurant" << endl;
    customer->setState(new AboutToLeave());
}

void WaitingToOrder::changeHappiness(Customer* customer)
{
    //Randomize seed before changing happiness every time
    int num = rand() % 10;
    for (int i = 0; i < num; i++)
    {
        srand(time(NULL));
    }

    int happiness = rand() % 12;
    customer->changeHappiness(happiness);
    cout << "[WAITING_TO_ORDER] - Happiness changed..." << endl;
    cout << "[WAITING_TO_ORDER] - Happiness:\tCustomer " << customer->getCustomerNumber() << "[" << customer->getHappiness() << "] " << endl;
}

string WaitingToOrder::toString()
{
    return "[WAITING_TO_ORDER]";
}