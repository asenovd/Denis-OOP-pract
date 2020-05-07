#include <iostream>

#include "Chainmail.hpp"

unsigned Chainmail::getArmor() {
  return defense;
}

Armor* Chainmail::copy() {
  return new Chainmail(*this);
}
