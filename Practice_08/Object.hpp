#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

class Object {
protected:
  double weight;
  double width;
  double length;
  double height;
public:
  Object();
  Object(double, double, double, double);
  void print();
};


#endif
