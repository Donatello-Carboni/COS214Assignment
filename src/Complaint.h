#ifndef COMPLAINT_H
#define COMPLAINT_H

#include <string>

#include "Report.h"

class Complaint : public Report {
 private:
  std::string complaint;

 public:
  Complaint(std::string header, std::string body, std::string complaint);
  void report() const override;
  std::string getComplaint();
};

#endif