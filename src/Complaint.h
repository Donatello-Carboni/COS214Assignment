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
