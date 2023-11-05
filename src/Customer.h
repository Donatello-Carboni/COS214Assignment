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
        void changeHappiness(int happy);
        State* getState();
        void setState(State* currState);
        void setOrder(std::vector<std::string> extras);
        std::vector<std::string> getOrder();
        void setState(State* currState);
        State* getState();
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