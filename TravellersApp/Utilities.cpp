#include <iostream>
#include <cstring>

#include "Utilities.hpp"


bool isEscapeSeq(const char symb) {
  return symb == ' ' || symb == '\n' || symb == '\0';
}
bool isDivider(const char symb) {
  return symb == '.' || symb == '-' || symb == '/' || symb == ',';
}
bool isCharacter(const char symb) {
  return (symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z');
}
bool isNumber(const char symb) {
  return (symb >= '0' && symb <= '9');
}
bool isStringNumber(const char* str) {
  unsigned i = 0;
  while(str[i]) {
    if(!isNumber(str[i++])) return false;
  }
  return true;
}

int strToInt(const char* str) {
  unsigned i = 0;
  bool negative = str[i] == '-';
  if(negative) ++i;
  int n = 0;
  while(str[i]) {
    n = n*10 + (str[i++] - '0');
  }
  if(negative) {
    n = -n;
  }
  return n;
}
double strtoDouble(const char* str) {
  unsigned i = 0;
  bool negative = str[i] == '-';
  if(negative) ++i;

  int n = 0;
  while(str[i] != '.' && str[i]) {
    n = n*10 + (str[i++] - '0');
  }
  if(!str[i]) {
    if(negative) {
      n = -n;
    }
    return n;
  }
  else {
    unsigned j = ++i;
    double n2 = 0;
    while(str[j]) {
      n2 = n2*10 + (str[j++] - '0');
    }
    while(i<j) {
      n2 /= 10;
      ++i;
    }
    double res = n2+n;
    if(negative) {
      res = -res;
    }
    return res;
  }
}

unsigned findTag(const char* str) {
  unsigned i = 0;
  while(str[i]) {
    if(str[i] == '#') {
      return strToInt(str+i+1);
    }
    ++i;
  }
  return 0;
}
void removeAfterTag(char* str) {
  unsigned i = 0;
  while(str[i]) {
    if(str[i] == '#') {
      str[i] = '\0';
    }
    ++i;
  }
}

bool validateName(const char* str) {
  unsigned i = 0;
  while(str[i]) {
    if(!isCharacter(str[i++])) return false;
  }
  return true;
}
bool validateAge(unsigned num) {
  return num<=90;
}
bool validateEmail(const char* str) {
  unsigned i = 0;
  if(!isCharacter(str[i])) {
    return false;
  }
  ++i;

  while(str[i] != '@' && str[i]) {
    ++i;
  }
  ++i;

  if(!isCharacter(str[i])) {
    return false;
  }
  ++i;

  while(str[i] != '.' && str[i]) {
    ++i;
  }
  ++i;

  if(!isCharacter(str[i])) {
    return false;
  }

  return true;
}

void setString(char* &current, const char* temp) {
  if(current) delete[] current;
  current = new char[strlen(temp)+1];
  strcpy(current, temp);
}
