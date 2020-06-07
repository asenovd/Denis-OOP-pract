#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "Userdb.hpp"

class Commands {
  char* buffer;
  const static int bufferSize = 256;

  Userdb userdb;

  void reg();
  void show();
  void login();
  void load();

  char* extractCommand();
  bool callCommand(const char*);

public:
  Commands();
  Commands(Commands const &);
  ~Commands();

  void run();
};


#endif
