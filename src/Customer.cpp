#include "Customer.h"
#include <cstdlib>  
#include <ctime>    
#include <random>
#include "WaitingToOrder.h"
#include "WaitingToSit.h"

Customer::Customer() { paid = false; }

Customer::Customer(int num) {
  customerNumber = num;
  happiness = 60;
  state = new WaitingToSit();

  // Seed the random number generator once at the beginning of your program
  static bool seeded = false;
  if (!seeded) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    seeded = true;
  }

  // Generate a random number (0 or 1) to determine the value of WantsTab
  int randomValue = std::rand() % 2;  // Generates 0 or 1

  // Set WantsTab based on the random value (0 or 1)
  this->WantsTab = (randomValue == 1);
}

Customer::~Customer() {
  cout << yellow << bold << "|  + " << white << "Customer (" << customerNumber << ")" << yellow << " left the restaurant..." << endl << reset;
}

int Customer::getHappiness() { return happiness; }

void Customer::changeHappiness(int happy) {
  random_device random;
  mt19937 happ(random());
  std::uniform_int_distribution<int> happiness(1, 100);
  int incOrDec = happiness(happ);

  if (incOrDec < 50)
      this->happiness += happy;
  else 
      this->happiness -= happy;

  if (this->happiness > 100)
    this->happiness = 100;
  else if (this->happiness <= 0)
    this->happiness = 0;
}

State* Customer::getState() { return state; }

void Customer::setState(State* currState) {
  if (currState != this->state) {
    if (this->state != NULL) delete this->state;
    this->state = currState;
  }
}

void Customer::setOrder(vector<string> extras) {
  cout << bold << blue << "[CUSTOMER]\t\t- Customer (" << customerNumber
       << ") is ready to order!" << endl << reset;
  order = extras;
}

vector<string> Customer::getOrder() { return order; }

void Customer::placeOrder() {
  //need to make sure its strings just being pushed
  cout << bold << blue << "[CUSTOMER]\t\t- Customer (" << customerNumber
       << ") is deciding what to order..." << endl << reset;
  state->chooseItems(this);
}

void Customer::cancelOrder(string item) { order.push_back(item); }

void Customer::getTheBill() {
  state->callForBill(this);
  state->payBill(this);  // Should change state to "AboutToLeave"
  state->review(this);
  paid = true;
}

int Customer::getCustomerNumber() { return customerNumber; }

void Customer::printOrder() {
  cout << "======CUSTOMER(" << customerNumber << ")======" << endl;
  std::vector<std::string>::iterator it;
  for (it = order.begin(); it != order.end(); it++) {
    cout << *(it) << endl;
  }
}

void Customer::sitDown() {
  cout << bold << blue;
  cout << "[CUSTOMER]\t\t- Customer (" << customerNumber
       << ") is sitting down at a table" << endl;
  state->chooseItems(this);
}

void Customer::leave() { this->~Customer(); }

bool Customer::didPay() { return paid; }

bool Customer::Tab()
{
  return WantsTab;
}

void Customer::givePlate(Plate* plate)
{
  this->plate = plate;
}

Plate* Customer::removePlate()
{
  Plate* plate = this->plate;
  this->plate = NULL;
  return plate;
}

Plate* Customer::getPlate()
{
  return this->plate;
}