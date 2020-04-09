#include <iostream>
#include "shape.hpp"
#include "rectangular.hpp"
#include "coloredrect.hpp"
#include "square.hpp"
#include "cube.hpp"

using std::cout;
using std::endl;

int main() {
  Rectangular r1;
  Rectangular r2(3,5);
  Rectangular r3(REGULAR, 2, 6, 7);

  ColoredRectangular cr1;
  ColoredRectangular cr2("red");
  ColoredRectangular cr3("blue", r3);
  ColoredRectangular cr4(3, 12, "green");
  ColoredRectangular cr5(REGULAR, 2, 24, 27, "yellow");

  cout << cr1;
  cout << cr2;
  cout << cr3;
  cout << cr4;
  cout << cr5 << endl << endl << endl;

  Square s1;
  Square s2(5);
  Square s3(REGULAR, 2, 3);

  Cube c1;
  Cube c2(s3);
  Cube c3(REGULAR, 3, 9);
  Cube c4(REGULAR, 3, s3);
  cout << c1;
  cout << c2;
  cout << c3;
  cout << c4;
}
