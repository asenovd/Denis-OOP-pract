#ifndef __USER_HPP__
#define __USER_HPP__

class User {
  char* name;
  char* pass;
  char* email;

public:
  User();
  User(User const &);
  ~User();
  User &operator=(User const &);

  friend std::ostream &operator<<(std::ostream&, User const &);

  void setName(const char*);
  void setPass(const char*);
  void setEmail(const char*);

  const char* getName();
  const char* getPass();
  const char* getEmail();

};

#endif
