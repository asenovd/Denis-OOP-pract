#ifndef __COLORRECTANGULAR_HPP__
#define __COLORRECTANGULAR_HPP__

#include "shape.hpp"
#include "rectangular.hpp"

class ColoredRectangular : public Rectangular {
  char* color;
public:
  ColoredRectangular();
  ColoredRectangular(const char*);
  ColoredRectangular(const char*, Rectangular);
  ColoredRectangular(double, double, const char*);
  ColoredRectangular(TYPE, unsigned, double, double, const char*);
  ~ColoredRectangular();
  friend std::ostream& operator<<(std::ostream&, ColoredRectangular&);

  void setColor(const char*);

  const char* getColor() const;
};


#endif
