#ifndef __ASHBRINGER_HPP__
#define __ASHBRINGER_HPP__

#include "Weapon.hpp"

class Ashbringer : public Weapon {
  unsigned attack;
  
public:
  unsigned getAttack();
  Weapon* copy();

};

#endif
