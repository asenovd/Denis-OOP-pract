#ifndef __BANANA_HPP__
#define __BANANA_HPP__

#include "Fruit.hpp"
#include "Product.hpp"

class Banana : public Fruit, public Product {
public:
  Banana();
  Banana(Taste, double, double, double, double, double, const char*, const char*, double, double, double, double);
  double getPricePerCallories();
  double getFatWeight();
  void print();
};


#endif
