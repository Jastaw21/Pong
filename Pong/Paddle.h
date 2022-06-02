#ifndef PADDLE_H
#define PADDLE_H
#include <SDL.h>

#include <vector>
#include <string>
#include <cstring>
#include <sstream>

#include "FontManager.h"
#include "Geometry.h"
#include "Vec2.h"

class Paddle {
 public:
  Paddle(WindowGeom wg, int xpos, int textXpos, int textYpos, int textSize,
         int width = 5, int length = 50)
      : pos(xpos, wg.HEIGHT - (length / 2)),
        length_m(length),
        width_m(width),
        rectangle_m{xpos, (wg.HEIGHT / 2) - (length / 2), width, length},
        yMax(wg.HEIGHT),
        xMax(wg.HEIGHT),
        draw_rect{textXpos, textYpos, textSize, textSize} {}

  SDL_Rect rectangle_m;

  // setters
  void up(int inc);
  void down(int inc);

  // getters
  int x();
  int y();
  virtual int maxX();
  virtual int maxY();
  int top();
  int bottom();
  int length();
  int width();

  // game functions
  bool hit(int xball, int yball);
  void score();
  void paddleDraw(SDL_Renderer* renderer_P, FontManager* fontmanager);

 public:
  SDL_Rect draw_rect;

 protected:
  int length_m;  // size
  int width_m;
  Vec2  pos;              // position
  const int r_m{255};  // colour
  const int g_m{255};
  const int b_m{255};
  int xMax;
  int yMax;

 protected:
  int score_m{0};
};

// basically just aliases at this point
class Player : public Paddle {
 public:
  Player(WindowGeom wg) : Paddle{wg, 10, 25, 15, 100} {}

  virtual int maxX();
  virtual int maxY();
};
class Opponent : public Paddle {
 public:
  Opponent(WindowGeom wg)
      : Paddle{wg, wg.WIDTH - (10 + 5), wg.WIDTH - 150, 15, 100}

  {}
  virtual int maxX();
  virtual int maxY();

  SDL_Rect draw_rect{};
};

#endif