#include "Report.h"

#include <iostream>

Report::Report(std::string header, std::string body)
    : header(header), body(body) {}

void Report::report() const {
  std::cout << green << bold << "|  = Header: " << white << header << std::endl;
  std::cout << cyan << bold << "|  = Body: " << white << body << std::endl;
}

std::string Report::getHeader() { return header; }

std::string Report::getBody() { return body; }