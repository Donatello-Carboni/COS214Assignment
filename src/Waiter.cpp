#include "Waiter.h"

#include <algorithm>

Waiter::Waiter(std::vector<Table*> freeTables) : FreeTables(freeTables) {
    for (auto table : FreeTables) {
        table->attach(this);
    }
}

Waiter::~Waiter() {
  for (auto table : FreeTables) {
    table->detach(this);
    delete table;
  }
  FreeTables.clear();

  for (auto table : OccupiedTables) {
    table->detach(this);
    delete table;
  }
  OccupiedTables.clear();
}


void Waiter::update(Table* changedTable) {
  if (changedTable->getState()) {
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
