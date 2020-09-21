/**
 * @file medium_bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
*/

#include "src/medium_bus.h"

MediumBus::MediumBus(std::string name, Route* out, Route* in, double speed,
   std::string type)
    : Bus(name, out, in, 60, speed, "MediumBus") {
}

// intended for use with decorator pattern
// /**
// * @brief Sets the color of the bus to the appropriate 4 tuple
// *
// */
// void MediumBus::SetColor() {
//   std::tuple<int,int,int,int> color = std::make_tuple(255,255,255,1);
//   color_ = color;
// }
