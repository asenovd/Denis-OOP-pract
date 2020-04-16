#include<iostream>
#include<cstring>
#include"WashingMachines.hpp"

WashingMachines::WashingMachines() {
  manufacturer = nullptr;
  model = nullptr;
  capacity = 0;
  consumption = 0;
  water = 0;
}

WashingMachines::WashingMachines(const char* tempManufacturer, const char* tempModel, int tempCapacity, double tempConsumption, int tempWater) {
  manufacturer = new char[strlen(tempManufacturer)+1];
  strcpy(manufacturer, tempManufacturer);

  model = new char[strlen(tempModel)+1];
  strcpy(model, tempModel);

  capacity = tempCapacity;
  consumption = tempConsumption;
  water = tempWater;
}

WashingMachines::WashingMachines(const WashingMachines &temp) {
  manufacturer = new char[strlen(temp.manufacturer)+1];
  strcpy(manufacturer, temp.manufacturer);

  model = new char[strlen(temp.model)+1];
  strcpy(model, temp.model);

  capacity = temp.capacity;
  consumption = temp.consumption;
  water = temp.water;
}

bool WashingMachines::operator>(WashingMachines const &temp) {
  short compr = 0;
  if( capacity > temp.capacity ) compr++;
  else compr--;
  if( consumption < temp.consumption ) compr++;
  else compr--;
  if( water < temp.water ) compr++;
  else compr--;

  if(compr>0) return 1;
  else return 0;
}

WashingMachines::~WashingMachines() {
  delete[] manufacturer;
  delete[] model;
}


char* WashingMachines::getManufacturer() {
  return manufacturer;
}
char* WashingMachines::getModel() {
  return model;
}
int WashingMachines::getCapacity() {
  return capacity;
}
double WashingMachines::getConsumption() {
  return consumption;
}
int WashingMachines::getWater() {
  return water;
}


void WashingMachines::setManufacturer(const char* temp) {
  delete[] manufacturer;
  manufacturer = new char[strlen(temp)+1];
  strcpy(manufacturer, temp);
}
void WashingMachines::setModel(const char* temp) {
  delete[] model;
  model = new char[strlen(temp)+1];
  strcpy(model, temp);
}
void WashingMachines::setCapacity(int temp) {
  capacity = temp;
}
void WashingMachines::setConsumption(double temp) {
  consumption = temp;
}
void WashingMachines::setWater(int temp) {
  water = temp;
}
