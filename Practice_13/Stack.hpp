#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "container.hpp"

template<typename T>
class Stack : public Container<T> {
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
void Stack<T>::push(T const &temp) {
  if(top == max_size-1) return;
  arr[++top] = temp;
}

template<typename T>
T Stack<T>::pop() {
  if(!empty()) {
    return arr[top--];
  }
  return 0;
}

template<typename T>
T Stack<T>::peek() {
  if(!empty()) {
    return arr[top];
  }
  return 0;
}

template<typename T>
int Stack<T>::size() {
  return top-1;
}

template<typename T>
bool Stack<T>::empty() {
  return top == empty_cont;
}


#endif
