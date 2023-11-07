#ifndef CREATEORDER_H
#define CREATEORDER_H
#include <string>
#include <vector>

#include "BurgerBunOrder.h"
#include "BurgerOrder.h"
#include "BurgerToppingOrder.h"
#include "CheeseOrder.h"
#include "Command.h"
#include "GherkinOrder.h"
#include "GlutenFreeBunOrder.h"
#include "LettuceOrder.h"
#include "MushroomOrder.h"
#include "MustardSauceOrder.h"
#include "OnionSliceOrder.h"
#include "PattyOrder.h"
#include "RegularBunOrder.h"
#include "TomatoSauceOrder.h"

/**
 * @brief Class to create and manage different types of burger orders, inheriting from Command.
 */
class CreateOrder : public Command {
 private:
  std::vector<std::string> orders; /**< List of orders. */
  BurgerOrder* burgerorder; /**< Pointer to the BurgerOrder object. */
  bool Inspection = false; /**< Boolean to check if the order has been inspected. */
  std::string yellow = "\033[33m";
  std::string red = "\033[31m";
  std::string white = "\033[37m";
  std::string bold = "\033[1m";
  std::string reset = "\033[0m";
  
 public:
  /**
   * @brief Constructor for the CreateOrder class.
   */
  CreateOrder();

  /**
   * @brief Destructor for the CreateOrder class.
   */
  ~CreateOrder();

  /**
   * @brief Execute the command to create the order.
   */
  void execute();

  /**
   * @brief Add an order to the list of orders.
   * @param order - The order to add.
   */
  void AddOrder(std::string order);

  /**
   * @brief Remove an order from the list.
   * @param order - The order to remove.
   */
  void RemoveOrder(std::string order);

  /**
   * @brief Get the list of orders.
   * @return A vector of strings representing the orders.
   */
  std::vector<std::string> getOrders();

  /**
   * @brief Delete the order.
   */
  void deleteOrder();

  /**
   * @brief Get the BurgerOrder object.
   * @return Pointer to the BurgerOrder object.
   */
  BurgerOrder* getBurgerOrder();
};

#endif
