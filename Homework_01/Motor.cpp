#include <iostream>
#include <cstring>

#include "Motor.hpp"


Motor::Motor() {
  brand = nullptr;
  manufactorYear = 0;
  engineCapacity = 0;
}

Motor::Motor(const char* temp_brand, unsigned temp_manufactorYear, double temp_engineCapacity) {
  brand = new char[strlen(temp_brand) + 1];
  strcpy(brand, temp_brand);
  manufactorYear = temp_manufactorYear;
  engineCapacity = temp_engineCapacity;
}

Motor::Motor(Motor const &temp) {
  brand = new char[strlen(temp.brand) + 1];
  strcpy(brand, temp.brand);
  manufactorYear = temp.manufactorYear;
  engineCapacity = temp.engineCapacity;
}

Motor::~Motor() {
  delete[] brand;
}

Motor &Motor::operator=(Motor const &temp) {
  brand = new char[strlen(temp.brand) + 1];
  strcpy(brand, temp.brand);
  manufactorYear = temp.manufactorYear;
  engineCapacity = temp.engineCapacity;

  return *this;
}

bool Motor::operator==(Motor const &temp) {
  if( !(manufactorYear == temp.manufactorYear) ||
      !(engineCapacity == temp.engineCapacity) ||
      (strcmp(brand, temp.brand))     ) return 0;

  return 1;
}

std::ostream& operator<<(std::ostream& ostr, Motor& temp) {
  ostr << (temp.brand ? temp.brand : "Unknown") << " "
       << temp.manufactorYear << " "
       << temp.engineCapacity << std::endl;
  return ostr;
}


const char* Motor::getBrand() const {
  return brand;
}

unsigned Motor::getManufactorYear() const {
  return manufactorYear;
}

double Motor::getEngineCapacity() const {
  return engineCapacity;
}


void Motor::setBrand(const char* temp) {
  delete[] brand;
  brand = new char[strlen(temp) + 1];
  strcpy(brand, temp);
}

void Motor::setManufactorYear(unsigned temp) {
  manufactorYear = temp;
}

void Motor::setEngineCapacity(double temp) {
  engineCapacity = temp;
}
