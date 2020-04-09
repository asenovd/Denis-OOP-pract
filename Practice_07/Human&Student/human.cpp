#include <iostream>
#include <cstring>
#include "human.hpp"

Human::Human() {
  firstName = nullptr;
  lastName = nullptr;
  age = 0;
}

Human::Human(const char* temp_firstName, const char* temp_lastName, int temp_age) {
  firstName = new char[strlen(temp_firstName) + 1];
  strcpy(firstName, temp_firstName);

  lastName = new char[strlen(temp_lastName) + 1];
  strcpy(lastName, temp_lastName);

  age = temp_age;
}

Human::~Human() {
  delete[] firstName;
  delete[] lastName;
}

void Human::setFirstName(const char* temp) {
  delete[] firstName;
  firstName = new char[strlen(temp) + 1];
  strcpy(firstName, temp);
}

void Human::setLastName(const char* temp) {
  delete[] lastName;
  lastName = new char[strlen(temp) + 1];
  strcpy(lastName, temp);
}

void Human::setAge(int temp) {
  age = temp;
}

const char* Human::getFirstName() const {
  return firstName;
}

const char* Human::getLastName() const {
  return lastName;
}

int Human::getAge() const {
  return age;
}
