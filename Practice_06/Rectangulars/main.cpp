#include<iostream>
#include<fstream>
#include"Rectangulars.hpp"


int main() {
  int n;
  std::ifstream fileIn("in.txt");
  fileIn >> n;
  Rectangulars* arr = new Rectangulars[n];
  for(int i=0; i<n; ++i) {
    int a1;
    fileIn >> a1;
    arr[i].setWidth(a1);
    int a2;
    fileIn >> a2;
    arr[i].setLength(a2);
  }
  fileIn.close();

  std::ofstream fileOut("out.txt", std::ios::trunc);
  int maxInd = arr[0].getArea();
  for(int i=1; i<n; ++i) {
    if(arr[i].getArea() > arr[maxInd].getArea()) maxInd = i;
  }
  fileOut << arr[maxInd].getArea();
  fileOut.close();

  return 0;
}
