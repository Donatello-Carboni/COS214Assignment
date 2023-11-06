#ifndef KITCHENMEDIATOR_H
#define KITCHENMEDIATOR_H
#include <string>
#include <vector>
#include "BaseChef.h"
#include "Colleague.h"
#include "Command.h"
#include "Waiter.h"

/**
 * @brief Class representing a mediator for communication between kitchen colleagues and chef.
 */
class KitchenMediator {
 private:
  std::vector<Colleague *> WaiterColleagues; /**< Collection of waiter colleagues. */
  std::vector<Command *> commands; /**< Collection of commands. */
  Chef *chef; /**< The chef responsible for cooking. */

 public:
  /**
   * @brief Constructor for KitchenMediator class.
   */
  KitchenMediator();

  /**
   * @brief Constructor for KitchenMediator class with initial colleagues, commands, and chef.
   * @param colleague - An array of colleague objects.
   * @param command - An array of command objects.
   * @param chef - Pointer to the chef.
   */
  KitchenMediator(Colleague *colleague[], Command *command[], Chef *chef);

  /**
   * @brief Destructor for KitchenMediator class.
   */
  virtual ~KitchenMediator();

  /**
   * @brief Method to notify colleagues and chef about orders.
   * @param colleague - The colleague notifying about an order.
   * @param choice - The choice of the order.
   * @param order - A vector of strings representing the order.
   */
  virtual void notify(Colleague *colleague, int choice, std::vector<std::string> order) = 0;

  /**
   * @brief Method to add a colleague to the mediator.
   * @param colleague - Pointer to the colleague object to add.
   */
  void addColleague(Colleague *colleague);

  /**
   * @brief Method to add a command to the mediator.
   * @param command - Pointer to the command object to add.
   */
  void addCommand(Command *command);

  /**
   * @brief Method to remove a colleague from the mediator.
   * @param colleague - Pointer to the colleague object to remove.
   */
  void removeColleague(Colleague *colleague);

  /**
   * @brief Method to remove a command from the mediator.
   * @param command - Pointer to the command object to remove.
   */
  void removeCommand(Command *command);

  /**
   * @brief Get the collection of colleagues.
   * @return A vector of colleague objects.
   */
  std::vector<Colleague *> getColleagues();

  /**
   * @brief Get the collection of commands.
   * @return A vector of command objects.
   */
  std::vector<Command *> getCommands();

  /**
   * @brief Get the chef responsible for cooking.
   * @return Pointer to the chef.
   */
  Chef* getChef();

  /**
   * @brief Method to add a chef to the mediator.
   * @param chef - Pointer to the chef.
   */
  void addChef(Chef* chef);
};

#endif