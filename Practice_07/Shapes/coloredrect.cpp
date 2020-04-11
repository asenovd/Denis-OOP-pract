#include <iostream>
#include <cstring>
#include "shape.hpp"
#include "rectangular.hpp"
#include "coloredrect.hpp"

ColoredRectangular::ColoredRectangular() {
  color = nullptr;
}

ColoredRectangular::ColoredRectangular(const char* temp_color) {
  color = new char[strlen(temp_color) + 1];
  strcpy(color, temp_color);
}


ColoredRectangular::ColoredRectangular(const char* temp_color, Rectangular temp_rect) : Rectangular(temp_rect.getWidth(), temp_rect.getLength()) {
  color = new char[strlen(temp_color) + 1];
  strcpy(color, temp_color);
}

ColoredRectangular::ColoredRectangular(double tempW, double tempL, const char* temp_color) : Rectangular(tempW, tempL) {
  color = new char[strlen(temp_color) + 1];
  strcpy(color, temp_color);
}

ColoredRectangular::ColoredRectangular(TYPE temp_type, unsigned temp_dim, double tempW, double tempL, const char* temp_color) : Rectangular(temp_type, temp_dim, tempW, tempL) {
  color = new char[strlen(temp_color) + 1];
  strcpy(color, temp_color);
}

ColoredRectangular::~ColoredRectangular() {
  delete[] color;
}

std::ostream& operator<<(std::ostream& ostr, ColoredRectangular& temp) {
    if(temp.type == IRREGULAR) {
      ostr << "CRect - Irregular Shape" << "   ";
    }
    else {
      ostr << "CRect - Regular Shape" << "   ";
    }
    ostr << "Dimensions: "<< temp.dimensions << "   "
         << "Width: "<< temp.getWidth() << "   "
         << "Length: "<< temp.getLength() << "   "
         << "Color: "<< (temp.color ? temp.color : "none") << std::endl;
    return ostr;
}


void ColoredRectangular::setColor(const char* temp) {
  delete[] color;
  color = new char[strlen(temp) + 1];
  strcpy(color, temp);
}

const char* ColoredRectangular::getColor() const {
  return color;
}
