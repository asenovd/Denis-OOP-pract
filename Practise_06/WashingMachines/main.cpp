#include<iostream>
#include<fstream>
#include"WashingMachines.hpp"

using namespace std;

const int MAX_LEN = 32;

void findBestMachine(WashingMachines array[], int sz) {
  int bestMachine = 0;
  for(int i=0; i<sz; i++) {
    if( array[i] > array[bestMachine] ) bestMachine = i;
  }
  ofstream fileOut("out.txt", ios::trunc);
  fileOut << array[bestMachine].getManufacturer() << " ";
  fileOut << array[bestMachine].getModel() << endl;
  fileOut.close();
}

void fillArrayFromFile() {
  int n;
  ifstream fileIn("in.txt");
  fileIn >> n;
  const int sizea = n;
  WashingMachines arr[sizea];
  for(int i=0; i<n; ++i) {
    fileIn.ignore();
    char a1[MAX_LEN];
    fileIn.getline(a1,MAX_LEN);
    arr[i].setManufacturer(a1);

    char a2[MAX_LEN];
    fileIn.getline(a2,MAX_LEN);
    arr[i].setModel(a2);

    int a3;
    fileIn >> a3;
    arr[i].setConsumption(a3);

    double a4;
    fileIn >> a4;
    arr[i].setCapacity(a4);

    int a5;
    fileIn >> a5;
    arr[i].setWater(a5);
  }
  fileIn.close();
  findBestMachine(arr,sizea);
}

int main() {
  fillArrayFromFile();
  return 0;
}
/// g++ main.cpp WashingMachines.cpp -o app
