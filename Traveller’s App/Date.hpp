#ifndef __DATE_HPP__
#define __DATE_HPP__

class Date {
  unsigned short year;
  unsigned short month;
  unsigned short day;

  void setNums(unsigned short, unsigned short, unsigned short);
public:
  Date();
  Date(unsigned short, unsigned short, unsigned short);
  Date(const char*);
  Date(Date const &);

  Date &operator=(int temp);
  Date &operator=(Date const &);
  bool operator>(Date const &);
  friend std::ostream &operator<<(std::ostream&, Date const &);
  void charToDate(const char*);
  bool validate() const;

  void setYear(unsigned short);
  void setMonth(unsigned short);
  void setDay(unsigned short);

  unsigned short getYear();
  unsigned short getMonth();
  unsigned short getDay();

};

#endif
