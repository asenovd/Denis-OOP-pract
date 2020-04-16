#ifndef __CLASSIFICATION_HPP__
#define __CLASSIFICATION_HPP__

class Classification {
protected:
  double price;
  char* barcode;
  char* category;
public:
  Classification();
  Classification(double, const char*, const char*);
  void print();
};


#endif
