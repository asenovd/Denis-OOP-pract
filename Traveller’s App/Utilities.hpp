#ifndef __UTILITIES_HPP__
#define __UTILITIES_HPP__

bool isEscapeSeq(const char);
bool isDivider(const char);
bool isCharacter(const char);
bool isNumber(const char);
bool isStringNumber(const char*);

int strToInt(const char*);
double strtoDouble(const char*);

unsigned findTag(const char*);
void removeAfterTag(const char*);

bool validateName(const char*);
bool validateAge(unsigned);
bool validateEmail(const char*);
bool validateFileImage(const char*);

void setString(char* &, const char*);

#endif
