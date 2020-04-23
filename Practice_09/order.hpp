#ifndef __ORDER_HPP__
#define __ORDER_HPP__

#include <iostream>
#include "set.hpp"

template <typename TYPE>
class Order : public Set<TYPE> {
  void sort();
public:
  Order();
  Order(Order const &);
  void push(TYPE const &);
};

template <typename TYPE>
void Order<TYPE>::sort() {
  for(unsigned i=0; i<Set<TYPE>::count-1; ++i) {
    for(unsigned j=i+1; j<Set<TYPE>::count; ++j) {
      if(Set<TYPE>::data[i] > Set<TYPE>::data[j]) {
        TYPE temp = Set<TYPE>::data[i];
        Set<TYPE>::data[i] = Set<TYPE>::data[j];
        Set<TYPE>::data[j] = temp;
      }
    }
  }
}

template <typename TYPE>
Order<TYPE>::Order() : Set<TYPE>::Set() {}

template <typename TYPE>
void Order<TYPE>::push(TYPE const &temp) {
  Set<TYPE>::push(temp);
  sort();
}


#endif
