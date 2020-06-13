#ifndef __TRAVELS_HPP__
#define __TRAVELS_HPP__

#include "Date.hpp"

class Travels {
  char* destination;
  char* comment;
  char* photos;
  Date timePeriod[2];
  unsigned short grade;

public:
  Travels();
  Travels(Travels const &);
  ~Travels();
  Travels &operator=(Travels const &);

  friend std::ostream &operator<<(std::ostream&, Travels const &);
  Travels* copy();
  void print() const;

  void setDestination(const char*);
  void setTimePeriod(Date, Date);
  void setGrade(unsigned short);
  void setComment(const char*);
  void setPhotos(const char*);

  const char* getDestination();
  Date* getTimePeriod();
  unsigned short getGrade();
  const char* getComment();
  const char* getPhotos();

};


#endif
