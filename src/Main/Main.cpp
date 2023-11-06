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
#include "../KitchenMediator.h"
#include "../Plate.h"
#include "../Tab.h"
#include "../TabMemento.h"
#include "../Waiter.h"
#include "../WaitingToOrder.h"
#include "../WaitingToSit.h"
#include "../SauceChef.h"
#include "../CheeseChef.h"
#include "../PattyChef.h"
#include "../ExtrasChef.h"
#include "../BunChef.h"
#include "../Customer.h"
#include "../CreateComplaint.h"

int main() {
  //======================
  //======CUSTOMER========
  //======================
  // This is the customer main, however I've added some sections of comments
  // directing the flow of what should happen in the demo main. Other classes
  // will be added later in between (such as the waiter, mediator, command etc)

  // int numCustomers = 0;
  // string ready = "";
  // Customer customer1(++numCustomers);
  // Customer customer2(++numCustomers);
  // Customer customer3(++numCustomers);
  // Customer customer4(++numCustomers);

  // // Customers being assigned to a table, table could be assigned these 4
  // // customers?
  // customer1.sitDown();
  // customer2.sitDown();
  // customer3.sitDown();
  // customer4.sitDown();

  // cout << "Simulation paused, enter any key to continue: ";
  // cin >> ready;
  // cout << "Resuming simulation..." << endl;

  // // Customers are ready to order...
  // customer1.placeOrder();
  // customer2.placeOrder();
  // customer3.placeOrder();
  // customer4.placeOrder();

  // // Customers are now in default state awaiting order...
  // cout << "Simulation paused, enter any key to continue: ";
  // cin >> ready;
  // cout << "Resuming simulation..." << endl;

  // // Waiter needs to retrieve their order via the table & iterator
  // customer1.printOrder();
  // customer2.printOrder();
  // customer3.printOrder();
  // customer4.printOrder();

  // cout << "The meals are now being prepared..." << endl;
  // cout << "." << endl;
  // cout << ".." << endl;
  // cout << "..." << endl;
  // cout << "Simulation paused, enter any key to continue: ";
  // cin >> ready;
  // cout << "Resuming simulation" << endl;

  // // Waiter needs to store order & add it to the bill in the memento

  // cout << "Simulation paused, enter any key to continue: ";
  // cin >> ready;
  // cout << "Resuming simulation" << endl;

  // Waiter needs to send order (string vector) through mediator and command to
  // decorator)

  // cout << "Simulation paused, enter any key to continue: ";
  // cin >> ready;
  // cout << "Resuming simulation" << endl;

  // // Decorator creates order objects based on order (command triggers the
  // // creation of objects)

  // cout << "Simulation paused, enter any key to continue: ";
  // cin >> ready;
  // cout << "Resuming simulation" << endl;

  // // Chef needs to create items

  // cout << "Simulation paused, enter any key to continue: ";
  // cin >> ready;
  // cout << "Resuming simulation" << endl;

  // // Chef needs to send created order back

  // cout << "Simulation paused, enter any key to continue: ";
  // cin >> ready;
  // cout << "Resuming simulation" << endl;

  // // Waiter gives order back to customer

  // cout << "Simulation paused, enter any key to continue: ";
  // cin >> ready;
  // cout << "Resuming simulation" << endl;

  // // Customer gets the bill and leaves a review/complaint

  // cout << "Simulation paused, enter any key to continue: ";
  // cin >> ready;
  // cout << "Resuming simulation" << endl;

  // customer1.getTheBill();
  // customer2.getTheBill();
  // customer3.getTheBill();
  // customer4.getTheBill();

  // //================
  // //======END=======
  // //================

  // // Create a Caretaker and a Tab
  // Caretaker caretaker;
  // Tab tab;

  // // Perform some actions on the tab
  // tab.addOrderedItem("Item1", 10.0);
  // tab.addOrderedItem("Item2", 15.0);

  // // Save the initial state in the caretaker
  // caretaker.addMemento(tab.createMemento());

  // // Perform more actions on the tab
  // tab.addOrderedItem("Item3", 20.0);

  // // Save the updated state in the caretaker
  // caretaker.addMemento(tab.createMemento());

  // // Print the current tab state
  // std::cout << "Current Tab State:" << std::endl;
  // tab.printBill();

  // // Rollback to the previous state
  // TabMemento previousState = caretaker.getMemento(3);
  // tab.setMemento(previousState);

  // // Print the tab state after rollback
  // std::cout << "\nTab State After Rollback:" << std::endl;
  // tab.printBill();

  // tab.setMemento(tab.createMemento());

  // std::cout << "\nTab State After Rollback:" << std::endl;
  // tab.printBill();
  // Mediator
  KitchenMediator *mediator = new ConcreteMediator();

  CheeseChef *cheeseChef = new CheeseChef();
  SauceChef *sauceChef = new SauceChef();
  PattyChef *pattyChef = new PattyChef();
  ExtrasChef *extrasChef = new ExtrasChef();
  BunChef * bunChef = new BunChef();


    cheeseChef->add(sauceChef);
    sauceChef->add(pattyChef);
    pattyChef->add(extrasChef);
    extrasChef->add(bunChef);
  // 3 tables
  CompositeTable table;
  CompositeTable table2;
  std::vector<Table *> FreeTables;
  FreeTables.push_back(&table);
  FreeTables.push_back(&table2);
  std::vector<Table *> FreeTables2;
  CompositeTable table3;
  CompositeTable table4;
  FreeTables2.push_back(&table3);
  FreeTables2.push_back(&table4);

  Waiter *waiter = new Waiter((ConcreteMediator *)mediator, FreeTables);
  Waiter *waiter2 = new Waiter((ConcreteMediator *)mediator, FreeTables2);

  mediator->addChef(cheeseChef);
  mediator->addColleague((Colleague *)waiter);

  Command *command = new CreateOrder();
  Command *command2 = new CreateComplaint();

  mediator->addCommand(command);
  mediator->addCommand(command2);

  std::vector<Customer *> seat9;
  std::vector<Customer *> seat4;
  for (int i = 0; i < 8; i++) {
    Customer *c = new Customer(i);
    c->placeOrder();
    seat9.push_back(c);
  }
  for (int i = 8; i < 12; i++) {
    Customer *c = new Customer(i);
    c->placeOrder();
    seat4.push_back(c);
  }
  cout << "starting to seat" << endl;
  waiter->seatCustomer(seat9);
  waiter->seatCustomer(seat4);
  waiter->CompleteCircuit(); 
  waiter->CompleteCircuit();
  waiter->CompleteCircuit();
  // waiter2->CompleteCircuit();
   Manager::getManager().toString();
  return 0;
}
