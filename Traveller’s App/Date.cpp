#include <iostream>
#include <cstring>

#include "Date.hpp"
#include "Utilities.hpp"

void Date::setNums(unsigned short temp_year, unsigned short temp_month, unsigned short temp_day) {
  year = temp_year;
  month = temp_month;
  day = temp_day;
}
void Date::charToDate(const char* temp) {
  unsigned i=0;
  while(!isDivider(temp[i]) && temp[i]) {
    ++i;
  }
  unsigned j=0;
  unsigned nYear = 0;
  while(j<i) {
    nYear = nYear*10 + (temp[j++] - '0');
  }
  if(isDivider(temp[i])) {
    ++j;
    ++i;
  }
  while(!isDivider(temp[i]) && temp[i]) {
    ++i;
  }
  unsigned nMonth = 0;
  while(j<i) {
    nMonth = nMonth*10 + (temp[j++] - '0');
  }
  if(isDivider(temp[i])) {
    ++j;
    ++i;
  }
  while(!isDivider(temp[i]) && temp[i]) {
    ++i;
  }
  unsigned nDay = 0;
  while(j<i) {
    nDay = nDay*10 + (temp[j++] - '0');
  }
  setNums(nYear, nMonth, nDay);
}
bool Date::validate() const {
  if((month > 12) || (month == 2 && day > 28)) return 0;
  else if (month == 1  ||
      month == 3  ||
      month == 5  ||
      month == 7  ||
      month == 8  ||
      month == 10 ||
      month == 12) {
        if(day > 31) return 0;
      }
  else if (month == 4 ||
           month == 6 ||
           month == 9 ||
           month == 11) {
             if(day > 30) return 0;
           }
  return 1;
}

Date::Date() {
  setNums(0, 0, 0);
}
Date::Date(unsigned short temp_year, unsigned short temp_month, unsigned short temp_day) {
  setNums(temp_year, temp_month, temp_day);
}
Date::Date(const char* temp) {
  charToDate(temp);
}
Date::Date(Date const &temp) {
  setNums(temp.year, temp.month, temp.day);
}

Date &Date::operator=(int temp) {
  setNums(0, 0, 0);
  return *this;
}
bool Date::operator>(Date const &temp) {
  if(year > temp.year) return 1;
  if(year < temp.year) return 0;

  if(month > temp.month) return 1;
  if(month < temp.month) return 0;

  if(day > temp.day) return 1;
  if(day <= temp.day) return 0;
  return 1;
}
Date &Date::operator=(Date const &temp) {
  setNums(temp.year, temp.month, temp.day);
  return *this;
}
std::ostream &operator<<(std::ostream &out, Date const &temp) {
  out << temp.year << ".";
  if(temp.month < 10) {
    out << "0" << temp.month << ".";
  }
  else out << temp.month << ".";
  if(temp.day < 10) {
    out << "0" << temp.day;
  }
  else out << temp.day;
  return out;
}

void Date::setDay(unsigned short temp) {
  day = temp;
}
void Date::setMonth(unsigned short temp) {
  month = temp;
}
void Date::setYear(unsigned short temp) {
  year = temp;
}

unsigned short Date::getDay() {
  return day;
}
unsigned short Date::getMonth() {
  return month;
}
unsigned short Date::getYear() {
  return year;
}
