#ifndef REVIEW_H
#define REVIEW_H

#include <string>

#include "Report.h"

class Review : public Report {
 private:
  int rating;

 public:
  Review(std::string header, std::string body, int rating);
  void report() const override;
  int getRating();
};

#endif