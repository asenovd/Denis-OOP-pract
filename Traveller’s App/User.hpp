#ifndef __USER_HPP__
#define __USER_HPP__

#include "TravelDest.hpp"
#include "Vector.cpp"

class User {
  char* name;
  char* pass;
  char* email;
  TravelDest travels;
  Vector<User*> frl;

public:
  User();
  User(const char*, const char*, const char*);
  User(User const &);
  ~User();
  User &operator=(User const &);

  friend std::ostream &operator<<(std::ostream&, User const &);

  User* copy();
  void saveRawBIN();
  void saveRawTXT();
  void loadTravel();
  void addTravel(Travels*);
  void addFriend(User*);

  void setName(const char*);
  void setPass(const char*);
  void setEmail(const char*);

  const char* getName() const;
  const char* getPass() const;
  const char* getEmail() const;
  void printUserTravels();
  void printUserFriends();

};

#endif
