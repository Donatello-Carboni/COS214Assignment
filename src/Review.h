#ifndef REVIEW_H
#define REVIEW_H

#include <string>
#include "Report.h"

/**
 * @brief Class representing a review report, inheriting from the Report base class.
 */
class Review : public Report {
private:
  int rating; /**< The rating associated with the review. */
  std::string cyan = "\033[36m";
  std::string blue = "\033[34m";
  std::string bold = "\033[1m";
  std::string yellow = "\033[33m";
  std::string green = "\033[32m";
  std::string red = "\033[31m";
  std::string white = "\033[37m";
  std::string reset = "\033[0m";


public:
  /**
   * @brief Constructor for the Review class.
   * @param header - The header of the review.
   * @param body - The body content of the review.
   * @param rating - The rating associated with the review.
   */
  Review(std::string header, std::string body, int rating);

  /**
   * @brief Method to present the review report details.
   */
  void report() const override;

  /**
   * @brief Get the rating associated with the review.
   * @return The rating value.
   */
  int getRating();
};

#endif
