#include "Location.h"

XY operator+(XY left, XY right) {
  return XY(left.x_mem + right.x_mem, left.y_mem + right.y_mem);
}
XY operator-(XY left, XY right) {
  return XY(left.x_mem - right.x_mem, left.y_mem - right.y_mem);
}
XY operator*(XY left, XY right) {
  return XY(left.x_mem * right.x_mem, left.y_mem * right.y_mem);
}
XY operator/(XY left, XY right) {
  return XY(static_cast<int>(left.x_mem / right.x_mem),
            static_cast<int>(left.y_mem / right.y_mem));
}
XY operator*(XY left, int right) {
  return XY(left.x_mem * right, left.y_mem * right);
}
bool operator==(XY left, XY right) {
  return ((left.x_mem == right.x_mem) && (left.y_mem == right.y_mem));
}
XY XY::operator=(XY right) {
  this->x_mem = right.x_mem;
  this->y_mem = right.y_mem;
  return *this;
}
void XY::is(int x, int y) {
  x_mem = x;
  y_mem = y;
}
