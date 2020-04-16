#ifndef __FRUIT_HPP__
#define __FRUIT_HPP__

#include "Eatable.hpp"

class Fruit : public Eatable {
protected:
  double calories;
  double protein;
  double carbs;
  double fat;
public:
  Fruit();
  Fruit(double, double, double, double);
  Fruit(Taste, double, double, double, double);
  void print();
};


#endif
