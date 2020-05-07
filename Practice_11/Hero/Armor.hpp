#ifndef __ARMOR_HPP__
#define __ARMOR_HPP__

class Armor {

public:
  virtual unsigned getArmor() = 0;
  virtual Armor* copy() = 0;
};

#endif
