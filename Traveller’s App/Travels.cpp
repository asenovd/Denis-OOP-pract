#include <iostream>
#include <cstring>

#include "Travels.hpp"
#include "Utilities.hpp"

using std::endl;

Travels::Travels() {
  destination = nullptr;
  timePeriod[0] = 0;
  timePeriod[1] = 0;
  grade = 0;
  comment = nullptr;
  photos = nullptr;
}
Travels::Travels(Travels const &temp) {
  setString(destination, temp.destination);
  timePeriod[0] = temp.timePeriod[0];
  timePeriod[1] = temp.timePeriod[1];
  grade = temp.grade;
  setString(comment, temp.comment);
  setString(photos, temp.photos);
}
Travels::~Travels() {
  delete[] destination;
  delete[] comment;
  delete[] photos;
}
Travels &Travels::operator=(Travels const &temp) {
  setString(destination, temp.destination);
  timePeriod[0] = temp.timePeriod[0];
  timePeriod[1] = temp.timePeriod[1];
  grade = temp.grade;
  setString(comment, temp.comment);
  setString(photos, temp.photos);
  return *this;
}

std::ostream &operator<<(std::ostream &out, Travels const &temp) {
  out << (temp.destination ? temp.destination : "Unknown") << endl
      << temp.timePeriod[0] << endl << temp.timePeriod[1] << endl
      << temp.grade << endl
      << temp.comment << endl
      << temp.photos << endl;
  return out;
}
Travels* Travels::copy() {
  return new Travels(*this);
}
void Travels::print() const {
  std::cout << (destination ? destination : "Unknown") << endl
      << timePeriod[0] << endl << timePeriod[1] << endl
      << grade << endl
      << comment << endl
      << photos << endl << endl;
}

void Travels::setDestination(const char* temp) {
  setString(destination, temp);
}
void Travels::setTimePeriod(Date temp1, Date temp2) {
  timePeriod[0] = temp1;
  timePeriod[1] = temp2;
}
void Travels::setGrade(unsigned short temp) {
  grade = temp;
}
void Travels::setComment(const char* temp) {
  setString(comment, temp);
}
void Travels::setPhotos(const char* temp) {
  setString(photos, temp);
}

const char* Travels::getDestination() {
  return destination;
}
Date* Travels::getTimePeriod() {
  return timePeriod;
}
unsigned short Travels::getGrade() {
  return grade;
}
const char* Travels::getComment() {
  return comment;
}
const char* Travels::getPhotos() {
  return photos;
}
