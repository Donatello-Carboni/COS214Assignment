#include "Waiter.h"
#include "Tab.h"
#include <algorithm>

#include "AboutToLeave.h"
#include "ConcreteMediator.h"
void Waiter::WriteDownOrder(std::vector<std::string> order) {
  for (int i = 0; i < order.size(); i++) {
    std::string Singleorder = order[i];
    // check if order item is cancel or add
    // check if single order contains "cancel-x"
    if (Singleorder.find("CANCEL-") != std::string::npos) {
      // remove cancel- from string
      Singleorder.erase(0, 7);
      
      this->CancelItem(Singleorder);
    } else {
      // cout<<"Write Down Order: "<<Singleorder<<endl;
      cout<<"Write Down Order: "<<Singleorder<<endl;
      this->mediator->notifyOrder((Colleague*)this, 1, Singleorder);
    }
  }

  this->DoneOrder();
}

void Waiter::CancelItem(std::string order) {
  // cout<<"Cancel Item "+order<<endl;
  this->mediator->notifyOrder((Colleague*)this, 2, order);
}

void Waiter::DoneOrder() { this->mediator->notifyDone((Colleague*)this); }

Waiter::Waiter(ConcreteMediator* mediator, std::vector<Table*> freeTables,Caretaker* caretaker)
    : FreeTables(freeTables) {
  this->mediator = mediator;
  for (auto table : FreeTables) {
    table->attach(this);
  }
  this->currTable = 0;
  this->currInternalTable = 0;
  this->currCustomer = 0;
  this->caretaker=caretaker;
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

// iterator
void Waiter::seatCustomer(vector<Customer*> customers) {
  if (this->getFreeTablesCount() > 0) {
    int whichTable = 0;
    for (int i = 0; i < customers.size(); i++) {
      if (this->FreeTables[whichTable]->AddCustomer(customers[i])) {
        customers[i]->sitDown();
      } else {
        cout << "No free tables left" << endl;
      }
    }
    this->FreeTables[whichTable]->setState(false);
  } else {
    cout << "No free tables" << endl;
  }
};

void Waiter::nextTable() {
  if (this->getOccupiedTablesCount() > 0) {
    if (this->currTable < this->getOccupiedTablesCount()) {
      this->currTable++;
    } else {
      this->currTable = 0;
    }
    //cout << "Current table: " << this->currTable << endl;
  } else {
    cout << "No occupied tables" << endl;
  }
}

Customer* Waiter::nextCustomer() {
  // cout << "next customer" << endl;
  // cout << "currTable in next customer: " << this->currTable << endl;
  CompositeTable* currComp =
      (CompositeTable*)this->OccupiedTables.at(this->currTable);

  RestaurantTable* currRestTable =
      (RestaurantTable*)currComp->getTables().at(this->currInternalTable);

  if (this->currCustomer + 1 > currRestTable->getCustomerCount()) {
    //cout << "next internal table" << endl;
    this->currCustomer = 0;
    this->currInternalTable++;
    // cout << "composite tables tables size" << currComp->getTables().size()
    //      << endl;
    if (this->currInternalTable + 1 > currComp->getTables().size()) {
      // cout << "returning null" << endl;
      return nullptr;
    }
  }
  currRestTable =
      (RestaurantTable*)currComp->getTables().at(this->currInternalTable);
  // cout << "getting customer from current table" << endl;
  // cout << "currCustomer: " << this->currCustomer << endl;
  // cout << "currInternalTable: " << this->currInternalTable << endl;
  Customer* c = currRestTable->getCustomers().at(this->currCustomer);
  this->currCustomer++;
 // cout << "returning customer" << endl;
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
    if (this->currCustomer > 3) {
      cout << "next table" << endl;
      this->nextTable();
    }
    
    cout << "serving customer " << c->getCustomerNumber() << endl;
    std::string stateStr = c->getState()->toString();
    if (stateStr == "[WAITING_TO_ORDER]") {
      TabMemento t=this->caretaker->getMemento();
      if(t.getTabID()>=0){
        cout<<"There exists a tab that need to be paid of by customer "<<c->getCustomerNumber()<<" of total "<<t.getTotalPrice()<<endl;
      }
      c->placeOrder();
      this->WriteDownOrder(c->getOrder());
    } else if (stateStr == "[DEFAULT]") {
      // return plate customer
      Plate* plate = this->getPlate(c->getCustomerNumber());
      if (plate != nullptr) {
        c->givePlate(plate);
      }
      cout << "Waiter plate map:" << endl;
      this->printPlateMap();
      c->setState(new AboutToLeave());
    } else if (stateStr == "[ABOUT_TO_LEAVE]") {

      if (c->Tab()) {
        cout<<c->getCustomerNumber()<<" is making a tab for "<<(this->getTab(c->getCustomerNumber()))->getTotalPrice()<<" for "+c->getPlate()->toString()<<endl;
        this->printTabMap();
        Tab* tab=this->getTab(c->getCustomerNumber());
        this->caretaker->addMemento(tab->createMemento());
        this->removeTab(c->getCustomerNumber());
      } else {
        cout<<c->getCustomerNumber()<<" is paying a total of "<<(this->getTab(c->getCustomerNumber()))->getTotalPrice()<<" for "+c->getPlate()->toString()<<endl;
        this->removeTab(c->getCustomerNumber());
      }
      this->storeHappy(c->getHappiness());
      c->leave();
    }
    cout << "done serving customer" << endl;
    if(c->getCustomerNumber()==0){
      string ready;
         cout << "first customer served. Enter when inspected" << endl;
    cin>>ready;
  cout << "Resuming simulation..." << endl;
    }
    cout << "done serving customer" << endl;
  }
  if (c == nullptr && this->OccupiedTables.size() == 1) {
    this->currCustomer = 0;
    this->currInternalTable = 0;
    this->currTable = 0;
    return;
  }
  cout << "Finishing circuit itertions circuit" << endl;
  this->currTable++;
  this->currInternalTable = 0;
  this->currCustomer = 0;
  while (this->currTable != 0) {
    Customer* c = this->nextCustomer();
    if (c == nullptr) {
      break;
    }
    if (this->currCustomer == 0) {
      this->nextTable();
    } else {
      std::string stateStr = c->getState()->toString();

      if (stateStr == "[WAITING_TO_ORDER]") {
        //logic for checking tab
        c->placeOrder();
        this->WriteDownOrder(c->getOrder());
      } else if (stateStr == "[DEFAULT]") {
        // return plate customer
        Plate* plate = this->getPlate(c->getCustomerNumber());
        if (plate != nullptr) {
          c->givePlate(plate);
        }
        cout << "Waiter plate map:" << endl;
        this->printPlateMap();
        c->setState(new AboutToLeave());
      } else if (stateStr == "[ABOUT_TO_LEAVE]") {

        if (c->Tab()) {
        cout<<c->getCustomerNumber()<<" is making a tab for "<<(this->getTab(c->getCustomerNumber()))->getTotalPrice()<<" for "+c->getPlate()->toString()<<endl;
        this->printTabMap();
        Tab* tab=this->getTab(c->getCustomerNumber());
        this->caretaker->addMemento(tab->createMemento());
       this->removeTab(c->getCustomerNumber());
      } else {
        cout<<c->getCustomerNumber()<<" is paying a total of "<<(this->getTab(c->getCustomerNumber()))->getTotalPrice()<<" for "+c->getPlate()->toString()<<endl;
        this->removeTab(c->getCustomerNumber());
      }
      this->storeHappy(c->getHappiness());
      c->leave();
      }
    }
  }
  this->currCustomer = 0;
  this->currInternalTable = 0;
  this->currTable = 0;
}

