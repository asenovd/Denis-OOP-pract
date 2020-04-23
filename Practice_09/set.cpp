#ifndef __SET_HPP__
#define __SET_HPP__

#include <iostream>

template <typename TYPE>
class Set {
protected:
  TYPE* data;
  unsigned reserved;
  unsigned count;

public:
  Set();
  Set(Set const &);
  ~Set();

  Set &operator=(Set const &);
  TYPE &operator[](unsigned);

  bool isEmpty();
  unsigned size() const;
  void push(TYPE const &);
  void remove(unsigned);
};


template <typename TYPE>
Set<TYPE>::Set() {
  reserved = 32;
  data = new TYPE[reserved];
  count = 0;
}

template <typename TYPE>
Set<TYPE>::Set(Set const &temp) {
  delete[] data;

  reserved = temp.reserved;
  count = temp.count;
  data = new TYPE[reserved];

  for(unsigned i=0; i<count; ++i) {
    data[i] = temp.data[i];
  }
}


template <typename TYPE>
Set<TYPE>::~Set() {
  delete[] data;
}

template <typename TYPE>
Set<TYPE> &Set<TYPE>::operator=(Set const &temp) {
  delete[] data;

  reserved = temp.reserved;
  count = temp.count;
  data = new TYPE[reserved];

  for(unsigned i=0; i<count; ++i) {
    data[i] = temp.data[i];
  }
  return *this;
}

template <typename TYPE>
TYPE& Set<TYPE>::operator[](unsigned i) {
  return data[i];
}

template <typename TYPE>
bool Set<TYPE>::isEmpty() {
  return !count;
}

template <typename TYPE>
unsigned Set<TYPE>::size() const {
  return count;
}

template <typename TYPE>
void Set<TYPE>::push(TYPE const &temp) {
  if(isEmpty()) {
    data[count++] = temp;
    return;
  }
  else {
    for(unsigned i=0; i<count; ++i) {
      if(data[i] == temp) {
        return;
      }
    }
    if(count == reserved) {
      reserved *= 2;
      TYPE* newData = new TYPE[reserved];
      for(unsigned i=0; i<count; ++i) {
        newData[i] = data[i];
      }
      delete[] data;
      data = newData;
    }
    data[count++] = temp;
    return;
  }
}

template <typename TYPE>
void Set<TYPE>::remove(unsigned ind) {
  if(ind >= count) {
    return;
  }
  else {
    TYPE* newData = new TYPE[reserved];
    for(unsigned i=0; i<ind; ++i) {
      newData[i] = data[i];
    }
    count--;
    for(unsigned i=ind; i<count; ++i) {
      newData[i] = data[i+1];
    }
    delete[] data;
    data = newData;
  }
}


#endif
