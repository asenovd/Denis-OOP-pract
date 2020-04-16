#include <iostream>

#include "Object.hpp"

Object::Object() {
  weight = 0;
  width = 0;
  length = 0;
  height = 0;
}

Object::Object(double we, double wi, double le, double he) {
  weight = we;
  width = wi;
  length = le;
  height = he;
}

void Object::print() {
  std::cout << weight << " " << width << " " << length << " " << height << std::endl;
}
