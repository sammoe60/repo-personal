#ifndef POINT2_H
#define POINT2_H

class Point2 {
public:
  Point2();
  Point2(float _x, float _y);
  float DistanceBetween(Point2 _otherPoint);
  int Quadrant();
  void Print();
private:
  float x, y;
};

#endif
