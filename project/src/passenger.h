/**
 * @file passenger.h
 *
 * @brief The Passenger class is used to represent the passengers that ride the
 * busses from stop to stop along routes in the simulation.
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

#include <iostream>
#include <string>

class Passenger {  // : public Reporter {
 public:
  explicit Passenger(int = -1, std::string = "Nobody");
  /**
  * @brief Update increments the passengers time at a stop if at a stop or their
  * time on the bus if they are on a bus.
  */
  void Update();
  /**
  * @brief GetOnBus sets time_on_bus_ to 1 indicating that the passenger is on
  * the bus.
  */
  void GetOnBus();
  /**
  * @brief GetTotalWait returns sum of the passengers time waited at stop and
  * time waited on the bus.
  *
  * @return Int representing the sum of the wait_at_stop_ and time_on_bus_
  * fields.
  */
  int GetTotalWait() const;
  /**
  * @brief GetTimeOnBus gives to total number of time a passenger has been on a
  * bus
  *
  * @return Int: the total time on bus
  * fields.
  */
  int GetTimeOnBus() const;
  /**
  * @brief GetWaitAtStop gives to total number of time a passenger has waited
  * at stops
  *
  * @return Int: the total wait at stop
  * fields.
  */
  int GetWaitAtStop() const;
  /**
  * @brief IsOnBus indicates whether the passenger is on a bus.
  *
  * @return boolean indicating if the passenger is on the bus or not.
  */
  bool IsOnBus() const;
  /**
  * @brief GetDestination gives the desired destination of a passenger.
  *
  * @return Int indicating the stop id of the passengers destination.
  */
  int GetDestination() const;
  /**
  * @brief GetName gives the name of a passenger.
  *
  * @return string indicating the name of the passenger.
  */
  std::string GetName();
  /**
  * @brief Report prints useful information about the passenger such as name,
  * destination, total wait time, time waited at stop and time waited on bus.
  *
  * @param[in] std::ostream reference indicating where to print the information
  */
  void Report(std::ostream&) const;


 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
