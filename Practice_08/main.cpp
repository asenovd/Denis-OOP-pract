#include <iostream>

#include "Eatable.hpp"
#include "Classification.hpp"
#include "Object.hpp"
#include "Fruit.hpp"
#include "Product.hpp"
#include "Banana.hpp"

using std::cout;
using std::endl;

int main() {
  cout<<"--------------\n";
  /*
  Eatable a1;
  Classification a2;
  Object a3;
  Fruit a4;
  Product a5;
  Banana a6;

  a1.print();
  cout<<"--------------\n";
  a2.print();
  cout<<"--------------\n";
  a3.print();
  cout<<"--------------\n";
  a4.print();
  cout<<"--------------\n";
  a5.print();
  cout<<"--------------\n";
  a6.print();
  cout<<"--------------\n";
  cout<<"--------------\n";
  cout<<"--------------\n";
  cout<<"--------------\n";
  */

  /*
  Eatable b1(SOUR);
  Classification b2(3.20, "1101", "nam");
  Object b3(5,10,15,20);
  Fruit b4(SWEET,30,40,50,60);
  Product b5(6.90, "0000", "prod", 7, 8, 9, 10);
  Banana b6(SAVORY,150,200,250,300, 4.50, "1111", "banan", 10, 15, 20, 25);

  b1.print();
  cout<<"--------------\n";
  b2.print();
  cout<<"--------------\n";
  b3.print();
  cout<<"--------------\n";
  b4.print();
  cout<<"--------------\n";
  b5.print();
  cout<<"--------------\n";
  b6.print();
  cout<<"--------------\n";
  */

  Banana banan1(SWEET, 105, 1.3, 27, 0.4, 0.70, "10101011", "Fiber Plant", 118, 3, 3, 21);
  banan1.print();
  cout<<"\n--------------\n";
  cout<<banan1.getVolume();
  cout<<"\n--------------\n";
  cout<<banan1.getPricePerWeight();
  cout<<"\n--------------\n";
  cout<<banan1.getPricePerVolume();
  cout<<"\n--------------\n";
  cout<<banan1.getFatWeight();
  cout<<"\n--------------\n";
  cout<<banan1.getPricePerCallories();
  cout<<"\n--------------\n";


  return 0;
}
