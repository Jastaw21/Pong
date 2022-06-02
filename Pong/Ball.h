#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include <Vec2.h>

#include <iostream>

#include "Bounds.h"
#include "Clamp.h"
#include "Geometry.h"
#include "Paddle.h"
#include "Settings.h"
#include "Vec2.h"

class Ball : public SDL_Rect {
 public:
  Ball(WindowGeom wg, pix size = 8)
      : SDL_Rect{wg.WIDTH / 2 - (size / 2), wg.HEIGHT / 2, size, size},
        maxY_m(wg.HEIGHT - size),
        maxX_m(wg.WIDTH - size),
        size_m{size},
        target_M{0, 120},
        centre{wg.WIDTH / 2 - (size / 2), wg.HEIGHT / 2} {}

  // get
  Vec2 pos() { return Vec2(x, y); }
  pix xPos() { return x; }
  pix yPos() { return y; }
  pix maxX() { return maxX_m; }
  pix maxY() { return maxY_m; }
  // update
  void move(int tick, Paddle* player, Paddle* opponent);
  void ballDraw(SDL_Renderer* rendererP);

 private:
  const int r_m{255};
  const int g_m{255};
  const int b_m{255};
  int size_m{};
  int maxY_m{};
  int maxX_m{};
  Vec2 centre{0, 0};
  unsigned long long lastmovetick{0};
  bool stepsinit{false};
  int xstep{0};
  int ystep{0};
  Vec2 target_M;
  void initialiseSteps();
  Bounds hitDetector(Paddle* player, Paddle* opponent);
  void hitHandler(Bounds hitarea, Paddle* player, Paddle* opponent);
  int paddleHit(Paddle* player, Paddle* opponent);
  void resetBall();
};

#endif
