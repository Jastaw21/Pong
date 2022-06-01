// simple class to hold two points

#ifndef LOCATION_H
#define LOCATION_H
class Vec2  {
 public:
  Vec2 (int x, int y) : x_mem(x), y_mem(y) {}

  // overloads
  friend Vec2  operator+(XY left, Vec2  right);
  friend Vec2  operator-(XY left, Vec2  right);
  friend Vec2  operator*(XY left, Vec2  right);
  friend Vec2  operator/(XY left, Vec2  right);
  friend Vec2  operator*(XY left, int right);
  friend bool operator==(XY left, Vec2  right);
  Vec2  operator=(XY right);

  // getters
  int x() { return x_mem; }
  int y() { return y_mem; }

  // setter
  void is(int x, int y);
  void x(int xP) { x_mem = xP; }
  void y(int yP) { y_mem = yP; }

 private:
  int x_mem{0};
  int y_mem{0};
};
#endif  // !1
