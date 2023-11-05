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
    Customer customer1(++numCustomers);
    Customer customer2(++numCustomers);
    Customer customer3(++numCustomers);
    Customer customer4(++numCustomers);

    //Customers are ready to order...
    customer1.placeOrder();
    customer2.placeOrder();
    customer3.placeOrder();
    customer4.placeOrder();
    string ready = "";

    //Customers are now in default state awaiting order...
    cout << "Simulation paused, enter any key to continue: ";
    
    cin >> ready;
    
        cout << "Resuming simulation..." << endl;

    //Waiter needs to retrieve their order via the table & iterator

    cout << "The meals are now being prepared..." << endl;
    cout << "." << endl;
    cout << ".." << endl;
    cout << "..." << endl;
    cout << "Simulation paused, enter any key to continue: ";
    cin >> ready;
    cout << "Resuming simulation" << endl;

    //Waiter needs to store order & add it to the bill in the memento

    cout << "Simulation paused, enter any key to continue: ";
    cin >> ready;
    cout << "Resuming simulation" << endl;

    //Waiter needs to send order (string vector) through mediator and command to decorator)

    cout << "Simulation paused, enter any key to continue: ";
    cin >> ready;
    cout << "Resuming simulation" << endl;

    //Decorator creates order objects based on order (command triggers the creation of objects)

    cout << "Simulation paused, enter any key to continue: ";
    cin >> ready;
    cout << "Resuming simulation" << endl;

    //Chef needs to create items

    cout << "Simulation paused, enter any key to continue: ";
    cin >> ready;
    cout << "Resuming simulation" << endl;

    //Chef needs to send created order back

    cout << "Simulation paused, enter any key to continue: ";
    cin >> ready;
    cout << "Resuming simulation" << endl;

    //Waiter gives order back to customer

    cout << "Simulation paused, enter any key to continue: ";
    cin >> ready;
    cout << "Resuming simulation" << endl;

    //Customer gets the bill and leaves a review/complaint

    cout << "Simulation paused, enter any key to continue: ";
    cin >> ready;
    cout << "Resuming simulation" << endl;


    customer1.getTheBill();
    customer2.getTheBill();
    customer3.getTheBill();
    customer4.getTheBill();

    return 0;
}