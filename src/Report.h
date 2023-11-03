#ifndef REPORT_H
#define REPORT_H

#include <string>

class Report {
 private:
  std::string header;
  std::string body;

 public:
  Report(std::string header, std::string body);
  virtual ~Report() = default;
  virtual void report() const;
  std::string getHeader();
  std::string getBody();
};

#endif