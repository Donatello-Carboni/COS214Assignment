#ifndef EDIBLEBURGER_H
#define EDIBLEBURGER_H
#include <iostream>
#include <string>
#include <vector>
/**
 * @brief Class representing the Bun for a burger.
 */
class Bun {
 private:
  std::string type; /**< The type of bun. */

 public:
  /**
   * @brief Constructor for the Bun class.
   * @param type - The type of bun.
   */
  Bun(std::string type);

  /**
   * @brief Get a string representation of the bun.
   * @return A string describing the bun.
   */
  std::string toString();
};

/**
 * @brief Class representing the Patty for a burger.
 */
class Patty {
 public:
  /**
   * @brief Constructor for the Patty class.
   */
  Patty();

  /**
   * @brief Get a string representation of the patty.
   * @return A string describing the patty.
   */
  std::string toString();
};

/**
 * @brief Class representing the Cheese for a burger.
 */
class Cheese {
 public:
  /**
   * @brief Constructor for the Cheese class.
   */
  Cheese();

  /**
   * @brief Get a string representation of the cheese.
   * @return A string describing the cheese.
   */
  std::string toString();
};

/**
 * @brief Class representing Extra toppings for a burger.
 */
class Extra {
 private:
  std::vector<std::string> extras; /**< The list of extra toppings. */

 public:
  /**
   * @brief Constructor for the Extra class.
   * @param extra - The extra topping to add.
   */
  Extra(std::string extra);

  /**
   * @brief Get a string representation of the extra toppings.
   * @return A string describing the extra toppings.
   */
  std::string toString();

  /**
   * @brief Method to add an extra topping.
   * @param extra - The extra topping to add.
   */
  void addExtra(std::string extra);
  // Other methods and data members
};

/**
 * @brief Class representing Sauces for a burger.
 */
class Sauce {
 private:
  std::vector<std::string> sauces; /**< The list of sauces. */

 public:
  /**
   * @brief Constructor for the Sauce class.
   * @param extra - The sauce to add.
   */
  Sauce(std::string extra);

  /**
   * @brief Method to add a sauce.
   * @param sauce - The sauce to add.
   */
  void addSauce(std::string sauce);

  /**
   * @brief Get a string representation of the sauces.
   * @return A string describing the sauces.
   */
  std::string toString();
};

#endif
