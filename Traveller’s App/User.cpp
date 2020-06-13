#include <iostream>
#include <fstream>
#include <cstring>

#include "User.hpp"
#include "Utilities.hpp"

using std::endl;
using std::cout;

User::User() {
  name = nullptr;
  pass = nullptr;
  email = nullptr;
  travels = TravelDest();
}
User::User(const char* temp_name, const char* temp_pass, const char* temp_email) {
  setString(name, temp_name);
  setString(pass, temp_pass);
  setString(email, temp_email);
  travels = TravelDest();
}
User::User(User const &temp) {
  setString(name, temp.name);
  setString(pass, temp.pass);
  setString(email, temp.email);
  travels = TravelDest();
}
User::~User() {
  delete[] name;
  delete[] pass;
  delete[] email;
  travels.~TravelDest();
}
User &User::operator=(User const &temp) {
  setString(name, temp.name);
  setString(pass, temp.pass);
  setString(email, temp.email);
  travels = temp.travels;
  frl = temp.frl;

  return *this;
}

std::ostream &operator<<(std::ostream &out, User const &temp) {
  out << (temp.name ? temp.name : "Unknown") << " "
      /*<< (temp.pass ? temp.pass : "Unknown") << " "*/
      << (temp.email ? temp.email : "Unknown") << std::endl;
  return out;
}

User* User::copy() {
  return new User(*this);
}
void User::saveRawBIN() {
  std::fstream file("users.db", std::ios::out | std::ios::binary | std::ios::app | std::ios::ate);

  int nameLen = strlen(name);
  file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
  file.write(name, nameLen);

  int passLen = strlen(pass);
  file.write(reinterpret_cast<const char*>(&passLen), sizeof(passLen));
  file.write(pass, passLen);

  int emailLen = strlen(email);
  file.write(reinterpret_cast<const char*>(&emailLen), sizeof(emailLen));
  file.write(email, emailLen);

  file.close();
}
void User::saveRawTXT() {
  std::fstream file("users.db", std::ios::out | std::ios::app | std::ios::ate);

  file << name << endl;
  file << pass << endl;
  file << email << endl;

  file.close();
}
void User::loadTravel() {
  char* filename = new char[strlen(name) + 1];
  strcpy(filename, name);
  strcat(filename, ".db");

  //std::cout << "Loading from file " << filename << "\n";

  std::fstream file;
  file.open(filename, std::ios::in);
  //std::cout << "test 1\n";

  const static int bSize = 512;
  while (file.peek() != std::ifstream::traits_type::eof()) {
    char buf[bSize];

    file.getline(buf, bSize);
    char* ndest = new char[strlen(buf) + 1];
    strcpy(ndest, buf);

    file.getline(buf, bSize);
    Date ndfdate;
    ndfdate.charToDate(buf);

    file.getline(buf, bSize);
    Date ndtdate;
    ndtdate.charToDate(buf);

    file.getline(buf, bSize);
    int ngrade = strToInt(buf);

    file.getline(buf, bSize);
    char* ncomment = new char[strlen(buf) + 1];
    strcpy(ncomment, buf);

    file.getline(buf, bSize);
    char* nphotos = new char[strlen(buf) + 1];
    strcpy(nphotos, buf);

    Travels temp;
    temp.setDestination(ndest);
    temp.setTimePeriod(ndfdate, ndtdate);
    temp.setGrade(ngrade);
    temp.setComment(ncomment);
    temp.setPhotos(nphotos);

    travels.push(temp.copy());
    delete[] ndest;
    delete[] ncomment;
    delete[] nphotos;
  }
  file.close();
}

void User::addTravel(Travels* temp) {
  travels.push(temp);

  char* filename = new char[strlen(name) + 1];
  strcpy(filename, name);
  strcat(filename, ".db");

  std::fstream file(filename, std::ios::out | std::ios::app | std::ios::ate);
  file << *travels[travels.size()-1];
  file.close();
  delete[] filename;
}
void User::addFriend(User* temp) {
  for(unsigned i=0, sze = frl.size(); i<sze; ++i) {
    if(!strcmp(temp->getEmail(), frl[i]->getEmail())) {
      cout << "You're already friends with this person.\n";
      return;
    }
  }
  frl.push(temp);
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
void User::printUserFriends() {
  for(int i=0, sze=travels.size(); i<sze; ++i) {
    std::cout << *frl[i] << std::endl;
  }
}
