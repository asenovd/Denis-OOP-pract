#include <iostream>

#include "Figures.hpp"

/*
double Figures::getMaxPerim() {
  double mx = 0;
  for(unsigned i=0; i<count; ++i) {
    double temp = data[i]->getPerimeter();
    if(mx < temp) mx = temp;
  }
  return mx;
}

double Figures::getMaxArea() {
  double mx = 0;
  for(unsigned i=0; i<count; ++i) {
    double temp = data[i]->getArea();
    if(mx < temp) mx = temp;
  }
  return mx;
}
*/

double Figures::getMax(double (Shape::*func)() ) {
  double mx = 0;
  for(unsigned i=0; i<count; ++i) {
    double temp = data[i]->func();
    if(mx < temp) mx = temp;
  }
  return mx;
}
