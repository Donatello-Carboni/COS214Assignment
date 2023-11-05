#include "Report.h"

#include <iostream>

Report::Report(std::string header, std::string body)
    : header(header), body(body) {}

void Report::report() const {
  std::cout << "Header: " << header << std::endl;
  std::cout << "Body: " << body << std::endl;
}

std::string Report::getHeader() { return header; }

std::string Report::getBody() { return body; }