// tests/test_main.cpp

#include <gtest/gtest.h>

#include "../AboutToLeave.h"
#include "../BaseChef.h"
#include "../BunChef.h"
#include "../BurgerOrder.h"
#include "../Caretaker.h"
#include "../CheeseChef.h"
#include "../Chef.h"
#include "../Colleague.h"
#include "../Command.h"
#include "../Complaint.h"
#include "../CompositeTable.h"
#include "../ConcreteMediator.h"
#include "../CreateOrder.h"
#include "../Customer.h"
#include "../Default.h"
#include "../KitchenMediator.h"
#include "../Manager.h"
#include "../PattyChef.h"
#include "../Plate.h"
#include "../Report.h"
#include "../RestaurantTable.h"
#include "../Review.h"
#include "../SauceChef.h"
#include "../Tab.h"
#include "../TabMemento.h"
#include "../Table.h"
#include "../Waiter.h"
#include "../WaitingToOrder.h"
#include "../WaitingToSit.h"
#include "../Caretaker.h"
//=============================================
//===============CUSTOMER TEST=================
//=============================================

TEST(CustomerTest, getCustomerNumber) {
  Customer *c1 = new Customer(1);
  Customer *c2 = new Customer(2);

  // Checking if customer numbers are being set
  ASSERT_EQ(c1->getCustomerNumber(), 1);
  ASSERT_EQ(c2->getCustomerNumber(), 2);
}

TEST(CustomerTest, setOrder) {
  Customer *c = new Customer(1);

  std::vector<std::string> customerOrder;
  customerOrder.push_back("PATTY");
  customerOrder.push_back("TOMATO_SAUCE");
  customerOrder.push_back("REGULAR_BUN");
  customerOrder.push_back("SLICE_OF_CHEESE");
  c->setOrder(customerOrder);

  // Checking if the order is being set correctly
  ASSERT_EQ(c->getOrder(), customerOrder);
}

TEST(CustomerTest, stateInitialization) {
  Customer *c = new Customer(1);

  // Checking if state initialized correctly
  ASSERT_EQ(c->getState()->toString(), "[WAITING_TO_SIT]");
}

TEST(CustomerTest, setState) {
  Customer *c = new Customer(1);
  State *newState = new AboutToLeave();

  c->setState(newState);

  // Checking if setState is implemented correctly
  ASSERT_EQ(c->getState()->toString(), "[ABOUT_TO_LEAVE]");
}

TEST(CustomerTest, placeOrder) {
  Customer *c = new Customer(1);
  c->setState(new WaitingToOrder());
  c->placeOrder();

  // Checks if state switches to WaitingToOrder
  ASSERT_EQ(c->getState()->toString(), "[DEFAULT]");
}

TEST(CustomerTest, sitDown) {
  Customer *c = new Customer(1);
  c->sitDown();

  // Checks if state switches to WaitingToOrder
  ASSERT_EQ(c->getState()->toString(), "[WAITING_TO_ORDER]");
}

// TEST(CustomerTest, leave) {
//   Customer* c = new Customer(1);

//   //Checks if object calls destructor
//   ASSERT_EQ(c->leave(), NULL);
// }

TEST(CustomerTest, getTheBill_and_paid) {
  Customer *c = new Customer(1);
  c->setState(new Default());
  c->getTheBill();

  // Checks if paid param is set and if state changes
  ASSERT_EQ(c->didPay(), true);
  ASSERT_EQ(c->getState()->toString(), "[ABOUT_TO_LEAVE]");
}

//=============================================
//===========REPORT & MANAGER TEST=============
//=============================================

TEST(ReportManagerTest, SingletonInstance) {
  Manager &manager1 = Manager::getManager();
  Manager &manager2 = Manager::getManager();

  // The two instances should be the same
  ASSERT_EQ(&manager1, &manager2);
}

//=============================================
//============TAB & MEMENTO TEST===============
//=============================================

// Test case for creating and setting memento
TEST(TabTest, CreateAndSetMemento) {
  Tab tab;

  // Create memento
  TabMemento memento = tab.createMemento();

  // Set new values to the tab
  tab.setTabID(2);
  tab.setTotalPrice(25.0);

  // Set memento to restore previous state
  tab.setMemento(memento);

  // Check if the tab has been restored to the previous state
  EXPECT_EQ(tab.getTabID(), 0);
  EXPECT_EQ(tab.getTotalPrice(), 0);
}

// Test case for printing the bill
TEST(TabTest, PrintBill) {
  testing::internal::CaptureStdout();  // Redirect cout for testing

  Tab tab;
  tab.setTabID(1);
  tab.printBill();

  std::string output = testing::internal::GetCapturedStdout();

  // Check if the printed bill contains expected information
  //EXPECT_NE(output.find("Tab ID: 1"), std::string::npos);
  EXPECT_NE(output.find("Total Price: "), std::string::npos);
  EXPECT_NE(output.find("Ordered Items:"), std::string::npos);
}

