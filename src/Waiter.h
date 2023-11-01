#ifndef WAITER_H
#define WAITER_H
#include <vector>

#include "Observer.h"
#include "Table.h"

class Waiter : public Observer {
 private:
  std::vector<Table*> FreeTables;
  std::vector<Table*> OccupiedTables;

 public:
  Waiter(std::vector<Table*> FreeTables);
  ~Waiter();
  void update(Table* changedTable);
};

#endif
