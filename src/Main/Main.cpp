#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>

#include "../AboutToLeave.h"
#include "../BaseChef.h"
#include "../Caretaker.h"
#include "../Chef.h"
#include "../Colleague.h"
#include "../Command.h"
#include "../ConcreteMediator.h"
#include "../CreateOrder.h"
#include "../Customer.h"
#include "../KitchenMediator.h"
#include "../Plate.h"
#include "../Tab.h"
#include "../TabMemento.h"
#include "../Waiter.h"
#include "../WaitingToOrder.h"
#include "../WaitingToSit.h"

int main() {
  //======================
  //======CUSTOMER========
  //======================
  // This is the customer main, however I've added some sections of comments
  // directing the flow of what should happen in the demo main. Other classes
  // will be added later in between (such as the waiter, mediator, command etc)

  int numCustomers = 0;
  string ready = "";
  Customer customer1(++numCustomers);
  Customer customer2(++numCustomers);
  Customer customer3(++numCustomers);
  Customer customer4(++numCustomers);

  // Customers being assigned to a table, table could be assigned these 4
  // customers?
  customer1.sitDown();
  customer2.sitDown();
  customer3.sitDown();
  customer4.sitDown();

  cout << "Simulation paused, enter any key to continue: ";
  cin >> ready;
  cout << "Resuming simulation..." << endl;

  // Customers are ready to order...
  customer1.placeOrder();
  customer2.placeOrder();
  customer3.placeOrder();
  customer4.placeOrder();

  // Customers are now in default state awaiting order...
  cout << "Simulation paused, enter any key to continue: ";
  cin >> ready;
  cout << "Resuming simulation..." << endl;

  // Waiter needs to retrieve their order via the table & iterator
  customer1.printOrder();
  customer2.printOrder();
  customer3.printOrder();
  customer4.printOrder();

  cout << "The meals are now being prepared..." << endl;
  cout << "." << endl;
  cout << ".." << endl;
  cout << "..." << endl;
  cout << "Simulation paused, enter any key to continue: ";
  cin >> ready;
  cout << "Resuming simulation" << endl;

  // Waiter needs to store order & add it to the bill in the memento

  cout << "Simulation paused, enter any key to continue: ";
  cin >> ready;
  cout << "Resuming simulation" << endl;

  // Waiter needs to send order (string vector) through mediator and command to
  // decorator)

  cout << "Simulation paused, enter any key to continue: ";
  cin >> ready;
  cout << "Resuming simulation" << endl;

  // Decorator creates order objects based on order (command triggers the
  // creation of objects)

  cout << "Simulation paused, enter any key to continue: ";
  cin >> ready;
  cout << "Resuming simulation" << endl;

  // Chef needs to create items

  cout << "Simulation paused, enter any key to continue: ";
  cin >> ready;
  cout << "Resuming simulation" << endl;

  // Chef needs to send created order back

  cout << "Simulation paused, enter any key to continue: ";
  cin >> ready;
  cout << "Resuming simulation" << endl;

  // Waiter gives order back to customer

  cout << "Simulation paused, enter any key to continue: ";
  cin >> ready;
  cout << "Resuming simulation" << endl;

  // Customer gets the bill and leaves a review/complaint

  cout << "Simulation paused, enter any key to continue: ";
  cin >> ready;
  cout << "Resuming simulation" << endl;

  customer1.getTheBill();
  customer2.getTheBill();
  customer3.getTheBill();
  customer4.getTheBill();

  //================
  //======END=======
  //================

  return 0;
}
