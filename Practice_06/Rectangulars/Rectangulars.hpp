#ifndef __RECTANGULARS__
#define __RECTANGULARS__

#include<iostream>

class Rectangulars {
  int width;
  int length;
public:
  Rectangulars();
  Rectangulars(int, int);
  Rectangulars(const Rectangulars&);
  bool operator>(Rectangulars const &);

  int getWidth();
  int getLength();
  void setWidth(int);
  void setLength(int);

  int getArea();
};

#endif
