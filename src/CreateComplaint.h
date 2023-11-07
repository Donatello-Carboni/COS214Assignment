
#ifndef CREATECOMPLAINT_H
#define CREATECOMPLAINT_H
#include "Command.h"
#include "BurgerOrder.h"
#include "Manager.h"
#include "Report.h"
#include "Complaint.h"
#include "Review.h"
#include <vector>
#include <string>

/**
 * @brief Class to create a complaint about a burger order, inheriting from Command.
 */
class CreateComplaint : public Command {
private:
  int happy; /**< The happiness level of the Customer making the report. */
  BurgerOrder *burgerorder; /**< Pointer to the BurgerOrder object. */
  bool Inspection = false; /**< Boolean to check if the order has been inspected. */
  std::string cyan = "\033[36m";
  std::string blue = "\033[34m";
  std::string bold = "\033[1m";
  std::string yellow = "\033[33m";
  std::string green = "\033[32m";
  std::string red = "\033[31m";
  std::string white = "\033[37m";
  std::string magenta = "\033[35m";
  std::string reset = "\033[0m";


public:
  /**
   * @brief Constructor for the CreateComplaint class.
   */
  CreateComplaint();

  /**
   * @brief Destructor for the CreateComplaint class.
   */
  ~CreateComplaint();

  /**
   * @brief Execute the command to create the complaint.
   */
  void execute();
  
  /**
   * @brief Sets the happiness level of the customer.
   * 
   * @param Happy The happiness level of the customer.
   */
  void setHappy(int Happy);

  /**
   * @brief Builds a report based on the happiness level of the customer.
   * 
   * @param Happy The happiness level of the customer.
   * @return Report* A pointer to the generated report.
   */
  Report* buildReport(int Happy);
};

#endif

