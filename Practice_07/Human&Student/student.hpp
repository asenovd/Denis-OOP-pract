#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include "human.hpp"

class Student : public Human {
  int FN;
  char* spec;
public:
  Student();
  Student(const char*, const char*, int, int, const char*);
  ~Student();
  friend std::ostream& operator<<(std::ostream&, Student&);

  void setFN(int);
  void setSpec(const char*);

  int getFN() const;
  const char* getSpec() const;
};


#endif
