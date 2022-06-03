#include "Ball.h"

void Ball::move(int tick, Paddle* player, Paddle* opponent) {
  // give one second delay
  if (tick < Settings::InitalDelay) {
    return;
  }

  // see if we've set the movements by step in each direction
  if (!stepsinit) {
    initialiseSteps();
  }
  if (tick - lastmovetick > delay)  // if enough ticks have passed
  {
    x += xstep;
    y += ystep;
    delay = 0;

    bounce(hitDetector(player, opponent), player, opponent);
    lastmovetick = tick;
  }
}
Bounds Ball::hitDetector(Paddle* player, Paddle* opponent) {
  // check player hit
  if (x <= (player->x() + player->width()) && y >= player->y() &&
      y <= (player->y() + player->length())) {
    return Bounds::PLAYER;
  }
  // chck opponent hit
  if (x >= (opponent->x() - w) && y >= opponent->y() &&
      y <= (opponent->y() + opponent->length())) {
    return Bounds::OPPONENT;
  }
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
void Ball::bounce(Bounds hitarea, Paddle* player, Paddle* opponent) {
  switch (hitarea) {
    case Bounds::TOP:
      ystep *= -1;
      break;
    case Bounds::LEFT:
      opponent->score();
      stepsinit = false;
      resetBall();
      break;
    case Bounds::BOTTOM:
      ystep *= -1;
      break;
    case Bounds::RIGHT:
      player->score();
      stepsinit = false;
      resetBall();
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
    case Bounds::PLAYER:
      xstep *= -1;
      player->deflect(ystep, y);
      break;
    case Bounds::OPPONENT:
      xstep *= -1;
      opponent->deflect(ystep, y);
      break;
  }
}

void Ball::resetBall() {
  x = centre.x();
  y = centre.y();
  delay = 1000;
  stepsinit = false;
}
void Ball::initialiseSteps() {
  target_M.x(static_cast<int>(randomGen.xGen()));
  target_M.y(static_cast<int>(randomGen.yGen()));
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