/**
 * @file large_bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
*/

#include "src/large_bus.h"

LargeBus::LargeBus(std::string name, Route* out, Route* in, double speed,
   std::string type)
    : Bus(name, out, in, 90, speed, "LargeBus") {
}

// intended for use with decorator pattern
// void LargeBus::SetColor() {
//   std::tuple<int,int,int,int> color = std::make_tuple(255,255,255,1);
//   color_ = color;
// }