void Waiter::storePlate(int plateID, Plate* plate) {
  plateMap[plateID] = plate;
}

Plate* Waiter::getPlate(int plateID) {
  auto it = plateMap.find(plateID);
  if (it != plateMap.end()) {
    Plate* plate = it->second;
    removePlate(plateID);
    return plate;  // Return the Plate associated with the ID
  } else {
    return nullptr;  // Plate not found
  }
}

void Waiter::removePlate(int plateID) { plateMap.erase(plateID); }

void Waiter::printPlateMap() {
  std::cout << "Plate Map Contents:" << std::endl;
  for (const auto& pair : plateMap) {
    std::cout << "ID: " << pair.first << ", Plate: " << pair.second->toString()
              << std::endl;
  }
}

void Waiter::printBurgerMap() {
  std::cout << "Burger Map Contents:" << std::endl;
  for (const auto& pair : BurgerMap) {
    std::cout << "ID: " << pair.first << ", Burger: " << pair.second->toString()
              << std::endl;
  }
}

BurgerOrder* Waiter::getBurgerOrder(int orderID) {
  auto it = BurgerMap.find(orderID);
  if (it != BurgerMap.end()) {
    BurgerOrder* order = it->second;
    removeBurgerOrder(orderID);
    return order;  // Return the Plate associated with the ID
  } else {
    return nullptr;  // Plate not found
  }
}

void Waiter::removeBurgerOrder(int orderID) { BurgerMap.erase(orderID); }

void Waiter::storeBurgerOrder(int orderID, BurgerOrder* order) {
  BurgerMap[orderID] = order;
}

void Waiter::printTabMap() {
  std::cout << "Tab Map Contents:" << std::endl;
  for (const auto& pair : TabMap) {
    std::cout << "ID: " << pair.first << ", Tab: " << pair.second << std::endl;
  }
}

Tab* Waiter::getTab(int customerID) {
  auto it = TabMap.find(customerID);
  if (it != TabMap.end()) {
    Tab* tab = it->second;
    return tab;
  } else {
    return nullptr; // Tab not found
  }
}

void Waiter::removeTab(int tabID) { TabMap.erase(tabID); }

void Waiter::storeTab(int customerID, Tab* tab) {
  TabMap[customerID] = tab;
}

int Waiter::getHappy()
{
 if (!HappyVec.empty()) {
    int happy = HappyVec.back();   // Get the last element
    HappyVec.pop_back();           // Remove the last element
    return happy;
  } else {
    return -1;
  }
}

void Waiter::storeHappy(int ID)
{
  HappyVec.push_back(ID);
  this->mediator->notifyReport((Colleague*)this);
}