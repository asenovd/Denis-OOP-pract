#include <iostream>

#include "Product.hpp"

Product::Product() : Classification(), Object() {}

Product::Product(double pr, const char* bar, const char* cat, double we, double wi, double le, double he) :
    Classification(pr, bar, cat),
    Object(we, wi, le, he) {}

double Product::getVolume() {
  return width*length*height;
}

double Product::getPricePerWeight() {
  return price/weight;
}

double Product::getPricePerVolume() {
  return price/(getVolume());
}

void Product::print() {
  Classification::print();
  Object::print();
}
