#ifndef __HUMAN_HPP__
#define __HUMAN_HPP__

class Human {
protected:
  char* firstName;
  char* lastName;
  int age;
public:
  Human();
  Human(const char*, const char*, int);
  ~Human();

  void setFirstName(const char*);
  void setLastName(const char*);
  void setAge(int);

  const char* getFirstName() const;
  const char* getLastName() const;
  int getAge() const;
};


#endif
