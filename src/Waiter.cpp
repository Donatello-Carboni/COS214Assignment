#include "Waiter.h"

#include <algorithm>

#include "AboutToLeave.h"
#include "ConcreteMediator.h"
#include "Tab.h"
bool Waiter::Iterator = false;
bool Waiter::Observation = false;
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
      cout << yellow << bold<< "|  + Write Down Order: " << white << Singleorder << endl << reset;
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

Waiter::Waiter(ConcreteMediator* mediator, std::vector<Table*> freeTables,
               Caretaker* caretaker)
    : FreeTables(freeTables) {
  this->mediator = mediator;
  for (auto table : FreeTables) {
    table->attach(this);
  }
  this->currTable = 0;
  this->currInternalTable = 0;
  this->currCustomer = 0;
  this->caretaker = caretaker;
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
        cout << yellow << "|  + No free tables left" << reset << endl;
      }
    }
    std::string read;
    if(Observation==false){
      cout << endl << yellow << bold;
      cout << "|  + First group of customers seated observer triggered" << endl;
      cout << "|  =" << green << " Free tables: " << white << this->getFreeTablesCount() << endl << yellow;
      cout << "|  =" << red <<  " Occupied tables: " << white << this->getOccupiedTablesCount() << reset << endl;
      this->FreeTables[whichTable]->setState(false);
      cout << endl << yellow << bold;
      cout << "|  + Table distribution after observer was triggered" << endl;
      cout << "|  =" << green << " Free tables: " << white << this->getFreeTablesCount() << endl << yellow;
      cout << "|  =" << red << " Occupied tables: " << white << this->getOccupiedTablesCount() << reset << endl;
      cin >> read;
      Observation=true;
    }else{
      this->FreeTables[whichTable]->setState(false);
    }
  } else {
    cout << reset << yellow << bold << "|  + No free tables" << reset << endl;
  }
};

void Waiter::nextTable() {
  if (this->getOccupiedTablesCount() > 0) {
    if (this->currTable < this->getOccupiedTablesCount()) {
      this->currTable++;
    } else {
      this->currTable = 0;
    }
    // cout << "Current table: " << this->currTable << endl;
  } else {
    cout << yellow << "|  + No occupied tables" << reset << endl;
  }
}

