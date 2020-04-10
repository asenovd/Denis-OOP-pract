#include <iostream>
#include <cstring>

#include "ListMotor.hpp"
#include "Motorcyclist.hpp"


Motorcyclist::Motorcyclist() {
  name = nullptr;
  age = 0;
  motors = ListMotor();
}

Motorcyclist::Motorcyclist(const char* temp_name, unsigned temp_age) {
  name = new char[strlen(temp_name) + 1];
  strcpy(name, temp_name);
  age = temp_age;
  motors = ListMotor();
}

/*-------------------------------------------------------------*/
Motorcyclist::Motorcyclist(const char* temp_name, unsigned temp_age, ListMotor &temp_motors) {
  name = new char[strlen(temp_name) + 1];
  strcpy(name, temp_name);
  age = temp_age;
  motors = ListMotor(temp_motors);
}

/*-------------------------------------------------------------*/
Motorcyclist::Motorcyclist(Motorcyclist const &temp) {
  name = new char[strlen(temp.name) + 1];
  strcpy(name, temp.name);
  age = temp.age;
  motors = temp.motors;
}

Motorcyclist::~Motorcyclist() {
  delete[] name;
}

Motorcyclist &Motorcyclist::operator=(Motorcyclist const &temp) {
  name = new char[strlen(temp.name) + 1];
  strcpy(name, temp.name);
  age = temp.age;
  motors = temp.motors;

  return *this;
}

bool Motorcyclist::operator>(Motorcyclist const &temp) {
  if( motors.size() > temp.motors.size() ) return 1;
  return 0;
}

bool Motorcyclist::operator<(Motorcyclist const &temp) {
  if( motors.size() < temp.motors.size() ) return 1;
  return 0;
}

std::ostream& operator<<(std::ostream& ostr, Motorcyclist& temp) {
  ostr << "Name: " << (temp.name ? temp.name : "Unknown") << std::endl
       << "Age: "<< temp.age << std::endl;
  if(temp.motors.size() == 0) {
    ostr << "Doesn't own motors. \n";
  }
  else {
    ostr << "Owned Motors:\n"<< temp.motors << std::endl << std::endl;
  }
  return ostr;
}

void Motorcyclist::addMotor(Motor &temp) {
  motors.push(temp);
}
