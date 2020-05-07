#ifndef __CHAINMAIL_HPP__
#define __CHAINMAIL_HPP__

#include "Armor.hpp"

class Chainmail : public Armor {
  unsigned defense;

public:
  Chainmail();
  ~Chainmail();

  unsigned getArmor();
  Armor* copy();

};

#endif
