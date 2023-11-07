#include "Manager.h"

#include <iostream>

Manager::~Manager() {
  for (auto report : reports) {
    delete report;
  }
  reports.clear();
}

void Manager::addReport(Report* report) { reports.push_back(report); }

void Manager::toString() const {
  //  std::cout<<"ONE PIEEEECE IS REEEAAAL"<<std::endl;
  for (auto report : reports) {
    report->report();
    std::cout << "--------------------------" << std::endl;
  }
}

Manager& Manager::getManager() {
  static Manager manager;
  return manager;
}