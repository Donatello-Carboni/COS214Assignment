#include "AboutToLeave.h"
#include "Customer.h"
#include "Default.h"
#include "State.h"
#include "WaitingToOrder.h"
#include "WaitingToSit.h"
#include <unistd.h>

int stateMain()
{
    int numCustomers = 0;
    Customer customer(++numCustomers);
    customer.placeOrder();
    string ready = "N";

    cout << "=========================" << endl;
    cout << "       BURGER MANIA      " << endl;
    cout << "=========================" << endl;
    cout << "Welcome to Burger Mania!" << endl;
    cout << "This is a customer: " << endl;

    cout << "Here is the customer number: " << customer.getCustomerNumber() << endl;
    cout << "Customer is currently " << customer.getState()->toString() << endl;
    cout << "Ready to order? (Y/N): ";
    
    cin >> ready;
    if (ready == "N")
        cout << "Okay well, you are going to order anyway... soz" << endl;
    else if (ready == "Y")
        cout << "Alright, here's the menu: " << endl;
    else cout << "sigh..." << endl;

    customer.placeOrder();

    cout << "The meal is now being prepared..." << endl;
    sleep(1);
    cout << "." << endl;
    sleep(1);
    cout << ".." << endl;
    sleep(1);
    cout << "..." << endl;
    sleep(1);
    cout << "The order was created!" << endl;

    vector<string> order = customer.getOrder();
    vector<string>::iterator it;
    
    cout << "Here is what you ordered: " << order.size() << endl;
    for (it = order.begin(); it != order.end(); it++)
    {
        cout << *(it) << endl;
    }

    customer.getTheBill();

    return 0;
}