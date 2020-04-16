#include <iostream>

#include "Fruit.hpp"

Fruit::Fruit() : Eatable() {
  calories = 0;
  protein = 0;
  carbs = 0;
  fat = 0;
}

Fruit::Fruit(double temp_cal, double temp_prot, double temp_carbs, double temp_fat) : Eatable() {
  calories = temp_cal;
  protein = temp_prot;
  carbs = temp_carbs;
  fat = temp_fat;
}

Fruit::Fruit(Taste temp_taste, double temp_cal, double temp_prot, double temp_carbs, double temp_fat) : Eatable(temp_taste) {
  calories = temp_cal;
  protein = temp_prot;
  carbs = temp_carbs;
  fat = temp_fat;
}

void Fruit::print() {
  Eatable::print();
  std::cout << calories << " " << protein << " " << carbs << " " << fat << std::endl;
}
