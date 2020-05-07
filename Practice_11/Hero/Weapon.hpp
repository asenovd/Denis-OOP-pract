#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

class Weapon {

public:
  virtual unsigned getAttack() = 0;
  virtual Weapon* copy() = 0;
};

#endif
