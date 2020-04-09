#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

enum TYPE{IRREGULAR, REGULAR};

class Shape {
protected:
  TYPE type;
  unsigned dimensions;
public:
  Shape();
  Shape(TYPE, unsigned);

  void setType(TYPE);
  void setDimensions(unsigned);
  const char* getType() const;
  unsigned getDimensions() const;
};


#endif
