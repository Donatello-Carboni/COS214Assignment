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
  mediator->addColleague((Colleague *)waiter2);

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
  std::vector<Customer *> seat3;
  for (int i = 12; i < 16; i++) {
    Customer *c = new Customer(i);
    //c->placeOrder();
    seat3.push_back(c);
  }

  string ready = "";
  //======TERMINAL PREP======
  //    Styles
  std::string reset = "\033[0m";
  std::string bold = "\033[1m";
  std::string underline = "\033[4m";
  std::string blink_slow_flash  = "\033[5m";
  std::string reverse = "\033[7m";
  //    Colours
  std::string red = "\033[31m";
  std::string green = "\033[32m";
  std::string yellow = "\033[33m";
  std::string blue = "\033[34m";
  std::string magenta = "\033[35m";
  std::string cyan = "\033[36m";
  std::string white = "\033[37m";
  //    Background-Colours
  std::string blackBack = "\033[40m";
  std::string redBack = "\033[41m";
  std::string greenBack = "\033[42m";
  std::string yellowBack = "\033[43m";
  std::string blueBack = "\033[44m";
  std::string magentaBack = "\033[45m";
  std::string cyanBack = "\033[46m";
  std::string whiteBack = "\033[47m";
  //===========END===========

  cout << "\033[1;31;5m";
  cout << "|=========================================|" << endl;
  cout << "|===" << white << "$" << cyan <<"       " << cyan << "BURGER BLITZ TYCOON" << "\033[1;31;5m" << "       " << white << "$" << red << "===|" << endl;
  cout << "|=========================================|" << endl;
  cout << reset << endl;
  cout << yellow << bold;
  cout << "|  + About to seat customers..." << endl;
  cout << reset;
  cin>>ready;

  cout << yellow << bold;
  cout << "|  + Waiter 1 seating customers..." << endl;
  waiter->seatCustomer(seat9);
  waiter->seatCustomer(seat4);

  cout << bold << endl;
  cout << "Resuming simulation..." << endl;
  cout << reset << endl;

  cout << yellow << bold;
  cout << "|  + Waiter 2 seating customers..." << endl;
  waiter2->seatCustomer(seat3);
  
  cout << "" << endl;
  cout << reset << bold << yellow; 
  cout << "|  + " << green << "Commencing First Waiter Iteration taking orders..." << endl;
  cout << reset << bold << yellow; 
  cout << "|  + " << green << "Note there exits an order from Customer 0 Tab for a Cheese-Burger " << endl << yellow;
  cout << "|    " << green << "with mushrooms and tomato sauce that will need to be paid off before" << endl << yellow
       << "|    " << green << "the customer may order" << reset << endl;
  cout << reset;
  cin>>ready;

  waiter->CompleteCircuit();
  waiter->Iterator=true;
  
  waiter2->CompleteCircuit();
  cout << yellow << bold <<  "|  + Second iteration returning orders" << endl << reset;
  cin>>ready;
  
  cout << bold << "Resuming simulation..." << endl;

  waiter->CompleteCircuit();
  waiter2->CompleteCircuit();
    cout << yellow << bold <<  "|  + Third itertaion paying bills or making tabs and leaving" << endl << reset;
  cin>>ready;

  cout << bold << "Resuming simulation..." << endl;
  
  waiter->CompleteCircuit();
  waiter2->CompleteCircuit();
  cout << yellow << bold <<  "|  + Last iteration complete these customers made reviews" << endl << reset;
  cin>>ready;

  cout << bold << "Resuming simulation..." << endl;
   Manager::getManager().toString();
  return 0;
}
