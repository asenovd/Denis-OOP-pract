#include <iostream>

#include "Figures.hpp"

double Figures::getMax(double (Shape::*func)() ) {
  double mx = 0;
  for(unsigned i=0; i<count; ++i) {
    double temp = ((*data[i]).*func)();
    if(mx < temp) mx = temp;
  }
  return mx;
}
