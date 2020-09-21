/**
 * @file my_r_local_simulator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/my_r_local_simulator.h"

#include <vector>
#include <list>

#include "src/bus.h"
#include "src/stop.h"
#include "src/route.h"
#include "src/rtest_passenger_generator.h"

bool myrLocalSimulator::Start() {
  simulation_time_elapsed_ = 0;  // init, but also allows restart

  // int num_round_trips = 10;
  int num_round_trips = 1;
  for (int i = 0; i < num_round_trips; i++) {
    time_since_last_bus_generation_.push_back(0);
  }

  Stop ** Sanford_OB_stops = new Stop *[5];
  Stop ** Sanford_IB_stops = new Stop *[5];
  std::list<Stop *> Sanford_OB_stops_list;
  std::list<Stop *> Sanford_IB_stops_list;

  // Staticly defined objects get destroyed at end of Start()!
  // Must be dynamic...

  // Sanford OB stops
  Stop * stop_san_OB_1 = new Stop(0, 44.973683, -93.235447);  // Northrop
  Stop * stop_san_OB_2 = new Stop(1, 44.972557, -93.243959);  // Willey
  Stop * stop_san_OB_3 = new Stop(2, 44.970730, -93.245556);  // Carlson
  Stop * stop_san_OB_4 = new Stop(3, 44.973216, -93.245821);  // Mondale
  Stop * stop_san_OB_5 = new Stop(4, 44.980660, -93.239498);  // Sanford

  Stop * stop_san_IB_1 = new Stop(5, 44.980660, -93.239498);  // Sanford
  Stop * stop_san_IB_2 = new Stop(6, 44.979021, -93.235402);  // 15th Ave
  Stop * stop_san_IB_3 = new Stop(7, 44.976792, -93.229836);  // Rec center
  Stop * stop_san_IB_4 = new Stop(8, 44.974810, -93.227107);  // McNamara
  Stop * stop_san_IB_5 = new Stop(9, 44.973683, -93.235447);  // Northrop


  Sanford_OB_stops_list.push_back(stop_san_OB_1);
  Sanford_OB_stops[0] = stop_san_OB_1;
  Sanford_OB_stops_list.push_back(stop_san_OB_2);
  Sanford_OB_stops[1] = stop_san_OB_2;
  Sanford_OB_stops_list.push_back(stop_san_OB_3);
  Sanford_OB_stops[2] = stop_san_OB_3;
  Sanford_OB_stops_list.push_back(stop_san_OB_4);
  Sanford_OB_stops[3] = stop_san_OB_4;
  Sanford_OB_stops_list.push_back(stop_san_OB_5);
  Sanford_OB_stops[4] = stop_san_OB_5;

  Sanford_IB_stops_list.push_back(stop_san_IB_1);
  Sanford_IB_stops[0] = stop_san_IB_1;
  Sanford_IB_stops_list.push_back(stop_san_IB_2);
  Sanford_IB_stops[1] = stop_san_IB_2;
  Sanford_IB_stops_list.push_back(stop_san_IB_3);
  Sanford_IB_stops[2] = stop_san_IB_3;
  Sanford_IB_stops_list.push_back(stop_san_IB_4);
  Sanford_IB_stops[3] = stop_san_IB_4;
  Sanford_IB_stops_list.push_back(stop_san_IB_5);
  Sanford_IB_stops[4] = stop_san_IB_5;


  double * Sanford_OB_distances = new double[5];
  double * Sanford_IB_distances = new double[5];
  Sanford_OB_distances[0] = 4;
  Sanford_OB_distances[1] = 5;
  Sanford_OB_distances[2] = 4;
  Sanford_OB_distances[3] = 12;
  Sanford_OB_distances[4] = 6;

  Sanford_IB_distances[0] = 5;
  Sanford_IB_distances[1] = 3;
  Sanford_IB_distances[2] = 5;
  Sanford_IB_distances[3] = 10;
  Sanford_IB_distances[4] = 4;



  std::list<double> Sanford_OB_probs;  // realistic .15, .3, .025, .05, .05, 0
  Sanford_OB_probs.push_back(.3);  // Northrop
  Sanford_OB_probs.push_back(.03);  // Willey
  Sanford_OB_probs.push_back(.1);  // Carlson
  Sanford_OB_probs.push_back(.01);  // Mondale
  Sanford_OB_probs.push_back(0);  // Sanford

  // T is this always true? If so, we may want to reduce the length of probs
  // to_char_type remove possibility of generating passengers with nowhere to go

  std::list<double> Sanford_IB_probs;  // realistic .35, .05, .01, .01, .2, 0
  Sanford_IB_probs.push_back(.15);  // Sanford
  Sanford_IB_probs.push_back(.1);  // 15th Ave
  Sanford_IB_probs.push_back(.3);  // Rec Center
  Sanford_IB_probs.push_back(.02);  // McNamara
  Sanford_IB_probs.push_back(0);  // Northrop

  // Staticly defined objects get destroyed at end of Start()!
  // Must be dynamic...
  // RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  // RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);
  RtestPassengerGenerator * Sanford_OB_generator =
  new RtestPassengerGenerator (Sanford_OB_probs, Sanford_OB_stops_list);
  RtestPassengerGenerator * Sanford_IB_generator =
  new RtestPassengerGenerator (Sanford_IB_probs, Sanford_IB_stops_list);

  // Test to ensure generators are working
  // Helpful for debugging
  // CC_EB_generator.GeneratePassengers();
  // CC_WB_generator.GeneratePassengers();

  // Again, MUST be dynamic...
  // Route CC_EB("Campus Connector - Eastbound", CC_EB_stops, CC_EB_distances,
  // 8, &CC_EB_generator);
  // Route CC_WB("Campus Connector - Westbound", CC_WB_stops, CC_WB_distances,
  // 9, &CC_WB_generator);
  Route * Sanford_OB = new Route("Sanford Express Outbound", Sanford_OB_stops,
  Sanford_OB_distances, 5, Sanford_OB_generator);
  Route * Sanford_IB = new Route("Sanford Express Inbound", Sanford_IB_stops,
  Sanford_IB_distances, 5, Sanford_IB_generator);

  prototype_routes_.push_back(Sanford_OB);
  prototype_routes_.push_back(Sanford_IB);

  prototype_routes_[0]->Report(std::cout);
  prototype_routes_[1]->Report(std::cout);

  bus_counters_.push_back(10000);

  // This will eventually be replaced by configuration/command line argument
  bus_start_timings_.push_back(10);

  // Do we want a bus on start? Or let the update handle this?
  // active_buses_.push_back(new Bus(std::to_string(bus_counters_[0]),
  //   prototype_routes[0].Clone(), prototype_routes[1].Clone(), 60, 1));
  // bus_counters_[0]++;

  return true;
}

bool myrLocalSimulator::Update() {
  // increase time
  simulation_time_elapsed_++;
  std::cout << "~~~~~~~~~~~~~ The time is now " << simulation_time_elapsed_;
  std::cout << " ~~~~~~~~~~~~~" << std::endl;

  // various route-indexed list iterators
  std::vector<int>::iterator bus_gen_timing_iter = bus_start_timings_.begin();
  std::vector<int>::iterator bus_counter_iter = bus_counters_.begin();
  std::vector<Route *>::iterator prototype_route_iter =
                                                     prototype_routes_.begin();

  // increase each time since last bus
  // various iterators parallel the time_since_last iterator
  for (std::vector<int>::iterator it = time_since_last_bus_generation_.begin();
      it != time_since_last_bus_generation_.end();
      it++, bus_gen_timing_iter++, bus_counter_iter++) {
    (*it)++;

    // if time since last [index] == bus gen timing[index]
    if (0 >= (*bus_gen_timing_iter)) {
      // create a new bus! routes are:
      // prototype_routes_[index * 2] & prototype_routes_[index * 2 + 1]
      Route * outbound = (*prototype_route_iter);
      prototype_route_iter++;
      Route * inbound = (*prototype_route_iter);
      prototype_route_iter++;

      active_buses_.push_back(new Bus(std::to_string((*bus_counter_iter)),
                                  outbound->Clone(), inbound->Clone(), 60, 1));
      (*bus_counter_iter)++;
      (*bus_gen_timing_iter) = 10;
    } else {
      prototype_route_iter++;
      prototype_route_iter++;
      (*bus_gen_timing_iter)--;
    }
  }

  // for each bus
  for (std::list<Bus *>::iterator bus_iter = active_buses_.begin();
      bus_iter != active_buses_.end(); bus_iter++) {
    // update bus
    (*bus_iter)->Update();
    // bus report
    // (*bus_iter)->Report(std::cout);

    // REQUIRES USE OF IsTripComplete, which was not required
    // Buses which are "done" will just keep having Update() called
    //  Students MAY need to deal with this, not sure yet...
    // remove bus if trip is complete
    // if ((*bus_iter)->IsTripComplete()) {
    //  bus_iter = active_buses_.erase(bus_iter);
    //  bus_iter--;
    //}
  }

  // for each stop
  for (std::vector<Route *>::iterator route_iter = prototype_routes_.begin();
      route_iter != prototype_routes_.end(); route_iter++) {
    // update stop
    (*route_iter)->Update();
    (*route_iter)->Report(std::cout);
  }

  return true;
}
