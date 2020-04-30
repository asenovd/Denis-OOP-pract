#include <iostream>

#include "Figures.hpp"

double Figures::getMaxPerim() {
  double mx = data[0]->getPerimeter();
  for(unsigned i=1; i<count; ++i) {
    double temp = data[i]->getPerimeter();
    if(mx < temp) mx = temp;
  }
  return mx;
}

double Figures::getMaxArea() {
  double mx = data[0]->getArea();
  for(unsigned i=1; i<count; ++i) {
    double temp = data[i]->getArea();
    if(mx < temp) mx = temp;
  }
  return mx;
}
