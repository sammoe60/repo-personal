/**
 * @file Bus.cc
 *
 * @brief The Stop class represents the Stops that passengers are generated at,
 * where passengers are loaded onto and off of busses, and are used to make up
 * Routes.
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_STOP_H_
#define SRC_STOP_H_

#include <list>
#include <iostream>

#include "src/bus.h"
#include "src/passenger.h"

class Bus;

class Stop {
 public:
  explicit Stop(int, double = 44.973723, double = -93.235365);
  /**
  * @brief LoadPassengers removes passengers from the current Stop and puts
  * them on a given Bus.
  *
  * @param[in] A pointer to the Bus passengers are being loaded onto.
  *
  * @return int: the number of passengers loaded onto the bus.
  */
  int LoadPassengers(Bus *);  // Removing passengers from stop
  // and onto a bus
  /**
  * @brief AddPassengers Adds passenger(s) to the Stop.
  *
  * @param[in] A pointer to the passenger(s) to be added to the stop.
  *
  * @return int indicating how many Passengers were added to the Stop.
  */
  int AddPassengers(Passenger *);  // Adding passengers
  // to the stop (from the generator)
  /**
  * @brief Updates the state of each Passenger currently at the Stop.
  */
  void Update();
  /**
  * @brief Gives the stop id of the Stop.
  *
  * @return int: the id of the Stop.
  */
  int GetId() const;
  /**
  * @brief Report prints useful information about a stop such as it's stop ID,
  * and information about each Passenger currently at the Stop.
  *
  * @param[in] std::ostream object indicating where to print the information.
  */
  void Report(std::ostream&) const;

  // Vis Getters
  /**
  * @brief GetLongitude gives the longitude of the Stop.
  *
  * @return double: the longitude of the Stop.
  */
  double GetLongitude() const { return longitude_; }
  /**
  * @brief GetLatitude gives the latitude of the Stop.
  *
  * @return double: the latitude of the Stop.
  */
  double GetLatitude() const { return latitude_; }
  /**
  * @brief GetNumPassengersPresent gives the number of passenger currently at
  * the Stop.
  *
  * @return size_t object representing the number of passengers at the Stop.
  */
  size_t GetNumPassengersPresent() { return passengers_.size(); }

 private:
  int id_;
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  double longitude_;
  double latitude_;  // are we using long/lat coords?
  // derived information - not needed depending on passengers_
  // data structure implementation?
  // int passengers_present_;
};
#endif  // SRC_STOP_H_
