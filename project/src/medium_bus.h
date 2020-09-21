/**
 * @file medium_bus.h
 *
 * @brief The MediumBus class is identical to it's parent (Bus) with the
 * exception that MediumBus has a capacity of 60 passengers.
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_MEDIUM_BUS_H_
#define SRC_MEDIUM_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/bus.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

class MediumBus : public Bus {
 public:
   /**
   * @brief Constructor for MediumBus which has a capacity of 60 passengers
   */
  MediumBus(std::string name, Route* out, Route* in, double speed,
    std::string type);

    // intended for use with decorator pattern
  // /**
  // * @brief Sets the color of the bus to the appropriate 4 tuple
  // *
  // */
  // void SetColor();


 private:
   /**
   * @brief Unloads passengers from the bus and onto the current stop
   *
   * @return int: the number of passengers unloaded
   */
  int UnloadPassengers();  // returning revenue delta
  // bool Refuel();
  PassengerUnloader * unloader_;
  PassengerLoader * loader_;
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  // double revenue_; // revenue collected from passengers, doesn't include
                     // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                             // AND next stop set
  Stop * next_stop_;
  // bool trip_complete_;  // [DERIVED data] when BOTH routes are at end, trip
  // is complete
  // Vis data for bus
  BusData bus_data_;
  // std::tuple <int, int, int, int> color_;
};
#endif  // SRC_MEDIUM_BUS_H_
