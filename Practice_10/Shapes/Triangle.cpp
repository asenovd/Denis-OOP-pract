#include <iostream>
#include <cmath>

#include "Triangle.hpp"

Triangle::Triangle(double a, double b, double c) {
  sideA = a;
  sideB = b;
  sideC = c;
}

double Triangle::getPerimeter() {
  return sideA+sideB+sideC;
}

double Triangle::getArea() {
  double p = (getPerimeter())/2;
  return (sqrt(p*(p-sideA)*(p-sideB)*(p-sideC)));
}
