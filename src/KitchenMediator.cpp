#include "KitchenMediator.h"

#include <vector>

KitchenMediator::~KitchenMediator() {
  for (int i = 0; i < WaiterColleagues.size(); i++) {
    delete WaiterColleagues[i];
  }
  for (int i = 0; i < commands.size(); i++) {
    delete commands[i];
  }
}
KitchenMediator::KitchenMediator() {
  this->commands = std::vector<Command *>();
  this->WaiterColleagues = std::vector<Colleague *>();
}
KitchenMediator::KitchenMediator(Colleague *colleague[], Command *command[],Chef* chef) {
  this->commands = std::vector<Command *>();
  this->WaiterColleagues = std::vector<Colleague *>();
  for (int i = 0; i < 3; i++) {
    WaiterColleagues.push_back(
        colleague[i]);  // colleague 1 is for waiter colleague 2 is for chef
    commands.push_back(
        command[i]);  // command 1 is for adding to order and canceling from the
                      // order second is for complaints
  }
}

void KitchenMediator::addColleague(Colleague *colleague) {
  WaiterColleagues.push_back(colleague);
}

void KitchenMediator::addCommand(Command *command) {
  commands.push_back(command);
}

void KitchenMediator::removeColleague(Colleague *colleague) {
  bool bfound = false;
  int i = 0;
  while (!bfound && i < WaiterColleagues.size()) {
    if (WaiterColleagues[i] == colleague) {
      WaiterColleagues.erase(WaiterColleagues.begin() + i);
      bfound = true;
    }
    i++;
  }
}

void KitchenMediator::removeCommand(Command *command) {
  bool bfound = false;
  int i = 0;
  while (!bfound && i < commands.size()) {
    if (commands[i] == command) {
      commands.erase(commands.begin() + i);
      bfound = true;
    }
    i++;
  }
}

Chef* KitchenMediator::getChef()
{
  return chef;
}

void KitchenMediator::addChef(Chef* chef)
{
  this->chef = chef;
}

std::vector<Colleague *> KitchenMediator::getColleagues() { return WaiterColleagues; }

std::vector<Command *> KitchenMediator::getCommands() { return commands; }
