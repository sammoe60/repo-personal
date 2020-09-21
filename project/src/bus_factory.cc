/**
 * @file bus_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <vector>
#include <random>
#include <ctime>

#include "src/bus_factory.h"
#include "src/bus.h"
#include "src/small_bus.h"
#include "src/medium_bus.h"
#include "src/large_bus.h"

Bus * BusFactory::StrategyOne(int busId, Route* outbound, Route* inbound) {
  if (busId % 2 == 0) {
    return new SmallBus(std::to_string(busId), outbound->Clone(),
    inbound->Clone(), 1, "SmallBus");
  } else {
    return new MediumBus(std::to_string(busId), outbound->Clone(),
    inbound->Clone(), 1, "MediumBus");
  }
}

Bus * BusFactory::StrategyTwo(int busId, Route* outbound, Route* inbound) {
  if (busId % 2 == 0) {
    return new MediumBus(std::to_string(busId), outbound->Clone(),
    inbound->Clone(), 1, "MediumBus");
  } else {
    return new LargeBus(std::to_string(busId), outbound->Clone(),
    inbound->Clone(), 1, "LargeBus");
  }
}

Bus * BusFactory::StrategyThree(int busId, Route* outbound, Route* inbound) {
  if (busId % 3 == 1) {
    return new SmallBus(std::to_string(busId), outbound->Clone(),
    inbound->Clone(), 1, "SmallBus");
  } else if (busId %3 == 2) {
    return new MediumBus(std::to_string(busId), outbound->Clone(),
    inbound->Clone(), 1, "MediumBus");
  } else {
    return new LargeBus(std::to_string(busId), outbound->Clone(),
    inbound->Clone(), 1, "LargeBus");
  }
}

Bus * BusFactory::StrategyFour(int busId, Route* outbound, Route* inbound) {
  return new SmallBus(std::to_string(busId), outbound->Clone(),
  inbound->Clone(), 1, "SmallBus");
}

Bus * BusFactory::CreateBus(int busId, Route* outbound, Route* inbound) {
  BusFactory* f = new BusFactory;
  time_t curr_time;
  curr_time = time(0);
  tm* local_time = localtime(&curr_time);
  int hr = local_time->tm_hour;
  if ((hr >=6) & (hr < 8)) {
    return f->StrategyOne(busId, outbound, inbound);
  } else if ((hr >=8) & (hr < 15)) {
    return f->StrategyTwo(busId, outbound, inbound);
  } else if ((hr >= 15) & (hr < 20)) {
    return f->StrategyThree(busId, outbound, inbound);
  } else {
    return f->StrategyFour(busId, outbound, inbound);
  }
}
