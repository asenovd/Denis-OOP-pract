#include <iostream>

#include "set.hpp"
#include "order.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {
  Order<int> oi;
  oi.push(2);
  oi.push(3);
  oi.push(1);
  oi.push(1);
  oi.push(7);
  oi.push(1);
  oi.push(3);


  for(unsigned i=0, sze=oi.size(); i<sze; ++i) {
    cout << oi[i] << endl;
  }


  return 0;
}
