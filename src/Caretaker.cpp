#include "Caretaker.h"

void Caretaker::addMemento(TabMemento memento) {
  tabHistory.push_back(memento);
}

TabMemento Caretaker::getMemento() { return tabHistory[tabHistory.size() - 1]; }
 