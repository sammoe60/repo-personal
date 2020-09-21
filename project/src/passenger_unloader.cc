/**
 * @file passenger_unloader.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/passenger_unloader.h"

int PassengerUnloader::UnloadPassengers(std::list<Passenger *> passengers,
                                        Stop * current_stop) {
  // TODO(wendt): may need to do end-of-life here
  // instead of in Passenger or Simulator
  int passengers_unloaded = 0;
  for (std::list<Passenger *>::iterator it = passengers.begin();
      it != passengers.end(); it++) {
    if ((*it)->GetDestination() == current_stop->GetId()) {
      // could be used to inform scheduler of end-of-life?
      // This could be a destructor issue as well.
      // *it->FinalUpdate();
      FileWriter* fileWriter_ = FileWriter::GetInstance();
      std::ostringstream *sout;
      sout = new std::ostringstream();
      (*sout) << "Name " << (*it)->GetName();
      (*sout) << " Destination " << (*it)->GetDestination();
      (*sout) << " Total_wait " << (*it)->GetTotalWait();
      (*sout) << " Wait_at_stop  " << (*it)->GetWaitAtStop();
      (*sout) << " Time_on_bus " << (*it)->GetTimeOnBus();
      std::vector<std::string> vec = fileWriter_->ProcessOutput(sout);
      fileWriter_->Write(passenger_file_name, vec);

      it = passengers.erase(it);
      // getting seg faults, probably due to reference deleted objects
      // here
      it--;
      passengers_unloaded++;
    }
  }

  return passengers_unloaded;
}
