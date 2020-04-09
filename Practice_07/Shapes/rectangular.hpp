#ifndef __RECTANGULAR_HPP__
#define __RECTANGULAR_HPP__

#include "shape.hpp"

class Rectangular : public Shape {
protected:
  double width;
  double length;
public:
  Rectangular();
  Rectangular(double, double);
  Rectangular(TYPE, unsigned, double, double);

  void setWidth(double);
  void setLength(double);

  double getWidth() const;
  double getLength() const;
};


#endif
