#include "Review.h"

#include <iostream>

Review::Review(std::string header, std::string body, int rating)
    : Report(header, body), rating(rating) {}

void Review::report() const {
  Report::report();
  std::cout << blue << bold << "Rating: " << white << rating << std::endl;
}

int Review::getRating() { return rating; }