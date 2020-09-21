/**
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class representing passengers
 *
 * The class contains information about passengers and methods allowing the
 *  modification of passenger fields and other actions.
 */
class Passenger {  // : public Reporter {
 public:
  explicit Passenger(int = -1, std::string = "Nobody");
  /**
 * @brief Increases the wait_at_stop field by 1.
 *
 * @param[void] This funtion takes no parameters.
 *
 * @return This function is void and returns nothing
 */
  void Update();
  void GetOnBus();
  int GetTotalWait() const;
  bool IsOnBus() const;
  int GetDestination() const;
  void Report() const;
 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
