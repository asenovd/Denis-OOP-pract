#include<iostream>
#include"Rectangulars.hpp"

Rectangulars::Rectangulars() {
  width = 0;
  length = 0;
}

Rectangulars::Rectangulars(int a, int b) {
  width = a;
  length = b;
}

Rectangulars::Rectangulars(const Rectangulars& temp) {
  width = temp.width;
  length = temp.width;
}

int Rectangulars::getWidth() {
  return width;
}

int Rectangulars::getLength() {
  return length;
}

void Rectangulars::setWidth(int temp) {
   width = temp;
}

void Rectangulars::setLength(int temp) {
   length = temp;
}

int Rectangulars::getArea() {
  return width*length;
}
