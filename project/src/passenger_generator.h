/**
 * @file passenger_generator.h
 *
 * @brief The PassengerGenerator class is used to generate multiple passengers
 * using the probabilites that a passenger will be generated at a given stop
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_GENERATOR_H_
#define SRC_PASSENGER_GENERATOR_H_

#include <list>
#include "src/passenger_factory.h"
#include "src/stop.h"

class Stop;  // forward declaration

class PassengerGenerator {
 public:
   /**
   * @brief Generates multiple passengers
   *
   * @param[in] a list of doubles representing probabilites a passenger will
   * be generated
   * @param[in] a list of stops represting the stops in the simulation
   *
   */
  PassengerGenerator(std::list<double>, std::list<Stop *>);
  // Makes the class abstract, cannot instantiate and forces subclass override
  /**
  * @brief pure virtual function used as an interface for future overridden
  * versions that will Generate passengers based on probabilites.
  *
  * @return Int: the number of passengers generated
  */
  virtual int GeneratePassengers() = 0;  // pure virtual

 protected:
  std::list<double> generation_probabilities_;
  std::list<Stop *> stops_;

  // should we be using a singleton here somehow?
  // PassengerFactory * pass_factory;
};
#endif  // SRC_PASSENGER_GENERATOR_H_
