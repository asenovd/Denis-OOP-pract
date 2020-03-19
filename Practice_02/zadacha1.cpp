#include<iostream>
using std::cout;
using std::endl;

class Pace {
  double minutes;
  int kmh;
public:
  Pace() {
    minutes = 0;
    kmh = 0;
  };
  Pace(int min, int sec) {
    minutes = min + double(sec)/60;
    kmh = 60/minutes;
  }
  Pace(int n) {
    kmh = n;
    minutes = 60/n;
  }

  void printMinAndSecPerKm() {
    cout<<minutes<<" min/km";
  }
  void printKmh() {
    cout<<kmh<<" km/h";
  }
};

int main() {
  Pace test(12);
  test.printMinAndSecPerKm();
  cout<<endl;
  test.printKmh();
  return 0;
}
