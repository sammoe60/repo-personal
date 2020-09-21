/**
 * @file my_r_local_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_MY_R_LOCAL_SIMULATOR_H_
#define SRC_MY_R_LOCAL_SIMULATOR_H_

#include <vector>
#include <string>
#include "src/simulator.h"

class myrLocalSimulator : public Simulator {
 public:
   /**
   * @brief Function which Starts the simulation
   *
   * @return boolean: indicates if simulation started successfully
   */
  bool Start() override;
  /**
  * @brief Function which Updates the simulation as time progresses
  *
  * @return boolean: indicates if simulation updates successfully
  */
  bool Update() override;
 private:
  std::vector<int> bus_counters_;
  std::vector<int> bus_start_timings_;
  std::vector<int> time_since_last_bus_generation_;
  int simulation_time_elapsed_;
};

#endif  // SRC_MY_R_LOCAL_SIMULATOR_H_
