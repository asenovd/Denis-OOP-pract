#ifndef __PRODUCT_HPP__
#define __PRODUCT_HPP__

#include "Classification.hpp"
#include "Object.hpp"

class Product : public Classification, public Object {
public:
  Product();
  Product(double, const char*, const char*, double, double, double, double);
  double getVolume();
  double getPricePerWeight();
  double getPricePerVolume();
  void print();
};


#endif
