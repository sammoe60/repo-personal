#include "point2.h"

#include <iostream>
#include <cmath>

Point2::Point2() {
  x = 0.0;
  y = 0.0;
};

Point2::Point2(float _x, float _y) {
  x = _x;
  y = _y;
};

float Point2::DistanceBetween(Point2 otherPoint) {
  std::cout << otherPoint.x << std::endl;
  std::cout << this->x << std::endl;
  std::cout << otherPoint.y << std::endl;
  std::cout << this->y << std::endl;
  return sqrt(((otherPoint.x - this->x) * (otherPoint.x - this->x)) +
  ((otherPoint.y - this->y) * (otherPoint.y - this->y)));
};

int Point2::Quadrant() {
  float myX = this->x;
  float myY = this->y;
  if(myX >= 0.0){
    if(myX == 0.0){
      if(myY == 0.0){
        return 0;
      } else if(myY > 0.0){
        return 2;
      } else {
        return 4;
      }
    } else {
      if(myY >= 0.0) {
        return 1;
      } else {
        return 4;
      }
    }
  } else {
    if(myY <= 0.0){
      return 3;
    } else {
      return 2;
    }
  }
};

void Point2::Print() {
  std::cout << "(" << this->x << "," << this->y << ")" << std::endl;
};
