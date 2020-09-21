/**
 * @file random_passenger_generator.h
 *
 * @brief The RandomPassengerGenerator class uses the interface of it's parent
 * (PassengerGenerator) to randomly generate passengers based on probabilites
 * that a passenger will be generated at a given stop.
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_RANDOM_PASSENGER_GENERATOR_H_
#define SRC_RANDOM_PASSENGER_GENERATOR_H_

#include <list>
#include <random>
#include <ctime>

#include "src/passenger_generator.h"
#include "src/stop.h"

class Stop;  // forward declaration

class RandomPassengerGenerator : public PassengerGenerator{
 public:
  RandomPassengerGenerator(std::list<double>, std::list<Stop *>);
  /**
  * @brief GeneratePassengers is the overridden version of the parent method. It
  * randomly generates passengers based on probabilites that a passenger will be
  * generated at a given stop
  *
  * @return Int indicating the number of passengers generated
  *
  */
  int GeneratePassengers() override;

 private:
  static std:: minstd_rand0 my_rand;
};

#endif  // SRC_RANDOM_PASSENGER_GENERATOR_H_
