#include <iostream>
#include <string>
#include <vector>

#include "../Caretaker.h"
#include "../Tab.h"
#include "../TabMemento.h"
#include "../Plate.h"
#include "../Waiter.h"
#include "../Chef.h"
#include "../Colleague.h"
#include "../KitchenMediator.h"
#include "../ConcreteMediator.h"
#include "../CreateOrder.h"
#include "../Command.h"
#include "../BaseChef.h"
int main() {
  // Create a Caretaker and a Tab
  Caretaker caretaker;
  Tab tab;

  // Perform some actions on the tab
  tab.addOrderedItem("Item1", 10.0);
  tab.addOrderedItem("Item2", 15.0);

  // Save the initial state in the caretaker
  caretaker.addMemento(tab.createMemento());

  // Perform more actions on the tab
  tab.addOrderedItem("Item3", 20.0);

  // Save the updated state in the caretaker
  caretaker.addMemento(tab.createMemento());

  // Print the current tab state
  std::cout << "Current Tab State:" << std::endl;
  tab.printBill();

  // Rollback to the previous state
  TabMemento previousState = caretaker.getMemento(3);
  tab.setMemento(previousState);

  // Print the tab state after rollback
  std::cout << "\nTab State After Rollback:" << std::endl;
  tab.printBill();

  tab.setMemento(tab.createMemento());

  std::cout << "\nTab State After Rollback:" << std::endl;
  tab.printBill();
  //Mediator 
  KitchenMediator *mediator = new ConcreteMediator();
  Chef *chef=new BaseChef();
  Waiter *waiter=new Waiter((ConcreteMediator*)mediator);

  mediator->addColleague((Colleague*)chef);
  mediator->addColleague((Colleague*)waiter);
  Command *command = new  CreateOrder();
  Command *command2 = new CreateOrder();

  mediator->addCommand(command);
  mediator->addCommand(command2);

  waiter->WriteDownOrder("Burger");
  waiter->WriteDownOrder("Burger");
  
  return 0;
}
