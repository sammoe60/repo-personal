/**
 * @file route.h
 *
 * @brief The Route class represents the routes, which are made up of stops,
 * that busses follow to carry passengers from location to location.

 * @Copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROUTE_H_
#define SRC_ROUTE_H_

#include <list>
#include <iostream>
#include <string>

#include "./data_structs.h"

#include "./passenger_generator.h"
#include "./stop.h"

class PassengerGenerator;

class Route {
 public:
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
        PassengerGenerator *);
  /**
  * @brief Clone is used to clone a given Route.
  *
  * @return Pointer to the cloned Route.
  */
  Route * Clone();
  /**
  * @brief Generates passengers along the route and updates both the state of
  * the stops along the route and the state of the route data.
  */
  void Update();
  /**
  * @brief Report prints useful data about the Route such as the name, the
  * number of stops, and information about the stops contained in the Route.
  *
  * @param[in] std::ostream reference idicating where to print the information.
  */
  void Report(std::ostream&);
  /**
  * @brief IsAtEnd indicates whether the Route has been completed (all stops
  * have been visited).
  *
  * @return Boolean indicating if the Route has been completed or not.
  */
  bool IsAtEnd() const;
  /**
  * @brief PrevStop gives the Previous stop along the Route.
  *
  * @return Pointer the previous Stop.
  */
  Stop *  PrevStop();  // Returns stop before destination stop
  /**
  * @brief Moves the Route to it's next stop. If the route is already at the
  * final Stop then it indicates that the Route has completed.
  */
  void ToNextStop();  // Change destination_stop_ to next stop
  /**
  * @brief Provides a pointer to the next Stop along the Route.
  *
  * @return Pointer to the next Stop along the Route.
  */
  Stop * GetDestinationStop() const;    // Get pointer to next stop
  /**
  * @brief Gives to total distance of the Route.
  *
  * @return Double: the total distance of the Route.
  */
  double GetTotalRouteDistance() const;
  /**
  * @brief Gives the distance to the next Stop along the Route.
  *
  * @return Double: the distance to the next Stop along the Route.
  */
  double GetNextStopDistance() const;

  // Vis Getters
  /**
  * @brief Provides the name of the Route.
  *
  * @return string: the name of the Route.
  */
  std::string GetName() const { return name_; }
  /**
  * @brief Provides a list of pointers to all the stops in the Route.
  *
  * @return list of Pointers to Stops (all stops along the Route).
  */
  std::list<Stop *> GetStops() const { return stops_; }
  /**
  * @brief Updates Route data object to reflect the current stare of the Route.
  */
  void UpdateRouteData();
  /**
  * @brief Provides a RouteData object containing data about the Route.
  *
  * @return RouteData object containing data about the Route.
  */
  RouteData GetRouteData() const;

 private:
   /**
   * @brief GenerateNewPassengers uses PassengerGenerator to generate new
   * passengers a Stops along the Route based on generation probabilities.
   *
   * @return int indicating the number of new passengers generated.
   */
  int GenerateNewPassengers();       // generates passengers on its route
  PassengerGenerator * generator_;
  std::list<Stop *> stops_;
  std::list<double> distances_between_;  // length = num_stops_ - 1
  std::string name_;
  int num_stops_;
  int destination_stop_index_;  // always starts at zero, no init needed
  Stop * destination_stop_;
  // double trip_time_; // derived data - total distance travelled on route

  RouteData route_data_;
};
#endif  // SRC_ROUTE_H_
