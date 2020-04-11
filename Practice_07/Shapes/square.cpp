#include <iostream>
#include "shape.hpp"
#include "square.hpp"

Square::Square() : Shape() {
  length = 0;
}

Square::Square(unsigned temp_length) : Shape() {
  length = temp_length;
}

Square::Square(TYPE temp_type, unsigned temp_dim, unsigned temp_length) : Shape(temp_type, temp_dim) {
  length = temp_length;
}


void Square::setLength(unsigned temp) {
  length = temp;
}

unsigned Square::getLength() const {
  return length;
}
