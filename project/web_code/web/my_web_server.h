/**
 * @file my_web_server.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef WEB_MY_WEB_SERVER_H_
#define WEB_MY_WEB_SERVER_H_

#include <vector>

#include "web_code/web/web_interface.h"


class MyWebServer : public WebInterface {
 public:
  MyWebServer();
  ~MyWebServer() {}
  /**
  * @brief Method which Updates route information as time progresses
  */
  void UpdateRoute(const RouteData& route, bool deleted = false) override;
  /**
  * @brief Method which Updates bus information as time progresses
  */
  void UpdateBus(const BusData& bus, bool deleted = false) override;

  std::vector<RouteData> routes;
  std::vector<BusData> busses;
};

#endif  // WEB_MY_WEB_SERVER_H_
