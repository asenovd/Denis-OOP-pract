#ifndef __USERDB_HPP__
#define __USERDB_HPP__

#include "Vector.cpp"
#include "User.hpp"

class Userdb : public Vector<User*> {

public:
  bool isEmailAvailable(const char*) const;
  friend std::ostream &operator<<(std::ostream &, Userdb &);
  void save();
  void load();
};

#endif
