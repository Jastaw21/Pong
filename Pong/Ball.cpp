#include "Ball.h"

// set

void Ball::move(int tick, Paddle* player, Paddle* opponent) {
  // give one second delay
  if (tick < 1000) {
    return;
  }

  // see if we've set the movements by step in each direction
  if (!stepsinit) {
    initialiseSteps();
  }
  if (tick - lastmovetick >
      Settings::MoveInterval)  // if enough ticks have passed
  {
    x += xstep;
    y += ystep;

    hitHandler(hitDetector(player, opponent), player, opponent);
    lastmovetick = tick;
  }
}


Bounds Ball::hitDetector(Paddle* player, Paddle* opponent) {
  paddleHit(player, opponent);
  bool xhit = (x <= 0 || x >= maxX_m) ? true : false;
  bool yhit = (y <= 0 || y >= maxY_m) ? true : false;
  if (!xhit && !yhit) {
    return Bounds::NONE;
  }
  if (xhit && !yhit) {
    return x <= 0 ? Bounds::LEFT : Bounds::RIGHT;
  }
  if (yhit && !xhit) {
    return y <= 0 ? Bounds::TOP : Bounds::BOTTOM;
  }
  if (y > 0) {
    return x > 0 ? Bounds::BOTTOMRIGHT : Bounds::BOTTOMLEFT;
  }
  return x > 0 ? Bounds::TOPRIGHT : Bounds::TOPLEFT;
}

void Ball::hitHandler(Bounds hitarea, Paddle* player, Paddle* opponent) {
  switch (hitarea) {
    case Bounds::TOP:
      ystep *= -1;
      break;
    case Bounds::LEFT:
      xstep *= -1;
      opponent->score();
      break;
    case Bounds::BOTTOM:
      ystep *= -1;
      break;
    case Bounds::RIGHT:
      xstep *= -1;
      player->score();
      break;
    case Bounds::NONE:
      break;
    case Bounds::TOPLEFT:
      xstep *= -1;
      ystep *= -1;
      break;
    case Bounds::BOTTOMLEFT:
      xstep *= -1;
      ystep *= -1;
      break;
    case Bounds::TOPRIGHT:
      xstep *= -1;
      ystep *= -1;
      break;
    case Bounds::BOTTOMRIGHT:
      xstep *= -1;
      ystep *= -1;
      break;
  }
}
int Ball::paddleHit(Paddle* player, Paddle* opponent) { return 0; }
void Ball::initialiseSteps() {
  int deltax = target_M.x() - x;
  int deltay = target_M.y() - y;
  double xscale = fabs(deltax) / (fabs(deltax) + fabs(deltay));
  double yscale = 1.0 - xscale;
  double xmov =
      deltax < 0.0 ? -Settings::MoveStep * xscale : Settings::MoveStep * xscale;
  double ymov =
      deltay < 0.0 ? -Settings::MoveStep * yscale : Settings::MoveStep * yscale;
  xstep = static_cast<int>(round(xmov));
  ystep = static_cast<int>(round(ymov));
  stepsinit = true;
}
void Ball::ballDraw(SDL_Renderer* rendererP) {
  SDL_SetRenderDrawColor(rendererP, r_m, g_m, b_m, 255);
  SDL_RenderFillRect(rendererP, this);
}