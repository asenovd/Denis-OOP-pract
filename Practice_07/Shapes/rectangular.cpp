#include <iostream>
#include "shape.hpp"
#include "rectangular.hpp"

Rectangular::Rectangular() : Shape::Shape() {
  width = 0;
  length = 0;
}

Rectangular::Rectangular(double temp_width, double temp_length) : Shape::Shape() {
  width = temp_width;
  length = temp_length;
}


Rectangular::Rectangular(TYPE temp_type, unsigned temp_dim, double temp_width, double temp_length) : Shape::Shape(temp_type,temp_dim) {
  width = temp_width;
  length = temp_length;
}

void Rectangular::setWidth(double temp) {
  width = temp;
}

void Rectangular::setLength(double temp) {
  length = temp;
}


double Rectangular::getWidth() const {
  return width;
}

double Rectangular::getLength() const {
  return length;
}
