#ifndef TABMEMENTO_H
#define TABMEMENTO_H
#include <string>
#include <vector>

#include "BurgerOrder.h"

/**
 * @brief Class representing a memento for storing the state of a Tab.
 */
class TabMemento {
 private:
  int tabID; /**< The ID of the Tab. */
  float totalPrice; /**< The total price of the Tab. */
  std::vector<BurgerOrder*> orderedItems;  /**< The list of ordered items in the Tab. */

 public:

    /**
   * @brief Constructor for the TabMemento object.
   */
  TabMemento() {
    tabID = 0;
    totalPrice = 0;
  };
  /**
   * @brief Set the Tab ID for the memento.
   * @param tabID - The ID of the Tab to set.
   */
  void setTabID(int tabID);

  /**
   * @brief Get the Tab ID from the memento.
   * @return The ID of the Tab.
   */
  int getTabID();

  /**
   * @brief Set the total price for the memento.
   * @param totalPrice - The total price to set.
   */
  void setTotalPrice(float totalPrice);

  /**
   * @brief Get the total price from the memento.
   * @return The total price of the Tab.
   */
  float getTotalPrice();


  /**
   * @brief Set the ordered items for the memento.
   * @param orderedItems - The ordered items to set.
   */
    void setOrderedItems(
      const std::vector<BurgerOrder*>& orderedItems);

  /**
   * @brief Get the ordered items from the memento.
   * @return The list of ordered items in the Tab.
   */
  std::vector<BurgerOrder*> getOrderedItems();
};

#endif

