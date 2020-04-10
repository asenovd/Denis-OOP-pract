#ifndef __LISTMOTOR_HPP__
#define __LISTMOTOR_HPP__

#include "Motor.hpp"

class ListMotor {
  Motor* data;
  int count;
  int reserved;
  const int INITIAL_RESERVED = 32;

public:
  ListMotor();
  ~ListMotor();
  Motor& get(int);
  void push(Motor &);
  int size() const;
  ListMotor &operator=(ListMotor const &);
  friend std::ostream& operator<<(std::ostream&, ListMotor&);
};

#endif
