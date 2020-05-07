#include <iostream>

#include "Ashbringer.hpp"

unsigned Ashbringer::getAttack() {
  return attack;
}

Weapon* Ashbringer::copy() {
  return new Ashbringer(*this);
}
