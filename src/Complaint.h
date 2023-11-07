#ifndef COMPLAINT_H
#define COMPLAINT_H

#include <string>

#include "Report.h"

/**
 * @brief Class representing a complaint, inheriting from Report.
 */
class Complaint : public Report {
private:
  std::string complaint; /**< The complaint message. */
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
   * @brief Constructor for the Complaint class.
   * @param header - The header for the complaint report.
   * @param body - The body of the complaint report.
   * @param complaint - The detailed complaint message.
   */
  Complaint(std::string header, std::string body, std::string complaint);

  /**
   * @brief Overridden method to report the complaint.
   */
  void report() const override;

  /**
   * @brief Get the detailed complaint message.
   * @return The complaint message as a string.
   */
  std::string getComplaint();
};

#endif
