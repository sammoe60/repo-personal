/**
 * @file bus_factory.h
 *
 * @brief The BusFactory class is used to randomly generate either a small,
 * medium, or large bus.
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include <string>

#include "src/bus.h"

class BusFactory {
 public:
   /**
   * @brief Constructs a small, medium, or large bus with which bus being random
   *
   * @return pointer to Bus object
   */
  static Bus * CreateBus(int busId, Route* outbound, Route* inbound);
  /**
  * @brief Strategy that returns a pointer to a small or medium bus depending on
  * state (the pervious bus)
  *
  * @return pointer to the newly constructed bus
  */
  Bus * StrategyOne(int busId, Route* outbound, Route* inbound);
  /**
  * @brief Strategy that returns a pointer to a medium or large bus depending on
  * state (the pervious bus)
  *
  * @return pointer to the newly constructed bus
  */
  Bus * StrategyTwo(int busId, Route* outbound, Route* inbound);
  /**
  * @brief Strategy that returns a pointer to a small, medium or large bus
  * depending on state (the pervious bus)
  *
  * @return pointer to the newly constructed bus
  */
  Bus * StrategyThree(int busId, Route* outbound, Route* inbound);
  /**
  * @brief Strategy that returns a pointer to a small bus
  *
  * @return pointer to the newly constructed bus
  */
  Bus * StrategyFour(int busId, Route* outbound, Route* inbound);
  static int state;
};

#endif  // SRC_BUS_FACTORY_H_
