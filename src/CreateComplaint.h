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
  std::vector<std::string> complaint; /**< List to store the complaint. */
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
};

#endif
