/**
 * @file passenger_loader.h
 *
 * @bried The PassengerLoader class is used to load passengers onto busses
 * 
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_PASSENGER_LOADER_H_
#define SRC_PASSENGER_LOADER_H_

#include <list>
#include "./passenger.h"

class PassengerLoader {
 public:
  // LoadPassenger returns the number of passengers added to the bus.
  // Currently this is either one or zero: either passenger was added or they
  // weren't.
  // This was a design decision. We don't know if we should allow the adding of
  // multiple passengers at a time
  // This allows us to change the Passenger Loader without having to change
  // the Bus.
  /**
  * @brief LoadPassenger returns the number of passengers added to the bus.
  *
  * @param[in] Pointer to the passenger that will be loaded.
  * @param[in] int: the maximum number of passengers for a given bus.
  * @param[in] a pointer to a list of passenger pointers representing the
  * passengers to be loaded.
  *
  * @return Boolean indicating if passengers were loaded or not
  */
  bool LoadPassenger(Passenger * new_passenger, int max_pass,
                    std::list<Passenger *> * passengers);
};
#endif  // SRC_PASSENGER_LOADER_H_
