#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>

#include "State.h"

using namespace std;

class State;
class Customer {
 public:
  Customer();
  Customer(int);
  ~Customer();
  int getCustomerNumber();
  int getHappiness();
  void changeHappiness(int happy);
  State* getState();
  void setState(State* currState);
  void setOrder(std::vector<std::string> extras);
  std::vector<std::string> getOrder();
  void sitDown();
  void placeOrder();
  void cancelOrder(std::string item);
  void getTheBill();
  void printOrder();
  void leave();
  bool didPay();

 private:
  State* state;
  int happiness;
  std::vector<std::string> order;
  int customerNumber;
  bool paid;
};

#endif