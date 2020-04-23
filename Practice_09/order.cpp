#ifndef __ORDER_HPP__
#define __ORDER_HPP__

#include <iostream>
#include "set.cpp"

template <typename TYPE>
class Order : public Set<TYPE> {
  using Set<TYPE>::data;
  using Set<TYPE>::reserved;
  using Set<TYPE>::count;
  using Set<TYPE>::isEmpty;

  void sort();
public:
  Order();
  Order(Order const &);
  void push(TYPE const &);
};

template <typename TYPE>
void Order<TYPE>::sort() {
  for(unsigned i=0; i<count-1; ++i) {
    for(unsigned j=i+1; j<count; ++j) {
      if(data[i] > data[j]) {
        TYPE temp = data[i];
        data[i] = data[j];
        data[j] = temp;
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
