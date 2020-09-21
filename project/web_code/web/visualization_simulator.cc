/**
 * @file visualization_simulator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include <string.h>
#include <sstream>

#include "src/bus.h"
#include "src/route.h"
#include "src/IObservable.h"
// #include "src/maroon_bus.h"
// #include "src/maroon_bus.h"
#include "web_code/web/my_web_server_command.h"
#include "web_code/web/visualization_simulator.h"

VisualizationSimulator::VisualizationSimulator(WebInterface* webI,
  ConfigManager* configM) {
    webInterface_ = webI;
    configManager_ = configM;
    paused = true;
    fileWriter_ = FileWriter::GetInstance();
}

VisualizationSimulator::~VisualizationSimulator() {
}

void VisualizationSimulator::Start(const std::vector<int>& busStartTimings,
  const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;
    paused = false;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(std::cout);

        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }
}

void VisualizationSimulator::Update() {
  if (paused == false) {
    simulationTimeElapsed_++;

    std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
    std::cout << "~~~~~~~~~~" << std::endl;

    std::cout << "~~~~~~~~~~ Generating new busses if needed ";
    std::cout << "~~~~~~~~~~" << std::endl;

    // Check if we need to generate new busses
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        // Check if we need to make a new bus
        if (0 >= timeSinceLastBus_[i]) {
            Route * outbound = prototypeRoutes_[2 * i];
            Route * inbound = prototypeRoutes_[2 * i + 1];
            Bus* newBus = BusFactory::CreateBus(busId, outbound, inbound);
            busses_.push_back(newBus);
            busId++;

          // busses_.push_back(new Bus(std::to_string(busId), outbound->Clone(),
          // inbound->Clone(), 60, 1));
          // busId++;
            timeSinceLastBus_[i] = busStartTimings_[i];
        } else {
            timeSinceLastBus_[i]--;
        }
    }

    std::cout << "~~~~~~~~~ Updating busses ";
    std::cout << "~~~~~~~~~" << std::endl;

    // Update busses
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        busses_[i]->Update();
        // intended for use with decorator pattern
        // std::string currRoute = busses_[i]->GetCurrentRoute();
        // if(currRoute == "outgoing") {
        //   Bus *maroonBus = new MaroonBus(busses_[i]) //(*busses_[i]) ???
        //   busses_[i] = maroonBus;
        // } else {
        //   Bus *goldBus = new GoldBus(busses_[i]) //(*busses_[i]) ???
        //   busses_[i] = goldBus;
        // }

        if (busses_[i]->IsTripComplete()) {
            webInterface_->UpdateBus(busses_[i]->GetBusData(), true);
            busses_.erase(busses_.begin() + i);
            continue;
        }

        webInterface_->UpdateBus(busses_[i]->GetBusData());
        std::ostringstream *sout;
        sout = new std::ostringstream();
        // busses_[i]->Report(std::cout);
        busses_[i]->Report(sout);
        std::vector<std::string> vec = fileWriter_->ProcessOutput(sout);
        fileWriter_->Write(bus_stats_file_name, vec);
    }

    std::cout << "~~~~~~~~~ Updating routes ";
    std::cout << "~~~~~~~~~" << std::endl;
    // Update routes
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Update();

        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
        prototypeRoutes_[i]->Report(std::cout);
    }
  }
}

void VisualizationSimulator::Pause() {
    if (paused == true) {
      paused = false;
    } else {
      paused = true;
    }
}

// removes all bus observers currently in the simulation. This is accomplished
// by invoking the method ClearObservers from the IObservable class.
void VisualizationSimulator::ClearListeners() {
  for (std::vector<Bus*>::const_iterator iter = busses_.begin();
  iter != busses_.end(); ++iter) {
    (*iter)->ClearObservers();
  }
}

// loops through list of bus observers looking for bus ID
// once id obtained, RegisterObserver called to register the BusWebObserver
// on the list of observers
void VisualizationSimulator::AddListener(std::string* id, IObserver* observer) {
  for (std::vector<Bus*>::const_iterator iter = busses_.begin();
  iter != busses_.end(); ++iter) {
    BusData data = (*iter)->GetBusData();
    std::string currId = data.id;
    if (currId.compare(*id) == 0) {
      (*iter)->RegisterObserver(observer);
    }
  }
  // BusWebObserver::RegisterObserver(observer);
}