//===============================================
//===========MEDIATOR & COMMAND TEST=============
//===============================================

TEST(MediatorTest, AddCommand) {
  KitchenMediator *mediator = new ConcreteMediator();

  Command *command = new CreateOrder();
  Command *command2 = new CreateOrder();

  mediator->addCommand(command);
  mediator->addCommand(command2);

  // Perform assertions to validate the number of commands
  ASSERT_EQ(mediator->getCommands().size(), 2);
  ASSERT_EQ(mediator->getCommands().at(0), command);
  ASSERT_EQ(mediator->getCommands().at(1), command2);
}

//======================================
//===========COMPOSITE TEST=============
//======================================

// Define a test fixture for RestaurantTable and CompositeTable
class TableTest : public ::testing::Test {
 protected:
  RestaurantTable *restaurantTable;
  CompositeTable *compositeTable;

  void SetUp() override {
    restaurantTable = new RestaurantTable(3);
    compositeTable = new CompositeTable();
  }

  void TearDown() override {
    delete restaurantTable;
    delete compositeTable;
  }
};

TEST_F(TableTest, RestaurantTableAddCustomer) {
  Customer customer;
  EXPECT_TRUE(restaurantTable->AddCustomer(&customer));
  EXPECT_TRUE(restaurantTable->AddCustomer(&customer));
  EXPECT_TRUE(restaurantTable->AddCustomer(&customer));
  EXPECT_FALSE(restaurantTable->AddCustomer(&customer));
}

TEST_F(TableTest, RestaurantTableRemoveCustomer) {
  Customer customer;
  restaurantTable->AddCustomer(&customer);
  EXPECT_TRUE(restaurantTable->RemoveCustomer(&customer));
  EXPECT_FALSE(
      restaurantTable->RemoveCustomer(&customer));  // Customer not found
}

TEST_F(TableTest, CompositeTableAddRemoveTable) {
  RestaurantTable *table1 = new RestaurantTable(2);
  RestaurantTable *table2 = new RestaurantTable(3);

  EXPECT_TRUE(compositeTable->AddTable(table1));
  EXPECT_TRUE(compositeTable->AddTable(table2));
  EXPECT_EQ(compositeTable->getState(), true);  // Should be available

  EXPECT_TRUE(compositeTable->RemoveTable(table1));
  EXPECT_FALSE(compositeTable->RemoveTable(table1));  // Table not found
}

TEST_F(TableTest, CompositeTableAddCustomer) {
  Customer customer1;
  Customer customer2;
  Customer customer3;

  EXPECT_TRUE(compositeTable->AddCustomer(&customer1));
  EXPECT_TRUE(compositeTable->AddCustomer(&customer2));
  EXPECT_TRUE(compositeTable->AddCustomer(&customer3));  // All tables are full

  EXPECT_TRUE(compositeTable->RemoveCustomer(&customer1));
  EXPECT_FALSE(
      compositeTable->RemoveCustomer(&customer1));  // Customer not found
}

//=====================================
//===========OBSERVER TEST=============
//=====================================

TEST_F(TableTest, WaiterUpdate) {
  // Create tables
  RestaurantTable table3(3);
  RestaurantTable table4(3);
  KitchenMediator *mediator = new ConcreteMediator();
  Caretaker *caretaker = new Caretaker();
  Waiter waiter((ConcreteMediator *)mediator, {&table3, &table4},caretaker);

  table4.setState(false);  // Make table4 occupied
  table4.setState(false);  // Make table4 occupied

  // Check if the tables are initially in the correct vectors
  EXPECT_EQ(waiter.getFreeTablesCount(), 1);
  EXPECT_EQ(waiter.getOccupiedTablesCount(), 1);

  // Change the state of the tables and simulate notification
  table3.setState(false);  // Make table3 occupied

  // Check if tables are moved to the correct vectors after the state change
  EXPECT_EQ(waiter.getFreeTablesCount(), 0);
  EXPECT_EQ(waiter.getOccupiedTablesCount(), 2);

  table3.setState(true);
  table4.setState(true);

  EXPECT_EQ(waiter.getFreeTablesCount(), 2);
  EXPECT_EQ(waiter.getOccupiedTablesCount(), 0);
}

//========================================
//=====CHAIN OF RESPONSIBILITY TEST=======
//========================================

class ChefTest : public ::testing::Test {
 protected:
  BunChef *bunChef;
  Plate *plate;
  void SetUp() override {
    bunChef = new BunChef();
    plate = new Plate();
  }

  void TearDown() override {
    delete plate;
    delete bunChef;
  }
  
};

TEST_F(ChefTest, BunChefTest) { EXPECT_EQ(plate->toString(), ""); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
