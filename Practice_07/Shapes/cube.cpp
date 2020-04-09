#include <iostream>
#include "shape.hpp"
#include "square.hpp"
#include "cube.hpp"

Cube::Cube() {
  walls = Square();
}

Cube::Cube(Square temp_square) {
  walls = Square(temp_square.Square::getLength());
}

Cube::Cube(TYPE temp_type, unsigned temp_dim, unsigned temp_length) : Square(temp_type, temp_dim, temp_length) {
  walls = Square(temp_length);
}

Cube::Cube(TYPE temp_type, unsigned temp_dim, Square temp_square) : Square(temp_type, temp_dim, temp_square.Square::getLength()) {
  walls = Square(temp_square.Square::getLength());
}

std::ostream& operator<<(std::ostream& ostr, Cube& temp) {
    if(temp.type == IRREGULAR) {
      ostr << "Cube - Irregular Shape" << "   ";
    }
    else {
      ostr << "Cube - Regular Shape" << "   ";
    }
    ostr << "Dimensions: "<< temp.dimensions << "   "
         << "Length: "<< temp.walls.getLength() << std::endl;
    return ostr;
}

unsigned Cube::getLength() const {
  return walls.Square::getLength();
}
