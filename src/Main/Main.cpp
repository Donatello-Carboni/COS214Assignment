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
#include "../Caretaker.h"
#include "../Tab.h"
int main() {
  string ready = "";
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
  Caretaker* Care = new Caretaker();
  Waiter *waiter = new Waiter((ConcreteMediator *)mediator, FreeTables,Care);
  Waiter *waiter2 = new Waiter((ConcreteMediator *)mediator, FreeTables2,Care);
  // making prepopulated memento to showcase rollback
  BurgerOrder* order;
  order->inspected=true;
  order= new RegularBunOrder();
  order->add(new PattyOrder());
  order->add(new CheeseOrder());
  order->add(new TomatoSauceOrder());
  order->add(new MushroomOrder());
  Tab* tab=new Tab();
  tab->setTabID(0);
  tab->addOrderedItem(order);
  tab->calculateTotalPrice();
  Care->addMemento(tab->createMemento());
  order->inspected=false;
  //-------------------------------------------------------------
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
    //c->placeOrder();
    seat9.push_back(c);
  }
  for (int i = 8; i < 12; i++) {
    Customer *c = new Customer(i);
    //c->placeOrder();
    seat4.push_back(c);
  }
  cout << "starting to seat" << endl;
  cin>>ready;
  cout << "Resuming simulation..." << endl;
  waiter->seatCustomer(seat9);
  waiter->seatCustomer(seat4);
  cout << "Commencing First Waiter Iteration taking orders. Note there exits a an order as a from Customer 0 Tab for a Cheese-Burger with mushrooms and tomato sauce that will need to be paid off before the customer may order" << endl;
  cin>>ready;
  cout << "Starting" << endl;
  waiter->CompleteCircuit();
    cout << "Second iteration returning orders" << endl;
  cin>>ready;
  cout << "Resuming simulation..." << endl;
  waiter->CompleteCircuit();
    cout << "Third itertaion paying bills or making tabs and leaving" << endl;
  cin>>ready;
  cout << "Resuming simulation..." << endl;
  waiter->CompleteCircuit();
  cout << "Last iteration complete these customers made reviews" << endl;
  cin>>ready;
  cout << "Resuming simulation..." << endl;
  // waiter2->CompleteCircuit();
   Manager::getManager().toString();
  return 0;
}
