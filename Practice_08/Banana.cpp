#include <iostream>

#include "Banana.hpp"

Banana::Banana() : Fruit(), Product() {}

Banana::Banana(Taste a1,
   double a2,
   double a3,
   double a4,
   double a5,
   double a6,
   const char* a7,
   const char* a8,
   double a9,
   double a10,
   double a11,
   double a12) :
   Fruit(a1, a2, a3, a4, a5),
   Product(a6, a7, a8, a9, a10, a11, a12) {}

double Banana::getPricePerCallories() {
  return price/calories;
}

double Banana::getFatWeight() {
  return fat/weight;
}

void Banana::print() {
  Fruit::print();
  Product::print();
}
