/*
 * Students: Use this file as a guide to writing your own unit tests.
 * See the project instructions for more information on which classes
 * and methods must be tested.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *def_passenger, *param_passenger;
  string def_expected_output_name, param_expected_output_name,
   initial_expected_output_wait, initial_expected_output_time,
   def_expected_output_destination, param_expected_output_destination,
   initial_expected_output_total_wait;

  virtual void SetUp() {
    def_passenger = new Passenger();
    param_passenger = new Passenger(101, "Bob");
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
    def_expected_output_name = "Name: Nobody";
    def_expected_output_destination = "Destination: -1";
    param_expected_output_name = "Name: Bob";
    param_expected_output_destination = "Destination: 101";
    initial_expected_output_total_wait = "Total Wait: 0";
    initial_expected_output_wait = "\tWait at Stop: 0";
    initial_expected_output_time = "\tTime on bus: 0";
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete def_passenger;
    delete param_passenger;
    def_passenger = NULL;
    param_passenger = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(PassengerTests, DefaultConstructorTests) {
  EXPECT_EQ(def_passenger->GetDestination(), -1) << "Destination ID incorrect for default constructor" << endl;
  testing::internal::CaptureStdout();
  def_passenger->Report(cout);
  string output1 = testing::internal::GetCapturedStdout();
  int p1 = output1.find(def_expected_output_name);
  int p2 = output1.find(initial_expected_output_wait);
  int p3 = output1.find(initial_expected_output_time);
  EXPECT_GE(p1,0) << "Expected name incorrect for default constructor" << endl;
  EXPECT_GE(p2,0) << "Expected wait_at_stop_ incorrect for default constructor" << endl;
  EXPECT_GE(p3,0) << "Expected time_on_bus_ incorrect for default constructor" << endl;
};
<<<<<<< HEAD

TEST_F(PassengerTests, ParameterizedConstructorTests) {
  EXPECT_EQ(param_passenger->GetDestination(), 101) << "Destination ID incorrect for parameterized constructor" << endl;
  testing::internal::CaptureStdout();
  param_passenger->Report(cout);
  string output1 = testing::internal::GetCapturedStdout();
  int p1 = output1.find(param_expected_output_name);
  int p2 = output1.find(initial_expected_output_wait);
  int p3 = output1.find(initial_expected_output_time);
  EXPECT_GE(p1,0) << "Expected name incorrect for parameterized constructor" << endl;
  EXPECT_GE(p2,0) << "Expected wait_at_stop_ incorrect for parameterized constructor" << endl;
  EXPECT_GE(p3,0) << "Expected time_on_bus_ incorrect for parameterized constructor" << endl;
};

TEST_F(PassengerTests, ReportTests) {
  testing::internal::CaptureStdout();
  def_passenger->Report(cout);
  string output1 = testing::internal::GetCapturedStdout();
  int p1 = output1.find(def_expected_output_name);
  int p2 = output1.find(def_expected_output_destination);
  int p3 = output1.find(initial_expected_output_total_wait);
  int p4 = output1.find(initial_expected_output_wait);
  int p5 = output1.find(initial_expected_output_time);
  EXPECT_GE(p1,0) << "Expected name incorrect for default constructor" << endl;
  EXPECT_GE(p2,0) << "Expected wait_at_stop_ incorrect for default constructor" << endl;
  EXPECT_GE(p3,0) << "Expected total wait incorrect for default constructor" << endl;
  EXPECT_GE(p4,0) << "Expected wait_at_stop_ incorrect for default constructor" << endl;
  EXPECT_GE(p5,0) << "Expected time_on_bus_ incorrect for default constructor" << endl;
};

TEST_F(PassengerTests, IsOnBusTests) {
  EXPECT_EQ(def_passenger->IsOnBus(), false) << "IsOnBus() incorrect for passenger not on a bus" << endl;
  def_passenger->GetOnBus();
  EXPECT_EQ(def_passenger->IsOnBus(), true) << "IsOnBus() incorrect for passenger on a bus" << endl;
};

TEST_F(PassengerTests, GetOnBusTests) {
  testing::internal::CaptureStdout();
  def_passenger->Report(cout);
  string output1 = testing::internal::GetCapturedStdout();
  int p1 = output1.find(initial_expected_output_time);
  EXPECT_GE(p1,0) << "Expected time_on_bus_ incorrect for default constructor" << endl;
  EXPECT_EQ(def_passenger->IsOnBus(), false) << "IsOnBus() incorrect for passenger not on a bus" << endl;
  def_passenger->GetOnBus();
  testing::internal::CaptureStdout();
  def_passenger->Report(cout);
  string output2 = testing::internal::GetCapturedStdout();
  string expected_output_time_2 = "\tTime on bus: 1";
  int p2 = output2.find(expected_output_time_2);
  EXPECT_GE(p2,0) << "Expected time_on_bus_ incorrect after call to GetOnBus()" << endl;
  EXPECT_EQ(def_passenger->IsOnBus(), true) << "GetOnBus() incorrect: passenger not on bus after call to GetOnBus()" << endl;
};

TEST_F(PassengerTests, UpdateTests) {
  testing::internal::CaptureStdout();
  def_passenger->Report(cout);
  string output1 = testing::internal::GetCapturedStdout();
  int p1 = output1.find(initial_expected_output_wait);
  EXPECT_GE(p1,0) << "Expected wait_at_stop_ incorrect for default constructor" << endl;
  def_passenger->Update();
  testing::internal::CaptureStdout();
  def_passenger->Report(cout);
  string output2 = testing::internal::GetCapturedStdout();
  string expected_output_wait_2 = "\tWait at Stop: 1";
  int p2 = output2.find(expected_output_wait_2);
  EXPECT_GE(p2,0) << "Expected wait_at_stop_ incorrect after first call to Update()" << endl;
  def_passenger->GetOnBus();
  testing::internal::CaptureStdout();
  def_passenger->Report(cout);
  string output3 = testing::internal::GetCapturedStdout();
  string expected_output_time = "\tTime on bus: 1";
  int p3 = output3.find(expected_output_time);
  EXPECT_GE(p3,0) << "Expected time_on_bus_ incorrect after first call to GetOnBus()" << endl;
  EXPECT_EQ(def_passenger->IsOnBus(), true) << "IsOnBus() incorrect: not true after GetOnBus()" << endl;
  def_passenger->Update();
  testing::internal::CaptureStdout();
  def_passenger->Report(cout);
  string output4 = testing::internal::GetCapturedStdout();
  string expected_output_time_2 = "\tTime on bus: 2";
  int p4 = output4.find(expected_output_time_2);
  EXPECT_GE(p4,0) << "Expected time_on_bus_ incorrect after second call to GetOnBus()" << endl;
};
=======
>>>>>>> support-code
