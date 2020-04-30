#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "Shape.hpp"

class Triangle : public Shape {
  double sideA;
  double sideB;
  double sideC;

public:
  Triangle(double, double, double);
  double getArea();
  double getPerimeter();
  
};

#endif
