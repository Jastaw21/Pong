#ifndef BALL_H
#define BALL_H

#include <SDL.h>

#include <iostream>

#include "Geometry.h"
#include "Location.h"
#include "Paddle.h"
#include "Clamp.h"

class Ball : public SDL_Rect {
 public:
  Ball(WindowGeom wg, pix size = 8)
      : SDL_Rect{wg.WIDTH / 2 - (size / 2), wg.HEIGHT / 2, size, size},
        maxY_M(wg.HEIGHT - size),
        maxX_M(wg.WIDTH - size),
        size_m{size},
        target{0, 120} {}

  // set
  void move(pix xP, pix yP);  // move with individual params
  void move(XY posP);         // pass a pos
  void move(int tick, int playerY,int opponentY, int size);        // main overload
  void resize(pix radius);    // will always be square
  void retarget(int xP, int yP);

  // get
  XY pos();
  pix xPos();
  pix yPos();
  pix size_get();
  pix maxX();
  pix maxY();

  // target for it to move towards
  XY target;

  Bounds hitDetector(int playerY, int opponentY, int size);  // hit detector function only


 private:
  const int r_m{255};
  const int g_m{255};
  const int b_m{255};

  int size_m{};
  int maxY_M{};
  int maxX_M{};
  // loop handlers
  unsigned long long lastmovetick{0};
  bool stepsinit{false};

  int xstep{0};
  int ystep{0};

  void initialiseSteps();
  void hitHandler(Bounds hitarea);
};

bool playerHit(int xpos, int ypos, int playerY, int playerSize);
bool opponnentHit(int xpos, int ypos, int opponnentY, int opponnentSize);

#endif
