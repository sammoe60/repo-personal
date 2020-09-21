/**
 * @file IObserver.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_IOBSERVER_H_
#define SRC_IOBSERVER_H_

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

#include "src/data_structs.h"

class IObserver {
 public:
   /**
   * @brief Pure virtual notification function that will be overridden in
   * BusWebObserver in order to Notify simulation about changes in busses
   */
  virtual void Notify(BusData* info) = 0;
};
#endif  // SRC_IOBSERVER_H_
