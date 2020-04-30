#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "Shape.hpp"

class Rectangle : public Shape {
  double width;
  double length;

public:
  Rectangle(double, double);
  double getArea();
  double getPerimeter();
  
};

#endif
