#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include "shape.hpp"

class Square : public Shape {
protected:
  unsigned length;
public:
  Square();
  Square(unsigned);
  Square(TYPE, unsigned, unsigned);

  void setLength(unsigned);

  unsigned getLength() const;
};


#endif
