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

TEST(ManagerTest, AddAndPrintReports) {
  Manager &manager = Manager::getManager();

  Report *review = new Review("Movie Review", "Great movie!", 5);
  Report *complaint =
      new Complaint("Service Complaint", "Poor service", "Late delivery");

  manager.addReport(review);
  manager.addReport(complaint);

  // Redirect std::cout to a stringstream for testing
  std::stringstream buffer;
  std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

  manager.toString();

  // Reset std::cout
  std::cout.rdbuf(old);

  // Check if the output matches the expected result
  std::string expectedOutput =
      "Header: Movie Review\nBody: Great movie!\nRating: "
      "5\n--------------------------\n"
      "Header: Service Complaint\nBody: Poor service\nComplaint: Late "
      "delivery\n--------------------------\n";

  ASSERT_EQ(buffer.str(), expectedOutput);
}

//=============================================
//============TAB & MEMENTO TEST===============
//=============================================

TEST(TabTest, CreateMemento) {
  Tab tab;
  tab.addOrderedItem("Item1", 10.0);
  tab.addOrderedItem("Item2", 15.0);

  TabMemento memento = tab.createMemento();

  // Perform assertions to validate the memento
  ASSERT_EQ(memento.getTabID(), tab.getTabID());
  ASSERT_EQ(memento.getTotalPrice(), tab.getTotalPrice());
  ASSERT_EQ(memento.getItemCost(), tab.getItemCost());
  ASSERT_EQ(memento.getOrderedItems(), tab.getOrderedItems());
}

TEST(TabTest, SetMemento) {
  Tab tab;
  TabMemento memento;
  memento.setTabID(1);
  memento.setTotalPrice(25.0);
  memento.setItemCost({10.0, 15.0});
  memento.setOrderedItems({"Item1", "Item2"});

  tab.setMemento(memento);

  // Perform assertions to validate the tab state after setting the memento
  ASSERT_EQ(memento.getTabID(), tab.getTabID());
  ASSERT_EQ(memento.getTotalPrice(), tab.getTotalPrice());
  ASSERT_EQ(memento.getItemCost(), tab.getItemCost());
  ASSERT_EQ(memento.getOrderedItems(), tab.getOrderedItems());
}

// Add more test cases for other functions in Tab class

//=============================================
//=========CARETAKER & MEMENTO TEST============
//=============================================

TEST(CaretakerTest, AddAndGetMemento) {
  Caretaker caretaker;
  Tab tab;

  // Perform some actions on the tab
  tab.addOrderedItem("Item1", 10.0);
  tab.addOrderedItem("Item2", 15.0);
  caretaker.addMemento(tab.createMemento());

  // Perform more actions on the tab
  tab.addOrderedItem("Item3", 20.0);
  caretaker.addMemento(tab.createMemento());

  // Retrieve the previous state
  TabMemento memento = caretaker.getMemento(1);

  // Perform assertions to validate the retrieved memento
  // (similar to the previous tests)
}

//=================================================
//===========MEDIATOR & COLLEAGUE TEST=============
//=================================================

// TEST(MediatorTest, AddColleague) {
//   KitchenMediator *mediator = new ConcreteMediator();
//   Chef *chef = new BaseChef();
//   Waiter *waiter = new Waiter((ConcreteMediator *)mediator);

//   mediator->addColleague((Colleague *)chef);
//   mediator->addColleague((Colleague *)waiter);

//   // Perform assertions to validate the number of colleagues
//   ASSERT_EQ(mediator->getColleagues().size(), 2);
//   ASSERT_EQ(mediator->getColleagues().at(0), (Colleague *)chef);
//   ASSERT_EQ(mediator->getColleagues().at(1), (Colleague *)waiter);
//   // delete mediator;
//   // delete mediator;
// }

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
  // delete mediator;
  // ASSERT_EQ(1, 1);
  // delete mediator;
  // ASSERT_EQ(1, 1);
}

// TEST(MediatorTest, CommsToDecor) {
//   KitchenMediator *mediator = new ConcreteMediator();
//   Chef *chef = new BaseChef();
//   Waiter *waiter = new Waiter((ConcreteMediator *)mediator);

//   mediator->addColleague((Colleague *)chef);
//   mediator->addColleague((Colleague *)waiter);
//   Command *command = new CreateOrder();
//   Command *command2 = new CreateOrder();

//   mediator->addCommand(command);
//   mediator->addCommand(command2);

//   waiter->WriteDownOrder("Burger");
//   waiter->WriteDownOrder("Burger");
//   Command *command3 = mediator->getCommands().at(0);
//   CreateOrder *command4 = (CreateOrder *)command3;
//   // Perform assertions to validate the number of colleagues
//   // std::string test = command4->burger->test;
//   // ASSERT_EQ(test, "BurgerBurger");
//   // delete mediator;
// }

//====================================
//===========COMMAND TEST=============
//====================================

// TEST(COMMAND, decorcmd) {
//   KitchenMediator *mediator = new ConcreteMediator();
//   Chef *chef = new BaseChef();
//   Waiter *waiter = new Waiter((ConcreteMediator *)mediator);

//   mediator->addColleague((Colleague *)chef);
//   mediator->addColleague((Colleague *)waiter);
//   Command *command = new CreateOrder();
//   Command *command2 = new CreateOrder();

//   mediator->addCommand(command);
//   mediator->addCommand(command2);

//   waiter->WriteDownOrder("ID-1");
//   waiter->WriteDownOrder("RegularBun");
//   waiter->WriteDownOrder("Cheese");
//   waiter->DoneOrder();
//   bool truefalse = false;
//   if (waiter->getPlate() != NULL) {
//     truefalse = true;
//   }
//   EXPECT_TRUE(truefalse);
// }

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
  Waiter waiter((ConcreteMediator*)mediator,{&table3, &table4});

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
  Plate* plate;
  void SetUp() override {
    bunChef = new BunChef();
    plate = new Plate();
  }


  void TearDown() override {
    delete plate;
    delete bunChef;
  }
  
};

TEST_F(ChefTest, BunChefTest) {
  EXPECT_EQ(plate->toString(), "");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
