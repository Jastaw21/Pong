#include "Paddle.h"

// position setters
void Paddle::move(XY newpos) {
  rectangle_m.x = newpos.x();
  rectangle_m.y = newpos.y();
}
void Paddle::move(int xN, int yN) {
  rectangle_m.x = xN;
  rectangle_m.y = yN;
}
void Paddle::up(int inc) {
  auto newY = rectangle_m.y - inc;

  if (newY > 0)  // case where no concerns - y is above zero
  {
    rectangle_m.y = newY;
    return;
  } else  // case would take us past zero
  {
    rectangle_m.y = 0;  // set to bounds
    return;
  }
}
void Paddle::down(int inc) {
  auto newY = rectangle_m.y + inc;
  if (newY <= maxY()) {
    rectangle_m.y = newY;
  } else {
    rectangle_m.y = yMax - length_m;
    return;
  }
}

// set size
void Paddle::lengthSet(int lengthP) { length_m = lengthP; }

// colour getters
int Paddle::r() { return r_m; }
int Paddle::g() { return g_m; }
int Paddle::b() { return b_m; }

// position getters
int Paddle::x() { return rectangle_m.x; }
int Paddle::y() { return rectangle_m.y; }
int Paddle::maxX() { return xMax; }
int Paddle::maxY() { return yMax; }
int Paddle::top() { return rectangle_m.y; }
int Paddle::bottom() { return rectangle_m.y + length_m; }

// size getters
int Paddle::length() { return length_m; }
int Paddle::width() { return width_m; }

// colour setter
void Paddle::colour(int rP, int gP, int bP) {
  r_m = rP;
  g_m = gP;
  b_m = bP;
}

bool Paddle::hit(int xball, int yball) {
  return ((xball == pos.x()) && (yball <= (pos.y() + length_m)) &&
          (pos.y() >= pos.y()));
}

// bounds getters
int Player::maxX() { return xMax; }
int Player::maxY() { return (yMax - length_m); }
int Opponent::maxX() { return xMax - width_m; }
int Opponent::maxY() { return (yMax - length_m); }
