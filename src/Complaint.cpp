#include "Complaint.h"

#include <iostream>

Complaint::Complaint(std::string header, std::string body,
                     std::string complaint)
    : Report(header, body), complaint(complaint) {}

void Complaint::report() const {
  Report::report();
  std::cout << "Complaint: " << complaint << std::endl;
}

std::string Complaint::getComplaint() { return complaint; }
