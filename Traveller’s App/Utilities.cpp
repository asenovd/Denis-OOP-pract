#include <iostream>
#include <cstring>

#include "Utilities.hpp"


using namespace std;
bool isEscapeSeq(const char symb) {
  return symb == ' ' || symb == '\n' || symb == '\0';
}
bool isDivider(const char symb) {
  return symb == '.' || symb == '-' || symb == '/' || symb == ',';
}
bool isCharacter(const char symb) {
  return (symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z') || symb == '_';
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

bool validateName(const char* str) {
  unsigned i = 0;
  while(str[i]) {
    if(!isCharacter(str[i++])) return false;
  }
  return true;
}
bool validatePass(const char* num) {
  return (strlen(num) <= 15);
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
bool validateFileImage(const char* str) {
  unsigned i=0;
  while(str[i] != '.') {
    if(!isCharacter(str[i]) || str[i] == '.') return 0;
    ++i;
  }
  str += i+1;

  if(strcmp(str, "jpeg") && strcmp(str, "png")) return 0;

  return 1;
}

void setString(char* &current, const char* temp) {
  if(current) delete[] current;
  current = new char[strlen(temp)+1];
  strcpy(current, temp);
}
