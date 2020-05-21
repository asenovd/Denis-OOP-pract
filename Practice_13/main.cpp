#include <iostream>

#include "Stack.hpp"
#include "Queue.hpp"

using std::cout;
using std::endl;

int main() {

  Stack<int> s;
  s.push(3);
  s.push(4);
  s.push(5);
  cout << s.peek() << endl;
  while(!s.empty()) {
    cout << s.pop() << endl;
  }

  cout << endl << endl;

  Queue<double> q;
  q.push(4.2);
  q.push(5.3);
  q.push(6.4);
  cout << q.peek() << endl;
  while(!q.empty()) {
    cout << q.pop() << endl;
  }

  return 0;
}
