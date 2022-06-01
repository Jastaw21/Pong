#include "Vec2.h"

Vec2 operator+(Vec2 left, Vec2  right) {
  return Vec2 (left.x_mem + right.x_mem, left.y_mem + right.y_mem);
}
Vec2 operator-(Vec2 left, Vec2  right) {
  return Vec2 (left.x_mem - right.x_mem, left.y_mem - right.y_mem);
}
Vec2 operator*(Vec2 left, Vec2  right) {
  return Vec2 (left.x_mem * right.x_mem, left.y_mem * right.y_mem);
}
Vec2 operator/(Vec2 left, Vec2  right) {
  return Vec2 (static_cast<int>(left.x_mem / right.x_mem),
            static_cast<int>(left.y_mem / right.y_mem));
}
Vec2 operator*(Vec2 left, int right) {
  return Vec2 (left.x_mem * right, left.y_mem * right);
}
bool operator==(Vec2 left, Vec2  right) {
  return ((left.x_mem == right.x_mem) && (left.y_mem == right.y_mem));
}
Vec2 Vec2 ::operator=(Vec2 right) {
  this->x_mem = right.x_mem;
  this->y_mem = right.y_mem;
  return *this;
}
void Vec2 ::is(int x, int y) {
  x_mem = x;
  y_mem = y;
}
