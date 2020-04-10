#include <iostream>
#include "Motor.hpp"
#include "ListMotor.hpp"
#include "Motorcyclist.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {
  Motor m2("gosho", 1969, 6.9);

  ListMotor lm1;
  lm1.push(m2);

  Motorcyclist mc("pesho", 20, lm1);
  cout << mc << endl << endl;
  mc.addMotor(m2);
  mc.addMotor(m2);

  Motorcyclist mc2(mc);
  mc2.addMotor(m2);
  cout << (mc>mc2) << endl;


  return 0;
}
