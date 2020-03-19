#include<iostream>
using std::cout;
using std::endl;

const unsigned short MAX_MIN = 60;
const unsigned short MAX_HOUR = 24;
const unsigned short MIN_HOUR = 0;

class Time {
  unsigned short hours;
  unsigned short minutes;
public:
  Time() {
    hours = 0;
    minutes = 0;
  };
  Time(int h, int m) {
    hours = h;
    minutes = m;
    while(minutes >= MAX_MIN) {
      hours++;
      minutes -= MAX_MIN;
    }
  }

  void get_UTC_n(int n) {
    int temp = hours+n;
    if(temp < MIN_HOUR) temp = MAX_HOUR+n+hours;
    else if(temp >= MAX_HOUR) temp = hours-MAX_HOUR+MIN_HOUR+n;
    cout<<temp<<":"<<minutes<<endl;
  }
  void get_UTC() {
    cout<<hours<<":"<<minutes<<endl;
  }
};

int main() {
  Time london(2,30);
  london.get_UTC_n(-5);
  london.get_UTC();
  return 0;
}
