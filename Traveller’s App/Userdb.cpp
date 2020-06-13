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

void Userdb::saveBIN() {
  std::fstream file2("users.db", std::ios::out | std::ios::in | std::ios::binary);

  file2.seekp(0, std::ios::beg);
  file2.write((char*)&count, sizeof(count));
  file2.close();

  data[count-1]->saveRawBIN();

  file2.close();
}
void Userdb::loadBIN() {
  int counter = 0;
  std::fstream file("users.db", std::ios::out | std::ios::in | std::ios::binary);
  if(!file.good()) {
    file.close();
    return;
  }
  file.read((char*)&counter, sizeof(counter));
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
    User temp;
    temp.setName(nname);
    temp.setPass(npass);
    temp.setEmail(nemail);
    this->push(temp.copy());
    ///cout << "don't remove this or it breaks\n";

    delete[] nname;
    delete[] npass;
    delete[] nemail;
  }
  file.close();
}

void Userdb::saveTXT() {
  data[count-1]->saveRawTXT();
}

void Userdb::loadTXT() {
  std::fstream file("users.db", std::ios::in);

  const static int bSize = 512;
  while (file.peek() != std::ifstream::traits_type::eof()) {
    char buf[bSize];

    file.getline(buf, bSize);
    char* nname = new char[strlen(buf) + 1];
    strcpy(nname, buf);

    file.getline(buf, bSize);
    char* npass = new char[strlen(buf) + 1];
    strcpy(npass, buf);

    file.getline(buf, bSize);
    char* nemail = new char[strlen(buf) + 1];
    strcpy(nemail, buf);

    ///cout << nname << endl << npass << endl << nemail << endl << endl;
    User temp;
    temp.setName(nname);
    temp.setPass(npass);
    temp.setEmail(nemail);
    this->push(temp.copy());
    ///cout << "don't remove this or it breaks\n";
  }
  file.close();
}