Customer* Waiter::nextCustomer() {
// cout << "next customer" << endl;
// cout << "currTable in next customer: " << this->currTable << endl;
std:
  string read;
  if (Iterator == false) {
    cout << yellow << bold << "|  + Getting Customer" << endl;
    cout << "|  + Current iterator vars customer: " << white << this->currCustomer << endl << yellow
         << "|  + Internal Table: " << white << this->currInternalTable << endl << yellow
         << "|  + Composite table: " << white << this->currTable << endl;
    cout << "" << reset << endl;
    cin >> read;
  }
  CompositeTable* currComp =
      (CompositeTable*)this->OccupiedTables.at(this->currTable);

  RestaurantTable* currRestTable =
      (RestaurantTable*)currComp->getTables().at(this->currInternalTable);

  if (this->currCustomer + 1 > currRestTable->getCustomerCount()) {
    // cout << "next internal table" << endl;
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
  if (Iterator == false) {
    cout << bold << yellow;
    cout << "|  " << blue << "*" << reset << bold << " Starting 1st iteration of circuit..." << endl;
  } else {
    cout << bold << yellow;
    cout << "|  " << blue << "*" << reset << bold << " Starting 1st iteration of circuit..." << endl;
  }
  Customer* c = nullptr;
  while (this->currTable != 1) {
    c = this->nextCustomer();
    
    if (c == nullptr) {
      break;
    }
    if (this->currCustomer > 3) {
      // cout << "next table" << endl;
      
      this->nextTable();
    }
    cout << yellow << bold;
    cout << "|  + Serving " << white << "Customer " << c->getCustomerNumber() << endl;
    std::string stateStr = c->getState()->toString();
    if (stateStr == "[WAITING_TO_ORDER]") {
      TabMemento t = this->caretaker->getMemento();
      if (t.getTabID() >= 0) {
        cout << yellow << "|  "<< red << "! There exists a tab that has to be paid off " << white << "by Customer "
             << c->getCustomerNumber() << red << " of total " << white << t.getTotalPrice()
             << endl << reset;
      }
      c->placeOrder();
      this->WriteDownOrder(c->getOrder());
    } else if (stateStr == "[DEFAULT]") {
      // return plate customer
      Plate* plate = this->getPlate(c->getCustomerNumber());
      if (plate != nullptr) {
        c->givePlate(plate);
      }
      cout << yellow << bold;
      cout << "|  + Waiter plate map:" << endl;
      this->printPlateMap();
      c->setState(new AboutToLeave());
    } else if (stateStr == "[ABOUT_TO_LEAVE]") {
      if (c->Tab()) {
        cout << yellow << bold << "|  + " << white << c->getCustomerNumber() << yellow << " is making a tab for "
             << (this->getTab(c->getCustomerNumber()))->getTotalPrice()
             << yellow << " for " << green << c->getPlate()->toString() << endl << reset;
        this->printTabMap();
        Tab* tab = this->getTab(c->getCustomerNumber());
        this->caretaker->addMemento(tab->createMemento());
        this->removeTab(c->getCustomerNumber());
      } else {
        cout << bold << yellow << "|  + " << white << c->getCustomerNumber() << yellow << " is paying a total of "
             << white << (this->getTab(c->getCustomerNumber()))->getTotalPrice()
             << yellow << " for " << green << c->getPlate()->toString() << endl << reset;
        this->removeTab(c->getCustomerNumber());
      }
      this->storeHappy(c->getHappiness());
      c->leave();
    }
    cout << yellow << bold << "|  " << green << "! Finished serving customer" << endl << reset;
    if (c->getCustomerNumber() == 0) {
      string ready;
      this->mediator->inspected=true;
      cout << yellow << bold <<  "|  + First customer served" << endl << reset;
      cin >> ready;
      cout << white << bold << "Resuming simulation..." << endl;
    }
    cout << yellow << bold << "|  " << green << "! Finished serving customer" << endl << reset;
  }
  if (c == nullptr && this->OccupiedTables.size() == 1) {
    this->currCustomer = 0;
    this->currInternalTable = 0;
    this->currTable = 0;
    return;
  }
  cout << yellow << bold << "|  + Finishing circuit itertions circuit" << endl << reset;
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
        // logic for checking tab
        c->placeOrder();
        this->WriteDownOrder(c->getOrder());
      } else if (stateStr == "[DEFAULT]") {
        // return plate customer
        Plate* plate = this->getPlate(c->getCustomerNumber());
        if (plate != nullptr) {
          c->givePlate(plate);
        }
        cout << yellow << bold << "|  + " << white << "Waiter" << yellow << " plate map:" << endl;
        this->printPlateMap();
        c->setState(new AboutToLeave());
      } else if (stateStr == "[ABOUT_TO_LEAVE]") {
        if (c->Tab()) {
          cout << yellow << bold << "|  + " << white << c->getCustomerNumber() << yellow << " is making a tab for "
               << white << (this->getTab(c->getCustomerNumber()))->getTotalPrice()
               << yellow << " for " << green << c->getPlate()->toString() << endl << reset;
          this->printTabMap();
          Tab* tab = this->getTab(c->getCustomerNumber());
          this->caretaker->addMemento(tab->createMemento());
          this->removeTab(c->getCustomerNumber());
        } else {
          cout << bold << yellow << "|  + " << white <<c->getCustomerNumber() << yellow << " is paying a total of "
               << white << (this->getTab(c->getCustomerNumber()))->getTotalPrice()
               << yellow << " for " << green << c->getPlate()->toString() << endl;
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
  std::cout << yellow << bold << "|  + Plate Map Contents:" << std::endl << reset;
  for (const auto& pair : plateMap) {
    std::cout << cyan << bold << "|  = ID: " << white << pair.first << yellow << ", " << cyan << "Plate: " << white << pair.second->toString()
              << std::endl;
  }
}

void Waiter::printBurgerMap() {
  std::cout << yellow << bold << "|  + Burger Map Contents:" << std::endl << reset;
  for (const auto& pair : BurgerMap) {
    std::cout << cyan << bold << "|  = ID: " << white << pair.first << yellow << ", " << cyan << "Burger: " << white << pair.second->toString()
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
  std::cout << yellow << bold << "|  + Tab Map Contents:" << std::endl << reset;
  for (const auto& pair : TabMap) {
    std::cout << blue << bold << "|  = ID: " << white << pair.first << yellow << ", " << blue << "Tab: "; 
    pair.second->printBill();
    std::cout << std::endl << reset;
  }
}

Tab* Waiter::getTab(int customerID) {
  auto it = TabMap.find(customerID);
  if (it != TabMap.end()) {
    Tab* tab = it->second;
    return tab;
  } else {
    return nullptr;  // Tab not found
  }
}

void Waiter::removeTab(int tabID) { TabMap.erase(tabID); }

void Waiter::storeTab(int customerID, Tab* tab) { TabMap[customerID] = tab; }

int Waiter::getHappy() {
  if (!HappyVec.empty()) {
    int happy = HappyVec.back();  // Get the last element
    HappyVec.pop_back();          // Remove the last element
    return happy;
  } else {
    return -1;
  }
}

void Waiter::storeHappy(int ID) {
  HappyVec.push_back(ID);
  this->mediator->notifyReport((Colleague*)this);
}