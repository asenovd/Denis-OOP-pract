#include <iostream>
#include <cstring>

#include "Utilities.hpp"
#include "User.hpp"
#include "Travels.hpp"
#include "Date.hpp"

using std::cout;
using std::endl;

int main() {
  User u1;
  u1.setName("Deni");
  u1.setPass("asd123");
  u1.setEmail("deni@abv.bg");
  cout << validateEmail(u1.getEmail()) << endl << endl;

  Date d1(2000,6,3);
  Date d2("2000.6.17");

  Travels t1;
  t1.setDestination("Burgas");
  t1.setTimePeriod(d1,d2);
  t1.setGrade(3);
  t1.setComment("A beautiful city on the Black Sea coast. I spent two unforgettable weeks there.");
  t1.setPhotos("burgas.jpeg \nlocumfest.png \nsunrise_on_the_coast.jpeg");

  cout << t1 << endl;

  return 0;
}
