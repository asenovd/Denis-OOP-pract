#include <iostream>

#include "point.hpp"

Point::Point() {
  x=0;
  y=0;
}
Point::Point(int temp_x, int temp_y) {
  x = temp_x;
  y = temp_y;
}
Point::Point(Point const &temp) {
  x = temp.x;
  y = temp.y;
}

Point &Point::operator=(Point const &temp) {
  x = temp.x;
  y = temp.y;

  return *this;
}
bool Point::operator>(Point const &temp) {
  if(x > temp.x || (x == temp.x && y > temp.y)) return true;
  return false;
}
bool Point::operator==(Point const temp) {
  if(x == temp.x && y == temp.y) return true;
  return false;
}
std::ostream &operator<<(std::ostream &ostr, Point const &temp) {
  ostr << temp.x << " " << temp.y << std::endl;
  return ostr;
}

void Point::setX(int temp) {
  x = temp;
}
void Point::setY(int temp) {
  y = temp;
}
int Point::getX() const {
  return x;
}
int Point::getY() const {
  return y;
}
