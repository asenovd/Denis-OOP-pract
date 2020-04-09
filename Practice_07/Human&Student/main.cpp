#include <iostream>
#include "human.hpp"
#include "student.hpp"

int main() {
  Student az("Denis", "Asenov", 20, 45680, "inf");
  std::cout << az;

  return 0;
}
