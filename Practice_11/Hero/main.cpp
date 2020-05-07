#include <iostream>

#include "Hero.hpp"
#include "Ashbringer.hpp"
#include "Chainmail.hpp"

using std::cout;
using std::endl;

int main() {
  Chainmail cm1;
  Ashbringer ab1;
  Hero h1("Uther");

  cout << h1.hp() << endl;
  h1.takeDamage(5);
  cout << h1.hp() << endl;
  h1.levelUp();
  h1.levelUp();
  cout << h1.hp() << endl;

  h1.equipWeapon(&ab1);
  h1.equipArmor(&cm1);
  
  h1.takeDamage(50);
  cout << h1.hp() << endl;
  h1.dealDamage();

  return 0;
}
