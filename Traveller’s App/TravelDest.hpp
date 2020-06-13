#ifndef __TRAVELDB_HPP__
#define __TRAVELDB_HPP__

#include "Vector.cpp"
#include "Travels.hpp"

class TravelDest : public Vector<Travels*> {

public:
  TravelDest();
  ~TravelDest();
};

#endif
