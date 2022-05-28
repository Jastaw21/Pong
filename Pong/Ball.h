#ifndef BALL_H
#define BALL_H

#include <SDL.h>

#include <iostream>

#include "Clamp.h"
#include "Geometry.h"
#include "Location.h"
#include "Settings.h"

class Ball : public SDL_Rect {
 public:
  Ball(WindowGeom wg, pix size = 8)
      : SDL_Rect{wg.WIDTH / 2 - (size / 2), wg.HEIGHT / 2, size, size},
        maxY_m(wg.HEIGHT - size),
        maxX_m(wg.WIDTH - size),
        size_m{size},
        target_M{0, 120} {}

  void move(int tick, int playerY, int opponentY, int size);
  // get
  XY pos();
  pix xPos();
  pix yPos();
  pix maxX();
  pix maxY();
  void ballDraw(SDL_Renderer* rendererP);

 private:
  const int r_m{255};
  const int g_m{255};
  const int b_m{255};
  int size_m{};
  int maxY_m{};
  int maxX_m{};

  unsigned long long lastmovetick{0};
  bool stepsinit{false};

  int xstep{0};
  int ystep{0};
  XY target_M;

  void initialiseSteps();
  void hitHandler(Bounds hitarea);
  Bounds hitDetector(int playerY, int opponentY, int size);
};

#endif
