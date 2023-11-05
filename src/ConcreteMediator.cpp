#include "ConcreteMediator.h"

#include <iostream>

void ConcreteMediator::notify(Colleague *colleague, int choice,
                              std::vector<std::string> order) {}

void ConcreteMediator::HandleCommand(int choice) {}

void ConcreteMediator::notifyOrder(Colleague *colleague, int choice,
                                   std::string order) {
  CreateOrder *cmd = dynamic_cast<CreateOrder *>(getCommands().at(0));
  if (choice == 1) {
    // std::cout << "Write Order: " << order << std::endl;
    cmd->AddOrder(order);
  } else if (choice == 2) {
    // std::cout << "Remove order: " << order << std::endl;
    cmd->RemoveOrder(order);
  }
}

void ConcreteMediator::notifyDone(Colleague *colleague) {
  cout << "processing" << endl;
  getCommands().at(0)->execute();
  cout << "done processing" << endl;
  CreateOrder *Cmd = (CreateOrder *)getCommands().at(0);
  BaseChef *c = (BaseChef *)this->getColleagues().at(1);
  Plate *plate = new Plate();
  // pass to chef to make burger
  c->addToPlate(Cmd->getBurgerOrder(), plate);
  Cmd->deleteOrder();
  cout << "done adding to plate" << endl;
  // identify waiter
  int i = 0;
  while (this->getColleagues().at(i) != colleague) {
    i++;
  }
  cout << "done finding waiter" << endl;
  Waiter *w = (Waiter *)this->getColleagues().at(i);
  cout << "giving plate" << endl;
  w->givePlate(plate);
}
