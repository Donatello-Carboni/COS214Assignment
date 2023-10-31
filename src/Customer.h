#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "State.h"
#include <string>
#include <vector>

using namespace std;

class State;
class Customer {
    public:
        Customer();
        Customer(int);
        ~Customer();
        int getCustomerNumber();
        int getHappiness();
        void setHappiness(int happy);
        State* getState();
        void setState(State* currState);
        void setOrder(std::vector<std::string> extras);
        std::vector<std::string> getOrder();
        void placeOrder();
        void getTheBill();
        void leave();
        void printOrder();
    
    private:
        State* state;
        int happiness;
        std::vector<std::string> order;
        int customerNumber;
};

#endif