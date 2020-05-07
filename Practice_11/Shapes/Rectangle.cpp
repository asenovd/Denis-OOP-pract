#include <iostream>

#include "Rectangle.hpp"

Rectangle::Rectangle(double a, double b) {
  width = a;
  length = b;
}

double Rectangle::getPerimeter() {
  return (width + width + length + length);
}

double Rectangle::getArea() {
  return width*length;
}
