#ifndef MANAGER_H
#define MANAGER_H

#include <vector>

#include "Report.h"

class Manager {
 private:
  std::vector<Report*> reports;

  Manager(){};
  ~Manager();
  Manager(const Manager& other) = delete;
  Manager& operator=(const Manager& other) = delete;

 public:
  void addReport(Report* report);
  void toString() const;
  static Manager& getManager();
};

#endif