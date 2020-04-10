#ifndef __MOTORCYCLIST_HPP__
#define __MOTORCYCLIST_HPP__

#include "ListMotor.hpp"
#include "Motor.hpp"

class Motorcyclist {
  char* name;
  unsigned age;
  ListMotor motors;
public:
  Motorcyclist();
  Motorcyclist(const char*, unsigned);
  Motorcyclist(const char*, unsigned, ListMotor &);
  Motorcyclist(Motorcyclist const &);
  ~Motorcyclist();
  Motorcyclist &operator=(Motorcyclist const &);
  bool operator>(Motorcyclist const &);
  bool operator<(Motorcyclist const &);
  friend std::ostream& operator<<(std::ostream&, Motorcyclist&);

  void addMotor(Motor &);
};

#endif
