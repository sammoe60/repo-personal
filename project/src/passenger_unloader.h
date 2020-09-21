/**
 * @file passenger_unloader.h
 *
 * @brief The PassengerUnloader class is used to unload passengers from the bus
 * at a given stop
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_UNLOADER_H_
#define SRC_PASSENGER_UNLOADER_H_
#include <list>
#include <string>
#include "src/passenger.h"
#include "src/stop.h"
#include "src/file_writer.h"
class Stop;
class Passenger;

class PassengerUnloader {
 public:
  // UnloadPassengers returns the number of passengers removed from the bus.
  /**
  * @brief UnloadPassengers returns the number of passengers taken off the bus.
  *
  * @param[in] Pointer to a list of pointers to the passengers on the bus.
  * @param[in] Pointer to the current_stop.
  *
  * @return Int indicating the number of passengers unloaded from the bus.
  */
  int UnloadPassengers(std::list<Passenger*> passengers, Stop * current_stop);

 private:
  std::string passenger_file_name = "PassData.csv";
};
#endif  // SRC_PASSENGER_UNLOADER_H_
