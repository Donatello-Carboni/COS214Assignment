#ifndef CREATECOMPLAINT_H
#define CREATECOMPLAINT_H
#include "Command.h"
#include "BurgerOrder.h"
#include "Manager.h"
#include "Report.h"
#include "Complaint.h"
#include "Review.h"
#include <vector>
#include <string>
class CreateComplaint : public Command {
 private:
  int happy;
 public:
  CreateComplaint();
  ~CreateComplaint();
  void execute();
  Report* buildReport(int Happy);
  void setHappy(int Happy);
};
#endif