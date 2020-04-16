#include <iostream>

#include "Eatable.hpp"

using std::cout;

Eatable::Eatable() {
  taste = SWEET;
}

Eatable::Eatable(Taste temp_taste) {
  taste = temp_taste;
}

void Eatable::print() {
  switch(taste) {
    case SWEET: {
      cout << "Sweet\n";
      return;
    }
    case SOUR: {
      cout << "Sour\n";
      return;
    }
    case SALTY: {
      cout << "Salty\n";
      return;
    }
    case BITTER: {
      cout << "Bitter\n";
      return;
    }
    case SAVORY: {
      cout << "Savory\n";
      return;
    }
    default: {
      cout << "Unknown\n";
      return;
    }
  }
}
