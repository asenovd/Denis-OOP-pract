#include <iostream>
#include <cstring>
#include "human.hpp"
#include "student.hpp"

Student::Student() {
  FN = 0;
  spec = nullptr;
}

Student::Student(const char* temp_firstName, const char* temp_lastName, int temp_age, int temp_FN, const char* temp_spec) : Human::Human(temp_firstName, temp_lastName, temp_age) {
  FN = temp_FN;
  spec = new char[strlen(temp_spec) + 1];
  strcpy(spec, temp_spec);
}

Student::~Student() {
  delete[] spec;
}

std::ostream& operator<<(std::ostream& ostr, Student& temp) {
    ostr << temp.firstName << " "
         << temp.lastName << " "
         << temp.age << " "
         << temp.FN << " "
         << temp.spec << std::endl;
    return ostr;
}

void Student::setFN(int temp) {
  FN = temp;
}

void Student::setSpec(const char* temp) {
  delete[] spec;
  spec = new char[strlen(temp) + 1];
  strcpy(spec, temp);
}

int Student::getFN() const {
  return FN;
}

const char* Student::getSpec() const {
  return spec;
}
