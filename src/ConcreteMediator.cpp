#include "ConcreteMediator.h"

#include <iostream>

#include "CheeseChef.h"

void ConcreteMediator::notify(Colleague *colleague, int choice,
                              std::vector<std::string> order) {}

void ConcreteMediator::notifyOrder(Colleague *colleague, int choice,
                                   std::string order) {
  CreateOrder *cmd = dynamic_cast<CreateOrder *>(getCommands().at(0));
  if (choice == 1) {
    std::string read = "";
    if (this->inspected == false) {
      std::cout << "Notifier is calling write order to command" << std::endl;
      std::cin >> read;
    }

    cmd->AddOrder(order);
  } else if (choice == 2) {
    std::string read = "";
    if (this->inspected == false) {
      std::cout << "Notifier is calling Remove order to command" << std::endl;
      std::cin >> read;
    }

    cmd->RemoveOrder(order);
  }
}

void ConcreteMediator::notifyDone(Colleague *colleague) {
  CreateOrder *Cmd = (CreateOrder *)getCommands().at(0);
  std::string idStr = Cmd->getOrders().at(0);
  int ID = std::stoi(idStr);
  getCommands().at(0)->execute();
  CheeseChef *c = (CheeseChef *)this->getChef();
  Plate *plate = new Plate();
  // pass to chef to make burger

  std::string read = "";
  if (this->inspected == false) {
    std::cout << "Passing empty Plate to Chef chain." << std::endl;
    std::cin >> read;
  }

  c->addToPlate(Cmd->getBurgerOrder(), plate);
  Cmd->deleteOrder();
  // identify waiter
  int i = 0;
  while (this->getColleagues().at(i) != colleague) {
    i++;
  }

  if (this->inspected == false) {
    std::cout << "Finding correct waiter..." << std::endl;
    std::cin >> read;
  }

  Waiter *w = (Waiter *)this->getColleagues().at(i);

  if (this->inspected == false) {
    std::cout << "Giving populated Plate to waiter." << std::endl;
    std::cin >> read;
  }

  // cout << "giving plate" << endl;
  // cout << plate->toString() << endl;
  w->storePlate(ID, plate);
  w->storeBurgerOrder(ID, Cmd->getBurgerOrder());
  Tab *tab = new Tab();
  tab->setTabID(ID);
  tab->addOrderedItem(Cmd->getBurgerOrder());
  tab->calculateTotalPrice();
  w->storeTab(ID, tab);
  // w->printTabMap();
  // cout << "Waiter plate map:" << endl;
  // w->printPlateMap();
}

void ConcreteMediator::notifyReport(Colleague *colleague) {
  cout << "Notify Report" << endl;
  CreateComplaint *Cmd = (CreateComplaint *)getCommands().at(1);
  Cmd->setHappy(((Waiter *)colleague)->getHappy());
  Cmd->execute();
}