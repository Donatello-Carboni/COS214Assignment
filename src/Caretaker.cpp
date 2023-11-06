#include "Caretaker.h"

void Caretaker::addMemento(TabMemento memento) {
  tabHistory.push_back(memento);
}

TabMemento Caretaker::getMemento(int numberOfRollbacks) {
  if (numberOfRollbacks > tabHistory.size()) {
    numberOfRollbacks = tabHistory.size();
  }
  TabMemento memento;
  for (int i = 0; i < numberOfRollbacks; i++) {
    memento = tabHistory.back();
    tabHistory.pop_back();
  }
  return memento;
}
