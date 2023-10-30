#include <iostream>
#include <string>
#include <vector>

#include "../Caretaker.h"
#include "../Tab.h"
#include "../TabMemento.h"

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

  return 0;
}
