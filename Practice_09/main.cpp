#include <iostream>

#include "set.cpp"
#include "order.cpp"
#include "point.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {
  Order<Point> OP;
  Point p1(3,4);
  Point p2(1,6);
  Point p3(2,1);
  Point p4(2,1);
  Point p5(2,1);
  Point p6(2,1);
  Point p7(2,1);
  Point p8(2,1);
  Point p9(2,4);
  Point p10(2,2);

  OP.push(p1);
  OP.push(p2);
  OP.push(p3);
  OP.push(p4);
  OP.push(p5);
  OP.push(p6);
  OP.push(p7);
  OP.push(p8);
  OP.push(p9);
  OP.push(p10);

  for(int i=0, sze = OP.size(); i<sze; ++i) {
    cout << OP[i] << endl;
  }



  return 0;
}
