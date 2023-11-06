
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

