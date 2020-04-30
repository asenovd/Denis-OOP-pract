#include <iostream>

#include "Shape.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Vector.cpp"

using std::cout;
using std::endl;

int main() {
  Triangle t1(3,4,5);
  Rectangle r1(6,8);
  Square s1(2);

  typedef Vector<Shape*> Figures;
  Figures arr;
  arr.push(&t1);
  arr.push(&r1);
  arr.push(&s1);
  
  cout << arr.getMaxPerim() << endl;
  cout << arr.getMaxArea() << endl;

  return 0;
}
