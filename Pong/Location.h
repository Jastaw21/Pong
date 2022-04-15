#pragma once

class XY {
 public:
  XY(int x, int y) : x_mem(x), y_mem(y) {}

  // overloads
  friend XY operator+(XY left, XY right);
  friend XY operator-(XY left, XY right);
  friend XY operator*(XY left, XY right);
  friend XY operator/(XY left, XY right);
  friend XY operator*(XY left, int right);
  friend bool operator==(XY left, XY right);
  XY operator=(XY right);

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
