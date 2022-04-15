#pragma once
#include <SDL.h>

#include "Geometry.h"
#include "Location.h"

class Paddle {
 public:
  Paddle(WindowGeom wg, int xpos, int width = 5, int length = 90)
      : pos(xpos, wg.HEIGHT - (length / 2)),
        length_m(length),
        width_m(width),
        rectangle_m{xpos, (wg.HEIGHT / 2) - (length / 2), width, length},
        yMax(wg.HEIGHT),
        xMax(wg.HEIGHT) {}

  // position setters
  void move(XY newpos);
  void move(int X, int newY);
  void up(int inc);
  void down(int inc);

  // set size (testing only)
  void lengthSet(int length);

  // colour getters
  int r();
  int g();
  int b();

  // position getters
  int x();
  int y();
  virtual int maxX();
  virtual int maxY();
  int top();
  int bottom();

  // size getters
  int length();
  int width();

  // colour setters
  void colour(int rP, int gP, int bP);

  bool hit(int xball, int yball);

  SDL_Rect rectangle_m;  // rect for SDL to use needs to be public.
                         // Actually could just inherit this

 protected:
  int length_m;  // size
  int width_m;
  XY pos;        // position
  int r_m{255};  // colour
  int g_m{255};
  int b_m{255};
  int xMax;
  int yMax;

 protected:
  int8_t score{0};
};

// basically just aliases at this point
class Player : public Paddle {
 public:
  Player(WindowGeom wg) : Paddle{wg, 10} {}

  virtual int maxX();
  virtual int maxY();
};
class Opponent : public Paddle {
 public:
  Opponent(WindowGeom wg) : Paddle{wg, wg.WIDTH - (10 + 5)} {}
  virtual int maxX();
  virtual int maxY();
};

