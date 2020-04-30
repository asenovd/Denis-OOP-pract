#ifndef __FIGURES_HPP__
#define __FIGURES_HPP__

#include <iostream>

#include "Vector.cpp"
#include "Shape.hpp"

class Figures : public Vector<Shape*> {

public:
  double getMaxPerim();
  double getMaxArea();

};

#endif
