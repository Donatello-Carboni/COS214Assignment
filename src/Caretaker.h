#ifndef CARETAKER_H
#define CARETAKER_H
#include <vector>

#include "TabMemento.h"

class Caretaker {
 private:
  std::vector<TabMemento> tabHistory;

 public:
  void addMemento(TabMemento memento);
  TabMemento getMemento();
};

#endif
