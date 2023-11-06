#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Plate.h"
#include "State.h"

using namespace std;

class State;
/**
 * @brief Class representing a customer in a restaurant.
 */
class Customer {
public:
  /**
   * @brief Default constructor for the Customer class.
   */
  Customer();

  /**
   * @brief Constructor for the Customer class with a specific customer number.
   * @param number - The customer number.
   */
  Customer(int number);

  /**
   * @brief Destructor for the Customer class.
   */
  ~Customer();

  /**
   * @brief Get the customer's number.
   * @return The customer number.
   */
  int getCustomerNumber();

  /**
   * @brief Get the customer's happiness level.
   * @return The happiness level.
   */
  int getHappiness();

  /**
   * @brief Change the customer's happiness level.
   * @param happy - The amount to change the happiness level by.
   */
  void changeHappiness(int happy);

  /**
   * @brief Get the current state of the customer.
   * @return A pointer to the current state.
   */
  State* getState();

  /**
   * @brief Set the customer's state.
   * @param currState - Pointer to the new state.
   */
  void setState(State* currState);

  /**
   * @brief Set the customer's order.
   * @param extras - A vector of strings representing the order.
   */
  void setOrder(std::vector<std::string> extras);

  /**
   * @brief Get the customer's order.
   * @return A vector of strings representing the order.
   */
  std::vector<std::string> getOrder();

  /**
   * @brief Method to simulate a customer sitting down.
   */
  void sitDown();

  /**
   * @brief Method to place an order.
   */
  void placeOrder();

  /**
   * @brief Method to cancel an item from the order.
   * @param item - The item to cancel.
   */
  void cancelOrder(std::string item);

  /**
   * @brief Method to request the bill.
   */
  void getTheBill();

  /**
   * @brief Method to print the customer's order.
   */
  void printOrder();

  /**
   * @brief Method to simulate the customer leaving the restaurant.
   */
  void leave();

  /**
   * @brief Check if the customer has paid the bill.
   * @return True if the bill has been paid, false otherwise.
   */
  bool didPay();

  /**
   * @brief Check if the customer wants a tab.
   * @return True if the customer wants a tab, false otherwise.
   */
  bool Tab();

  /**
   * @brief Method to give a plate to the customer.
   * @param plate - Pointer to the Plate object.
   */
  void givePlate(Plate* plate);

  /**
   * @brief Method to remove the customer's plate.
   * @return Pointer to the Plate object.
   */
  Plate* removePlate();

  /**
   * @brief Method to get the customer's plate.
   * @return Pointer to the Plate object.
   */
  Plate* getPlate();

private:
  std::string blue = "\033[34m";
  std::string bold = "\033[1m";
  std::string reset = "\033[0m";
  State* state; /**< The current state of the customer. */
  int happiness; /**< The happiness level of the customer. */
  std::vector<std::string> order; /**< The customer's order. */
  int customerNumber; /**< The customer's unique number. */
  bool paid; /**< Indicates if the bill has been paid. */
  bool WantsTab; /**< Indicates if the customer wants a tab. */
  Plate* plate; /**< The customer's plate. */
};

#endif
