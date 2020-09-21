/**
 * @file bus_decorator.h
 *
 * @brief This class uses the decorator pattern to enable new types of buses
 * to be introduced (by decorating existing buses)
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_BUS_DECORATOR_H_
#define SRC_BUS_DECORATOR_H_

// #include "src/bus.h"
// #include <tuple>
// #include <string>
//
// class BusDecorator : public Bus {
//  public:
//   // BusDecorator(Bus *baseBus) : m_bus(baseBus) {}
//   BusDecorator(std::string name, Route* out, Route * in, double speed,
//     std::string type) : m_bus(name, out, in, 90, speed, "NormalBus") {}
//  /**
//  * @brief Sets the color of the bus to the appropriate 4 tuple
//  *
//  */
//   void SetColor() {
//     std::tuple<int, int, int, int> color = std::make_tuple(255, 255, 255, 1);
//     color_ = color;
//   }
//
//  protected:
//   Bus *m_bus;
// };
//
#endif  // SRC_BUS_DECORATOR_H_
