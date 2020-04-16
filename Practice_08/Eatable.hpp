#ifndef __EATABLE_HPP__
#define __EATABLE_HPP__

enum Taste { SWEET, SOUR, SALTY, BITTER, SAVORY };

class Eatable {
protected:
  Taste taste;
public:
  Eatable();
  Eatable(Taste);
  void print();
};


#endif
