#include<iostream>
#include<fstream>
#include"Rectangulars.hpp"

using namespace std;

int main() {
  int n;
  ifstream fileIn("in.txt");
  fileIn >> n;
  const int sz = n;
  Rectangulars arr[sz];
  for(int i=0; i<sz; ++i) {
    int a1;
    fileIn >> a1;
    arr[i].setWidth(a1);
    int a2;
    fileIn >> a2;
    arr[i].setLength(a2);
  }
  fileIn.close();

  ofstream fileOut("out.txt", ios::trunc);
  int maxInd = 0;
  for(int i=1; i<sz; ++i) {
    if(arr[i].getArea() > arr[maxInd].getArea()) maxInd = i;
  }
  fileOut << arr[maxInd].getArea();
  fileOut.close();

  return 0;
}
