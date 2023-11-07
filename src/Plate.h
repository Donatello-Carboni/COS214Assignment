#ifndef PLATE_H
#define PLATE_H

#include <iostream>
#include <string>
#include "EdibleBurger.h"

/**
 * @brief Class representing a plate to assemble burger ingredients.
 */
class Plate {
private:
  Bun* bun; /**< Pointer to the bun on the plate. */
  Patty* patty; /**< Pointer to the patty on the plate. */
  Cheese* cheese; /**< Pointer to the cheese on the plate. */
  Extra* extra; /**< Pointer to the extra topping on the plate. */
  Sauce* sauce; /**< Pointer to the sauce on the plate. */

public:
  /**
   * @brief Constructor for the Plate class.
   */
  Plate();

  /**
   * @brief Method to add cheese to the plate.
   */
  void addCheese();

  /**
   * @brief Method to add a patty to the plate.
   */
  void addPatty();

  /**
   * @brief Method to add an extra topping to the plate.
   * @param extra - The extra topping to add.
   */
  void addExtra(std::string extra);

  /**
   * @brief Method to add sauce to the plate.
   * @param sauce - The sauce to add.
   */
  void addSauce(std::string sauce);

  /**
   * @brief Method to add a bun to the plate.
   * @param bun - The type of bun to add.
   */
  void addBun(std::string bun);

  /**
   * @brief Method to generate a string representation of the plate's contents.
   * @return A string describing the contents of the plate.
   */
  std::string toString();
};

#endif
