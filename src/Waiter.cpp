#include "Waiter.h"
#include "ConcreteMediator.h"
#include <algorithm>
Waiter::Waiter(ConcreteMediator *mediator)
{
    this->mediator = mediator;
}

void Waiter::WriteDownOrder(std::string order)
{
    this->mediator->notifyOrder((Colleague*)this,1,order);
}

void Waiter::CancelItem(std::string order)
{
    this->mediator->notifyOrder((Colleague*)this,2,order);
}

void Waiter::DoneOrder()
{
    this->mediator->notifyDone((Colleague*)this);
}

Waiter::Waiter(std::vector<Table*> freeTables) : FreeTables(freeTables) {
  for (auto table : FreeTables) {
    table->attach(this);
  }
}

Waiter::~Waiter() {
  for (auto table : FreeTables) {
    table->detach(this);
  }
  FreeTables.clear();

  for (auto table : OccupiedTables) {
    table->detach(this);
  }
  OccupiedTables.clear();
}

void Waiter::update(Table* changedTable) {
  if (!changedTable->getState()) {
    auto freeTableIter =
        std::find(FreeTables.begin(), FreeTables.end(), changedTable);

    if (freeTableIter != FreeTables.end()) {
      FreeTables.erase(freeTableIter);
      OccupiedTables.push_back(changedTable);
    }
  } else {
    auto occupiedTableIter =
        std::find(OccupiedTables.begin(), OccupiedTables.end(), changedTable);

    if (occupiedTableIter != OccupiedTables.end()) {
      OccupiedTables.erase(occupiedTableIter);
      FreeTables.push_back(changedTable);
    }
  }
}

int Waiter::getFreeTablesCount() const { return FreeTables.size(); }

int Waiter::getOccupiedTablesCount() const { return OccupiedTables.size(); }

void Waiter::givePlate(Plate* plate)
{
  this->plate=plate;
}
