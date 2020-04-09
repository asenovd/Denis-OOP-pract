#ifndef __CUBE_HPP__
#define __CUBE_HPP__

#include "shape.hpp"
#include "square.hpp"

class Cube : public Square {
  Square walls;
public:
  Cube();
  Cube(Square);
  Cube(TYPE, unsigned, unsigned);
  Cube(TYPE, unsigned, Square);
  friend std::ostream& operator<<(std::ostream&, Cube&);

  unsigned getLength() const;
};


#endif
