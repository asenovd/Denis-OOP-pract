#ifndef __UTILITIES_HPP__
#define __UTILITIES_HPP__

bool isEscapeSeq(const char);
bool isDivider(const char);
bool isCharacter(const char);

int strToInt(const char*);

bool validateName(const char*);
bool validatePass(const char*);
bool validateEmail(const char*);
bool validateFileImage(const char*);

void setString(char* &, const char*);

#endif
