/**
 * @file bus.h
 *
 * @brief The Bus class represents the busses that carry passengers from Stop
 * to Stop in the simulation.
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <iostream>
#include <list>
#include <string>
#include <sstream>
// #include <tuple>

// #include "src/data_structs.h"

#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/IObservable.h"
// #include "my_web_server_command.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

class Bus : public IObservable {
 public:
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
    double speed = 1, std::string type = "NormalBus");
  explicit Bus(int capacity);
  /**
  * @brief Returns a boolean value indicating if the bus's trip is complete
  *
  * @return boolean indicating if trip is complete
  */
  bool IsTripComplete();
  /**
  * @brief Loads a given passenger onto the bus.
  *
  * @param[in] Pointer to a passenger object
  *
  * @return boolean indicating whether or not a passenger was loaded
  */
  bool LoadPassenger(Passenger *);  // returning revenue delta
  /**
  * @brief The main driver method for Bus. This method moves the bus along the
  * Route. It updates the state of any passengers on the bus, loads passengers,
  * if they are at the current stop, or unloads passengers if the Bus is at
  * their desired destination.
  *
  * @return boolean indicating whether or the bus has moved
  */
  bool Move();
  /**
  * @brief Updates the state of the Bus by causing it to move and changing any
  * fields that have changed since the last update.
  */
  void Update();
  /**
  * @brief prints out useful information about the bus such as name, speed,
  * distance to next stop, and information about each passenger on the bus.
  */
  void Report(std::ostringstream*);

  // Vis Getters
  /**
  * @brief Updates any Bus fields that have changed.
  */
  void UpdateBusData();
  /**
  * @brief Used to obtain useful data about the bus (name, speed, distance,
  * passengers)
  *
  * @return BusData object containing the data about the bus
  */
  BusData GetBusData() const;
  /**
  * @brief Gives the name of the bus.
  *
  * @return a string: the name of the bus.
  */
  std::string GetName() const { return name_; }
  /**
  * @brief Gives the type of the bus.
  *
  * @return a string: the type of the bus.
  */
  std::string GetType() const { return type_; }
  /**
  * @brief Gives the bus's next stop along it's route.
  *
  * @return pointer to the next stop in the busses route.
  */
  Stop * GetNextStop() const { return next_stop_; }
  /**
  * @brief Gives the number of passengers on the bus
  *
  * @return size_t object: the number of passengers on the bus
  */
  size_t GetNumPassengers() const { return passengers_.size(); }
  /**
  * @brief Gives the capacity of the bus.
  *
  * @return int: the capacity of the bus.
  */
  int GetCapacity() const { return passenger_max_capacity_; }
  // intended for decorator pattern
  // /**
  // * @brief Sets the color of the bus.
  // *
  // */
  // void SetColor();
  // /**
  // * @brief Sets the current route of the bus (inbound or outbound).
  // *
  // */
  // void SetCurrentRoute(std::string);
  // /**
  // * @brief Gives the current route the bus is on (inbound or outbound)
  // *
  // * @return string: either "inbound" or "outbound"
  // */
  // std::string GetCurrentRoute();


 private:
   /**
   * @brief Unloads passengers from the bus and onto the current stop
   *
   * @return intL the number of passengers unloaded
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
  std::string type_;
  // std::tuple <int, int, int, int> color_;
  // std::string current_route_;

 protected:
  int total_passenger;
};
#endif  // SRC_BUS_H_
