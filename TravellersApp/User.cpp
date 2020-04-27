#include <iostream>
#include <cstring>

#include "User.hpp"
#include "Utilities.hpp"

User::User() {
  name = nullptr;
  pass = nullptr;
  email = nullptr;
}
User::User(User const &temp) {
  setString(name, temp.name);
  setString(pass, temp.pass);
  setString(email, temp.email);
}
User::~User() {
  delete[] name;
  delete[] pass;
  delete[] email;
}
User &User::operator=(User const &temp) {
  setString(name, temp.name);
  setString(pass, temp.pass);
  setString(email, temp.email);
  return *this;
}

std::ostream &operator<<(std::ostream &ostr, User const &temp) {
  ostr << (temp.name ? temp.name : "Unknown") << " ";
  ostr << (temp.pass ? temp.pass : "Unknown") << " ";
  ostr << (temp.email ? temp.email : "Unknown") << std::endl;
  return ostr;
}

void User::setName(const char* temp) {
  setString(name, temp);
}
void User::setPass(const char* temp) {
  setString(pass, temp);
}
void User::setEmail(const char* temp) {
  setString(email, temp);
}

const char* User::getName() {
  return name;
}
const char* User::getPass() {
  return pass;
}
const char* User::getEmail() {
  return email;
}
