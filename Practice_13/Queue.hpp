#ifndef __Queue_HPP__
#define __Queue_HPP__

#include "container.hpp"

template<typename T>
class Queue : public Container<T> {
public:
  using Container<T>::max_size;
  using Container<T>::empty_cont;
  using Container<T>::arr;
  using Container<T>::top;

  void push(T const &);
  T pop();
  T peek();
  int size();
  bool empty();
  
};

template<typename T>
void Queue<T>::push(T const &temp) {
  if(top == max_size-1) return;
  arr[++top] = temp;
}

template<typename T>
T Queue<T>::pop() {
  if(!empty()) {
    T temp = arr[0];
    for(int i=0; i<top; ++i) {
      arr[i] = arr[i+1];
    }
    --top;
    return temp;
  }
  return 0;
}

template<typename T>
T Queue<T>::peek() {
  if(!empty()) {
    return arr[0];
  }
  return 0;
}

template<typename T>
int Queue<T>::size() {
  return top-1;
}

template<typename T>
bool Queue<T>::empty() {
  return top == empty_cont;
}


#endif
