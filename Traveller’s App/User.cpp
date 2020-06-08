#include <iostream>
#include <fstream>
#include <cstring>

#include "User.hpp"
#include "Utilities.hpp"

User::User() {
  name = nullptr;
  pass = nullptr;
  email = nullptr;
}
User::User(const char* temp_name, const char* temp_pass, const char* temp_email) {
  setString(name, temp_name);
  setString(pass, temp_pass);
  setString(email, temp_email);
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

std::ostream &operator<<(std::ostream &out, User const &temp) {
  out << (temp.name ? temp.name : "Unknown") << " "
      << (temp.pass ? temp.pass : "Unknown") << " "
      << (temp.email ? temp.email : "Unknown") << std::endl;
  return out;
}

User* User::copy() {
  return new User(*this);
}

void User::addTravel(Travels* temp) {
  travels.push(temp);

  char* filename = new char[strlen(name) + 1];
  strcpy(filename, name);
  strcat(filename, ".db");
  std::ofstream file(filename, std::ios::app);
  delete[] filename;
  file << *temp << std::endl << std::endl;
  file.close();
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

const char* User::getName() const {
  return name;
}
const char* User::getPass() const {
  return pass;
}
const char* User::getEmail() const {
  return email;
}
void User::printUserTravels() {
  for(int i=0, sze=travels.size(); i<sze; ++i) {
    std::cout << *travels[i] << std::endl;
  }
}


void User::saveRaw() {
  std::fstream file("users.db", std::ios::out | std::ios::binary | std::ios::app);

  file.seekp(0, std::ios::end);

  int nameLen = strlen(name);
  file.write((char*)&nameLen, sizeof(nameLen));
  file.write(name, nameLen);

  int passLen = strlen(pass);
  file.write((char*)&passLen, sizeof(passLen));
  file.write(pass, passLen);

  int emailLen = strlen(email);
  file.write((char*)&emailLen, sizeof(emailLen));
  file.write(email, emailLen);

  file.close();
}
