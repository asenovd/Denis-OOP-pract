#include <iostream>

#include "ListMotor.hpp"
#include "Motor.hpp"

ListMotor::ListMotor() {
  count = 0;
  reserved = INITIAL_RESERVED;
  data = new Motor[reserved];
}

ListMotor::~ListMotor() {
  delete[] data;
}

Motor &ListMotor::get(int i) {
  return data[i];
}

void ListMotor::push(Motor &temp) {
  if (count == reserved) {
    Motor *newData = new Motor[reserved * 2];
    for (int i = 0; i < count; ++i) {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    reserved *= 2;
  }

  /// data[count++] = temp; /// doesn't work

  /* patched to work when pushing a Motor created by default contructor */
  if(temp.getBrand()) {
    data[count++] = temp;
  }
  else {
    data[count++] = Motor("Unknown", temp.getManufactorYear(), temp.getEngineCapacity());
  }
}

int ListMotor::size() const {
  return count;
}

ListMotor &ListMotor::operator=(ListMotor const &temp) {
  Motor *newData = new Motor[reserved * 2];
  for (int i = 0; i < count; ++i) {
    newData[i] = temp.data[i];
  }
  delete[] data;
  data = newData;

  count = temp.count;
  reserved = temp.reserved;

  return *this;
}

std::ostream& operator<<(std::ostream& ostr, ListMotor& temp) {
  for(int i=0; i<temp.size(); ++i) {
    ostr << temp.data[i];
  }
  return ostr;
}
