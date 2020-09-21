/**
 * @file IObservable.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_IOBSERVABLE_H_
#define SRC_IOBSERVABLE_H_

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

#include "src/data_structs.h"
#include "src/IObserver.h"

class IObservable {
 public:
   /**
   * @brief Registers a given observer (adds it to the list of observerss)
   */
  void RegisterObserver(IObserver* observer) {
    observer_.push_back(observer);
  }
  /**
  * @brief Clears all observers (removes all observers from observer list)
  */
  void ClearObservers() {
    observer_.clear();
  }
  /**
  * @brief Scans list of observers and notifies notifies each one about changes
  * in the bus it is observing
  */
  void NotifyObservers(BusData data) {
    for (std::vector<IObserver*>::const_iterator iter = observer_.begin();
    iter != observer_.end(); ++iter) {
      if (*iter != 0) {
        (*iter)->Notify(&data);
      }
    }
  }

 private:
  std::vector<IObserver*> observer_;
};

#endif  // SRC_IOBSERVABLE_H_
