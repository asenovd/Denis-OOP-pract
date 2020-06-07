#ifndef __USER_HPP__
#define __USER_HPP__

#include "Vector.cpp"
#include "Travels.hpp"

class User {
  char* name;
  char* pass;
  char* email;
  Vector<Travels*> travels;

public:
  User();
  User(const char*, const char*, const char*);
  User(User const &);
  ~User();
  User &operator=(User const &);

  friend std::ostream &operator<<(std::ostream&, User const &);

  User* copy();
  void saveRaw() const;
  void addTravel(Travels*);

  void setName(const char*);
  void setPass(const char*);
  void setEmail(const char*);

  const char* getName() const;
  const char* getPass() const;
  const char* getEmail() const;
  void printUserTravels();

};

#endif
