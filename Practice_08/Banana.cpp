#include <iostream>

#include "Banana.hpp"

Banana::Banana() : Fruit(), Product() {}

Banana::Banana(Taste temp_taste,
   double temp_calories,
   double temp_protein,
   double temp_carbs,
   double temp_fats,
   double temp_price,
   const char* temp_barcode,
   const char* temp_category,
   double temp_weight,
   double temp_width,
   double temp_length,
   double temp_height) :
   Fruit(temp_taste, temp_calories, temp_protein, temp_carbs, temp_fats),
   Product(temp_price, temp_barcode, temp_category, temp_weight, temp_width, temp_length, temp_height) {}

double Banana::getPricePerCallories() {
  return price/calories;
}

double Banana::getFatWeight() {
  return fat/weight;
}

void Banana::print() {
  Fruit::print();
  Product::print();
}
