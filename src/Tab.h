#ifndef TAB_H
#define TAB_H
#include <iostream>
#include <string>
#include <vector>

#include "BurgerOrder.h"
#include "TabMemento.h"

/**
 * @brief Class representing a tab for an order in a restaurant.
 */
class Tab {
 private:
  int tabID; /**< The ID of the tab. */
  float totalPrice; /**< The total price of the tab. */
  std::vector<float> itemCost; /**< The costs of individual items in the tab. */
  std::vector<std::string> orderedItems; /**< The list of ordered items in the tab. */

 public:
  /**
   * @brief Creates a memento representing the state of the tab.
   * @return A TabMemento object representing the current state.
   */
  TabMemento createMemento();

  /**
   * @brief Sets the state of the tab to a previous memento state.
   * @param memento - The TabMemento object representing the state to set.
   */
  void setMemento(TabMemento memento);

  /**
   * @brief Adds an item to the list of ordered items with its price.
   * @param orderedItem - The name of the item ordered.
   * @param price - The price of the item.
   */
  void addOrderedItem(std::string orderedItem, float price);

  /**
   * @brief Sets the ID for the tab.
   * @param tabID - The ID to set for the tab.
   */
  void setTabID(int tabID);

  /**
   * @brief Gets the ID of the tab.
   * @return The ID of the tab.
   */
  int getTabID();

  /**
   * @brief Sets the total price for the tab.
   * @param totalPrice - The total price to set.
   */
  void setTotalPrice(float totalPrice);

  /**
   * @brief Gets the total price of the tab.
   * @return The total price of the tab.
   */
  float getTotalPrice();

  /**
   * @brief Sets the costs of individual items in the tab.
   * @param itemCost - The item costs to set.
   */
  void setItemCost(std::vector<float> itemCost);

  /**
   * @brief Gets the costs of individual items in the tab.
   * @return The costs of individual items in the tab.
   */
  std::vector<float> getItemCost();

  /**
   * @brief Sets the list of ordered items in the tab.
   * @param orderedItems - The list of ordered items to set.
   */
  void setOrderedItems(std::vector<std::string> orderedItems);

  /**
   * @brief Gets the list of ordered items in the tab.
   * @return The list of ordered items in the tab.
   */
  std::vector<std::string> getOrderedItems();

  /**
   * @brief Calculates the total price based on the individual item costs.
   * @return The recalculated total price of the tab.
   */
  float calculateTotalPrice();

  /**
   * @brief Prints the bill with details of ordered items and the total price.
   */
  void printBill();
};

#endif
