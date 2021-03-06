/* STUDENTS:  DO NOT EDIT THIS FILE.  INSTEAD, MODIFY YOUR OWN PROJECT
 * CODE TO FIT THE SPECIFICATION GIVEN BY THE TESTS IN THIS FILE.
 *
 * If you DO modify it, we overwrite it with a fresh version from our repo
 * when grading, so you can't use it to fudge the tests anyway.
 *
 * This file is used by the CS3081W auto-grading system.
 *
 * Please note, the assessment tests for grading, will use the same include
 * files, class names, and function names for accessing students' code that you
 * find in this file.  So students, if you write your code so that it passes
 * these feedback tests, you can be assured that the auto-grader will at least
 * be able to properly link with your code.
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
#include "../src/random_passenger_generator.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BusTests : public ::testing::Test {
protected:

  Bus *def_bus, *param_bus;
  Route *out, *in;

  virtual void SetUp() {
    Stop ** CC_EB_stops = new Stop *[1];
    std::list<Stop *> CC_EB_stops_list;
    Stop stop_CC_EB_1(0, 43, -92.5);
    CC_EB_stops_list.push_back(&stop_CC_EB_1);
    CC_EB_stops[0] = &stop_CC_EB_1;
    double * CC_EB_distances = new double[1];
    CC_EB_distances[0] = 5;
    std::list<double> CC_EB_probs;
    CC_EB_probs.push_back(.15);
    RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
    out = new Route("out", CC_EB_stops, CC_EB_distances, 1, &CC_EB_generator);
    in = new Route("im", CC_EB_stops, CC_EB_distances, 1, &CC_EB_generator);
    def_bus = new Bus("bus", in, out);
    param_bus = new Bus("bus2", in, out, 30, 10);
  }

  virtual void TearDown() {
    delete out;
    delete in;
    delete def_bus;
    delete param_bus;
    out = NULL;
    in = NULL;
    def_bus = NULL;
    param_bus = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(BusTests, DefaultConstructorTests) {
  EXPECT_EQ(def_bus->GetCapacity(), 60) << "Default constructor: capacity incorrect" << endl;
  testing::internal::CaptureStdout();
  def_bus->Report(cout);
  string output1 = testing::internal::GetCapturedStdout();
  string bus_expected_output_name = "Name: bus";
  string bus_expected_output_speed = "Speed: 1";
  string bus_expected_output_dist = "Distance to next stop: 0";
  int p1 = output1.find(bus_expected_output_name);
  int p2 = output1.find(bus_expected_output_speed);
  int p3 = output1.find(bus_expected_output_dist);
  EXPECT_GE(p1,0) << "Expected name incorrect for default bus constructor" << endl;
  EXPECT_GE(p2,0) << "Expected speed incorrect for default bus constructor" << endl;
  EXPECT_GE(p3,0) << "Expected distance to next stop incorrect for default bus constructor" << endl;
};

TEST_F(BusTests, ParameterizedConstructorTests) {
  EXPECT_EQ(param_bus->GetCapacity(), 30) << "Default constructor: capacity incorrect" << endl;
  testing::internal::CaptureStdout();
  param_bus->Report(cout);
  string output1 = testing::internal::GetCapturedStdout();
  string bus_expected_output_name = "Name: bus2";
  string bus_expected_output_speed = "Speed: 10";
  string bus_expected_output_dist = "Distance to next stop: 0";
  int p1 = output1.find(bus_expected_output_name);
  int p2 = output1.find(bus_expected_output_speed);
  int p3 = output1.find(bus_expected_output_dist);
  EXPECT_GE(p1,0) << "Expected name incorrect for default bus constructor" << endl;
  EXPECT_GE(p2,0) << "Expected speed incorrect for default bus constructor" << endl;
  EXPECT_GE(p3,0) << "Expected distance to next stop incorrect for default bus constructor" << endl;
};

TEST_F(BusTests, IsTripCompleteTests) {
  EXPECT_EQ(param_bus->IsTripComplete(), false) << "Default constructor: capacity incorrect" << endl;
};
