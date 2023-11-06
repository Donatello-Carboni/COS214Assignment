
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
  std::vector<BurgerOrder*> orderedItems; /**< The list of ordered items in the tab. */

 public:
    /**
   * @brief Constructor for the Tab object.
   */
  Tab() {
    tabID = 0;
    totalPrice = 0;
  };
  /**
   * @brief Creates a memento representing the state of the tab.
   * @return A TabMemento object representing the current state.
   */
  TabMemento createMemento();

  /**
   * @brief Sets the state of the tab to a previous memento state.
   * @param memento - The TabMemento object representing the state to set.
   */
  void setMemento(TabMemento& memento);

  /**
   * @brief Adds an item to the list of ordered items.
   * @param orderedItem - The name of the item ordered.
   */
  void addOrderedItem(BurgerOrder* orderedItem);

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
   * @brief Sets the list of ordered items in the tab.
   * @param orderedItems - The list of ordered items to set.
   */
  void setOrderedItems(
      const std::vector<BurgerOrder*>& orderedItems);  // Pass by pointer

  /**
   * @brief Gets the list of ordered items in the tab.
   * @return The list of ordered items in the tab.
   */
  std::vector<BurgerOrder*> getOrderedItems();  // Change to pointer


  /**
   * @brief Prints the bill with details of ordered items and the total price.
   */
  void printBill();
};

#endif
