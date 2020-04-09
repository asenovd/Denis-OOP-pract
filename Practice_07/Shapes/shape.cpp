#include <iostream>
#include "shape.hpp"

Shape::Shape() {
  type = IRREGULAR;
  dimensions = 2;
}

Shape::Shape(TYPE temp_type, unsigned temp_dim) {
  type = temp_type;
  dimensions = temp_dim;
}

void Shape::setType(TYPE temp) {
  type = temp;
}

void Shape::setDimensions(unsigned temp) {
  dimensions = temp;
}

const char* Shape::getType() const {
  if(type==IRREGULAR) {
    return "Irregular";
  }
  else {
    return "Regular";
  }
}

unsigned Shape::getDimensions() const {
  return dimensions;
}
