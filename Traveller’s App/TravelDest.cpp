#include <iostream>
#include <fstream>
#include <cstring>

#include "Utilities.hpp"
#include "TravelDest.hpp"
#include "Travels.hpp"
#include "Date.hpp"

using std::cout;
using std::endl;

TravelDest::TravelDest() {
  reservedSpace = MINIMUM_SPACE;
  data = new Travels*[reservedSpace];
  count = 0;
}

TravelDest::~TravelDest() {
  delete[] data;
}
