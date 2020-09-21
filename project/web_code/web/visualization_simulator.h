/**
 * @file visualization_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef WEB_VISUALIZATION_SIMULATOR_H_
#define WEB_VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>
#include <string>

#include "web_code/web/web_interface.h"
#include "src/config_manager.h"
#include "src/IObservable.h"
#include "src/bus_factory.h"
#include "src/file_writer.h"

class Route;
class Bus;
class Stop;

class VisualizationSimulator {
 public:
  VisualizationSimulator(WebInterface*, ConfigManager*);
  ~VisualizationSimulator();
  /**
  * @brief Method which starts the simulation
  */
  void Start(const std::vector<int>&, const int&);
  /**
  * @brief Method which Updates the simulation as time progresses
  */
  void Update();
  /**
  * @brief Function which pauses or unpauses the simulation
  */
  void Pause();
  bool paused;
  /**
  * @brief Method which clears the observer list of all observers
  */
  void ClearListeners();
  /**
  * @brief Method which adds observers to the observer list
  */
  void AddListener(std::string* id, IObserver* observer);

 private:
  WebInterface* webInterface_;
  ConfigManager* configManager_;
  FileWriter* fileWriter_;

  std::vector<int> busStartTimings_;
  std::vector<int> timeSinceLastBus_;
  int numTimeSteps_;
  int simulationTimeElapsed_;

  std::vector<Route *> prototypeRoutes_;
  std::vector<Bus *> busses_;

  int busId = 1000;

  std::string bus_stats_file_name = "BusData.csv";
};

#endif  // WEB_VISUALIZATION_SIMULATOR_H_
