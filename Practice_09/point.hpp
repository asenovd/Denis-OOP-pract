#ifndef __POINT_HPP__
#define __POINT_HPP__

class Point {
  int x;
  int y;
public:
  Point();
  Point(int, int);
  Point(Point const &);

  Point &operator=(Point const &);
  bool operator>(Point const &);
  bool operator==(Point const);
  friend std::ostream &operator<<(std::ostream &, Point const &);

  void setX(int);
  void setY(int);
  int getX() const;
  int getY() const;
};

#endif
