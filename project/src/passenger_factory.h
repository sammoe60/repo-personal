/**
 * @file passenger_factory.h
 *
 * @brief The PassengerFactory class is used to generate passengers with
 * different names and assigns each passenger a starting and ending point.
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_PASSENGER_FACTORY_H_
#define SRC_PASSENGER_FACTORY_H_

#include <string>

#include "src/passenger.h"

class PassengerFactory {
 public:
   /**
   * @brief Generates a passenger and assigns the passenger a starting and
   * ending point based on the parameters
   *
   * @param[in] int: the passenger's current stop id (starting point)
   * @param[in] int: the passenger's desired destination stop id
   *
   * @return Pointer to generated passenger
   */
  static Passenger * Generate(int, int);
 private:
   /**
   * @brief Method to facilitate naming of passengers
   *
   * @return Static string representing the resulting name chosen
   */
  static std::string NameGeneration();
};
#endif  // SRC_PASSENGER_FACTORY_H_
