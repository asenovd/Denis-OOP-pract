#ifndef __MOTOR_HPP__
#define __MOTOR_HPP__


class Motor {
  char* brand;
  unsigned manufactorYear;
  double engineCapacity;
public:
  Motor();
  Motor(const char*, unsigned, double);
  Motor(Motor const &);
  ~Motor();
  Motor &operator=(Motor const &);
  bool operator==(Motor const &);
  friend std::ostream& operator<<(std::ostream&, Motor&);

  const char* getBrand() const;
  unsigned getManufactorYear() const;
  double getEngineCapacity() const;

  void setBrand(const char*);
  void setManufactorYear(unsigned);
  void setEngineCapacity(double);
};

#endif
