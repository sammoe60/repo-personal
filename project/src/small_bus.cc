/**
 * @file small_bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/small_bus.h"

SmallBus::SmallBus(std::string name, Route* out, Route* in, double speed,
   std::string type)
    : Bus(name, out, in, 30, speed, "SmallBus") {
}

// intended for use with decorator pattern
// void SmallBus::SetColor() {
//   std::tuple<int,int,int,int> color = std::make_tuple(255,255,255,1);
//   color_ = color;
// }
