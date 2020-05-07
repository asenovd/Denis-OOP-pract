#ifndef __HERO_HPP__
#define __HERO_HPP__

#include "Armor.hpp"
#include "Weapon.hpp"

class Hero {
  char* name;
  unsigned health;
  unsigned level;
  Armor* armor;
  Weapon* weapon;

public:
  Hero();
  Hero(const char*);
  Hero(const char*, unsigned, unsigned, Armor*, Weapon*);
  Hero(Hero const &);
  Hero &operator=(Hero const &);
  ~Hero();

  unsigned hp();

  void levelUp();
  void equipWeapon(Weapon*);
  void equipArmor(Armor*);
  void takeDamage(unsigned);
  void dealDamage();

};

#endif
