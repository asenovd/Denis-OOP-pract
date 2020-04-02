#ifndef __WASHING_MACHINES__
#define __WASHING_MACHINES__

#include<iostream>

class WashingMachines {
  char* manufacturer;
  char* model;
  int capacity;
  double consumption;
  int water;
public:
  WashingMachines();
  WashingMachines(const char*, const char*, int, double, int);
  WashingMachines(const WashingMachines&);
  bool operator>(WashingMachines const &);
  ~WashingMachines();

  char* getManufacturer();
  char*getModel();
  int getCapacity();
  double getConsumption();
  int getWater();

  void setManufacturer(const char*);
  void setModel(const char*);
  void setCapacity(int);
  void setConsumption(double);
  void setWater(int);

  void print() {
    std::cout << manufacturer << " " << model << std::endl;

  }
};

#endif /* end of include guard: __WASHING_MACHINES__ */
