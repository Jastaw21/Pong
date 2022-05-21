#ifndef BALL_H
#define BALL_H

#include <SDL.h>

#include <iostream>

#include "Clamp.h"
#include "Geometry.h"
#include "Location.h"


class Ball : public SDL_Rect {
 public:
  Ball(WindowGeom wg, pix size = 8)
      : SDL_Rect{wg.WIDTH / 2 - (size / 2), wg.HEIGHT / 2, size, size},
        maxY_m(wg.HEIGHT - size),
        maxX_m(wg.WIDTH - size),
        size_m{size},
        target_M{0, 120} {}

  // set
  void move(pix xP, pix yP);  // move with individual params
  void move(XY posP);         // pass a position resolved
  void move(int tick, int playerY, int opponentY, int size);  // main overload
  void resize(pix radius);  // will always be square
  void retarget(int xP, int yP);

  // get
  XY pos();
  pix xPos();
  pix yPos();
  pix size_get();
  pix maxX();
  pix maxY();

  Bounds hitDetector(int playerY, int opponentY,
                     int size);  // hit detector function only

 private:
  // properties (dimensions/colour)
  const int r_m{255};
  const int g_m{255};
  const int b_m{255};
  int size_m{};
  int maxY_m{};
  int maxX_m{};
  // loop handlers
  unsigned long long lastmovetick{0};
  bool stepsinit{false};

  // movement
  int xstep{0};
  int ystep{0};
  XY target_M;

  void initialiseSteps();
  void hitHandler(Bounds hitarea);
};

bool playerHit(int xpos, int ypos, int playerY, int playerSize);
bool opponnentHit(int xpos, int ypos, int opponnentY, int opponnentSize);

#endif
