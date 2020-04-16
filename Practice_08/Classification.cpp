#include <iostream>
#include <cstring>

#include "Classification.hpp"

Classification::Classification() {
  price = 0;
  barcode = nullptr;
  category = nullptr;
}

Classification::Classification(double temp_price, const char* temp_barcode, const char* temp_category) {
  price = temp_price;

  barcode = new char[strlen(temp_barcode) + 1];
  strcpy(barcode, temp_barcode);

  category = new char[strlen(temp_category) + 1];
  strcpy(category, temp_category);
}

void Classification::print() {
  std::cout << price << " " << (barcode ? barcode : "Unknown") << " " << (category ? category : "Unknown") << std::endl;
}
