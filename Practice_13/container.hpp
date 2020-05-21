#ifndef __CONTAINER_HPP__
#define __CONTAINER_HPP__

template <typename T>
class Container {
public:
  static int const max_size = 100;
  static int const empty_cont = -1;
  T arr[max_size];
  int top = empty_cont;

public:
  virtual void push(T const &) = 0;
  virtual T pop() = 0;
  virtual T peek() = 0;
  virtual int size() = 0;
  virtual bool empty() = 0;

};

#endif
