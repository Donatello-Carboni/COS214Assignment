#include "ConcreteMediator.h"
#include "CheeseChef.h"
#include <iostream>

void ConcreteMediator::notify(Colleague *colleague, int choice,
                              std::vector<std::string> order) {}

void ConcreteMediator::notifyOrder(Colleague *colleague, int choice,
                                   std::string order)
{
  CreateOrder *cmd = dynamic_cast<CreateOrder *>(getCommands().at(0));
  if (choice == 1)
  {
    // std::cout << "Write Order: " << order << std::endl;
    cmd->AddOrder(order);
  }
  else if (choice == 2)
  {
    // std::cout << "Remove order: " << order << std::endl;
    cmd->RemoveOrder(order);
  }
}

void ConcreteMediator::notifyDone(Colleague *colleague)
{
  CreateOrder *Cmd = (CreateOrder *)getCommands().at(0);
  std::string idStr = Cmd->getOrders().at(0);
  int ID = std::stoi(idStr);
  getCommands().at(0)->execute();
  CheeseChef *c = (CheeseChef *)this->getChef();
  Plate *plate = new Plate();
  // pass to chef to make burger
  c->addToPlate(Cmd->getBurgerOrder(), plate);
  Cmd->deleteOrder();
  // identify waiter
  int i = 0;
  while (this->getColleagues().at(i) != colleague)
  {
    i++;
  }
  //cout << "done finding waiter" << endl;
  Waiter *w = (Waiter *)this->getColleagues().at(i);
  //cout << "giving plate" << endl;
  //cout << plate->toString() << endl;
  w->storePlate(ID, plate);
  w->storeBurgerOrder(ID, Cmd->getBurgerOrder());
  //w->storeTab(ID, new Tab(Cmd->getBurgerOrder()));
  // cout << "Waiter plate map:" << endl;
  // w->printPlateMap();
}

void ConcreteMediator::notifyReport(Colleague *colleague){
    cout<<"Notify Report"<<endl;
    CreateComplaint *Cmd = (CreateComplaint *)getCommands().at(1);
    Cmd->setHappy(((Waiter*)colleague)->getHappy());
    Cmd->execute();
}