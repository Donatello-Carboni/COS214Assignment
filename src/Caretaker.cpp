#include "Caretaker.h"

void Caretaker::addMemento(TabMemento memento) {
  tabHistory.push_back(memento);
}

TabMemento Caretaker::getMemento() {
  if (tabHistory.size() == 0) {
    return *(new TabMemento());
  } else {
    return tabHistory[tabHistory.size() - 1];
  }
}
