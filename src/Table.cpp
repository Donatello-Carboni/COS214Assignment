#include "Table.h"

Table::Table() { myWaiter = nullptr; }

Table::~Table() { myWaiter = nullptr; }

void Table::attach(Observer* waiter) {
  if (!myWaiter) myWaiter = waiter;
}

void Table::detach(Observer* waiter) {
  if (myWaiter == waiter) myWaiter = nullptr;
}

void Table::notify() {
  if (myWaiter) myWaiter->update(this);
}

bool Table::getState() { return isAvailable; }

void Table::setState(bool state) {
  isAvailable = state;
  notify();
}
