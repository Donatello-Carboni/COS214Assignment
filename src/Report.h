#ifndef REPORT_H
#define REPORT_H

#include <string>

/**
 * @brief Class representing a generic report.
 */
class Report {
 private:
  std::string header; /**< The header content of the report. */
  std::string body; /**< The body content of the report. */
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
   * @brief Constructor for the Report class.
   * @param header - The header content of the report.
   * @param body - The body content of the report.
   */
  Report(std::string header, std::string body);

  /**
   * @brief Virtual destructor for the Report class.
   */
  virtual ~Report() = default;

  /**
   * @brief Method to display the report details.
   */
  virtual void report() const;

  /**
   * @brief Get the header content of the report.
   * @return The header content of the report.
   */
  std::string getHeader();

  /**
   * @brief Get the body content of the report.
   * @return The body content of the report.
   */
  std::string getBody();
};

#endif
