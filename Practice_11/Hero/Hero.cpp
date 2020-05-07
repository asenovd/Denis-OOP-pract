#include <iostream>
#include <cstring>

#include "Hero.hpp"

Hero::Hero() {
  name = nullptr;
  health = 10;
  level = 1;
  armor = nullptr;
  weapon = nullptr;
}
Hero::Hero(const char* _name) {
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);
  health = 10;
  level = 1;
  armor = nullptr;
  weapon = nullptr;
}
Hero::Hero(const char* _name, unsigned _hp, unsigned _lvl, Armor* _armor, Weapon* _weapon) {
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);
  health = _hp;
  level = _lvl;
  armor = _armor->copy();
  weapon = _weapon->copy();
}
Hero::Hero(Hero const &temp) {
  name = new char[strlen(temp.name) + 1];
  strcpy(name, temp.name);
  health = temp.health;
  level = temp.level;
  armor = temp.armor->copy();
  weapon = temp.weapon->copy();
}
Hero &Hero::operator=(Hero const &temp) {
  name = new char[strlen(temp.name) + 1];
  strcpy(name, temp.name);
  health = temp.health;
  level = temp.level;
  armor = temp.armor->copy();
  weapon = temp.weapon->copy();

  return *this;
}
Hero::~Hero() {
  delete[] name;
}

unsigned Hero::hp() {
  return health;
}

void Hero::levelUp() {
  ++level;
  health += 10;
}
void Hero::equipWeapon(Weapon* temp) {
  weapon = temp->copy();
}
void Hero::equipArmor(Armor* temp) {
  armor = temp->copy();
}
void Hero::takeDamage(unsigned temp) {
  if(armor) {
    int damage = temp - armor->getArmor();
    if(damage > health) {
      std::cout << (name ? name : "Unknown") << " Takes " << damage << " damage and dies! (" << damage - health<< " damage overkill)\n";
      health = 0;
    }
    else {
      std::cout << (name ? name : "Unknown") << " Takes " << damage << " damage!\n";
      health -= damage;
    }
  }
  else {
    if(temp > health) {
      std::cout << (name ? name : "Unknown") << " Takes " << temp << " damage and dies! (" << temp - health<< " damage overkill)\n";
      health = 0;
    }
    else {
      std::cout << (name ? name : "Unknown") << " Takes " << temp << " damage!\n";
      health -= temp;
    }
  }
}
void Hero::dealDamage() {
  std::cout << (name ? name : "Unknown") << " Deals " << weapon->getAttack() << " damage!\n";
}
