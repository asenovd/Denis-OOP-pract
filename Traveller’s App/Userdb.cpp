#include <iostream>
#include <fstream>
#include <cstring>

#include "Userdb.hpp"
#include "User.hpp"

using std::cout;
using std::endl;

bool Userdb::isEmailAvailable(const char* temp) const {
  for(unsigned i=0; i<count; ++i) {
    if(!strcmp(temp, data[i]->getEmail())) return 0;
  }
  return 1;
}

std::ostream &operator<<(std::ostream &ostr, Userdb &temp) {
  for(unsigned i=0, sze=temp.size(); i<sze; ++i) {
    ostr << *temp[i];
  }
  return ostr;
}

void Userdb::save() {
  std::fstream file2("users.db", std::ios::out | std::ios::binary | std::ios::trunc);

  file2.seekp(0, std::ios::beg);
  file2.write((char*)&count, sizeof(count));
  file2.seekp(0, std::ios::end);
  file2.close();

  data[count-1]->saveRaw();
}

void Userdb::load() {
  int counter = 0;
  std::ifstream file("users.db", std::ios::binary);
  file.read((char*)&counter, sizeof(counter));
  std::cout << counter << std::endl;

  for(unsigned i=0; i<counter; ++i) {
    int nameLen;
    file.read((char *)&nameLen, sizeof(nameLen));
    char* nname = new char[nameLen + 1];
    file.read(nname, nameLen);
    nname[nameLen] = 0;

    int passLen;
    file.read((char *)&passLen, sizeof(passLen));
    char* npass = new char[passLen + 1];
    file.read(npass, passLen);
    npass[passLen] = 0;

    int emailLen;
    file.read((char *)&emailLen, sizeof(emailLen));
    char* nemail = new char[emailLen + 1];
    file.read(nemail, emailLen);
    nemail[emailLen] = 0;

    User temp(nname, npass, nemail);
    this->push(temp.copy());
    delete[] nname;
    delete[] npass;
    delete[] nemail;
  }
}
