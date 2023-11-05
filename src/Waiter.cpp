#include "Waiter.h"

#include <algorithm>

#include "ConcreteMediator.h"
void Waiter::WriteDownOrder(std::vector<std::string> order) {
  for (int i = 0; i < order.size(); i++) {
    std::string Singleorder = order[i];
    // check if order item is cancel or add
    // check if single order contains "cancel-x"
    if (Singleorder.find("cancel-") != std::string::npos) {
      // remove cancel- from string
      Singleorder.erase(0, 7);
      this->CancelItem(Singleorder);
    } else {
      this->mediator->notifyOrder((Colleague*)this, 1, Singleorder);
    }
  }

  this->DoneOrder();
}

void Waiter::CancelItem(std::string order) {
  this->mediator->notifyOrder((Colleague*)this, 2, order);
}

void Waiter::DoneOrder() { this->mediator->notifyDone((Colleague*)this); }

Waiter::Waiter(ConcreteMediator* mediator, std::vector<Table*> freeTables)
    : FreeTables(freeTables) {
  this->mediator = mediator;
  for (auto table : FreeTables) {
    table->attach(this);
  }
  this->currTable = 0;
  this->currInternalTable = 0;
  this->currCustomer = 0;
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

void Waiter::givePlate(Plate* plate) { this->plate = plate; }

Plate* Waiter::getPlate() { return this->plate; }
// iterator
void Waiter::seatCustomer(vector<Customer*> customers) {
  if (this->getFreeTablesCount() > 0) {
    int whichTable = 0;
    for (int i = 0; i < customers.size(); i++) {
      if (this->FreeTables[whichTable]->AddCustomer(customers[i])) {
        customers[i]->sitDown();
        customers[i]->placeOrder();
      } else {
        cout << "No free tables" << endl;
      }
    }
    this->FreeTables[whichTable]->setState(false);
  }
};

void Waiter::nextTable() {
  if (this->getOccupiedTablesCount() > 0) {
    if (this->currTable < this->getOccupiedTablesCount()) {
      this->currTable++;
    } else {
      this->currTable = 0;
    }
    cout << "Current table: " << this->currTable << endl;
  } else {
    cout << "No occupied tables" << endl;
  }
}

Customer* Waiter::nextCustomer() {
  cout << "next customer" << endl;
  cout << "currTable in next customer: " << this->currTable << endl;
  CompositeTable* currComp =
      (CompositeTable*)this->OccupiedTables.at(this->currTable);

  RestaurantTable* currRestTable =
      (RestaurantTable*)currComp->getTables().at(this->currInternalTable);
  // check if there are customers at current restaurant table
  cout << "current Restables count: " << currRestTable->getCustomerCount()
       << endl;

  if (this->currCustomer + 1 > currRestTable->getCustomerCount()) {
    cout << "next internal table" << endl;
    this->currCustomer = 0;
    this->currInternalTable++;
    cout << "composite tables tables size" << currComp->getTables().size()
         << endl;
    if (this->currInternalTable + 1 > currComp->getTables().size()) {
      cout << "returning null" << endl;
      return nullptr;
    }
  }
  cout << "getting customer from current table" << endl;
  cout << "currCustomer: " << this->currCustomer << endl;
  cout << "currInternalTable: " << this->currInternalTable << endl;
  Customer* c = currRestTable->getCustomers().at(this->currCustomer);
  this->currCustomer++;
  cout << "returning customer" << endl;
  return c;
}

void Waiter::CompleteCircuit() {
  cout << "Starting 1st iteration of circuit" << endl;
  Customer* c = nullptr;
  while (this->currTable != 1) {
    c = this->nextCustomer();
    if (c == nullptr) {
      break;
    }
    if (this->currCustomer == 0) {
      cout << "next table" << endl;
      this->nextTable();
    } else {
      cout << "serving customer" << endl;
      std::string stateStr = c->getState()->toString();
      if (stateStr == "[WAITING_TO_ORDER]") {
        this->WriteDownOrder(c->getOrder());
      } else if (stateStr == "[DEFAULT]") {
      } else if (stateStr == "[ABOUT_TO_LEAVE]") {
      }
      cout << "done serving customer" << endl;
    }
  }
  if (c == nullptr) {
    return;
  }
  cout << "Finishing circuit itertions circuit" << endl;
  while (this->currTable != 0) {
    Customer* c = this->nextCustomer();

    if (this->currCustomer == 0) {
      this->nextTable();
    } else {
      std::string stateStr = c->getState()->toString();

      if (stateStr == "[WAITING_TO_ORDER]") {
        this->WriteDownOrder(c->getOrder());
      } else if (stateStr == "[DEFAULT]") {
      } else if (stateStr == "[ABOUT_TO_LEAVE]") {
      }
    }
  }
}
