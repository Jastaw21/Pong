#include "Ball.h"

// set
void Ball::move(pix xP, pix yP) {
  x = xP;
  y = yP;
}
void Ball::move(XY posP) {
  x = posP.x();
  y = posP.y();
}
void Ball::move(int tick, int playerY, int opponentY, int size) {
  if (tick < 1000) [[unlikely]] {
    return;
  }
  // see if we've set the init for movements
  if (!stepsinit) [[unlikely]] {
    initialiseSteps();
  }
  if (tick - lastmovetick > Settings::MoveInterval) [[likely]] {
    x += xstep;
    y += ystep;
    hitHandler(hitDetector(playerY, opponentY, size));
    lastmovetick = tick;
  }
}
void Ball::resize(pix radius) {
  w = radius;
  h = radius;
}
void Ball::retarget(int xP, int yP) {
  target.x(clamp(0, maxX_M, xP));
  target.y(clamp(0, maxY_M, yP));
}

// get
XY Ball::pos() { return XY(x, y); }
pix Ball::xPos() { return x; }
pix Ball::yPos() { return y; }
pix Ball::size_get() { return w; }
pix Ball::maxX() { return maxX_M; }
pix Ball::maxY() { return maxY_M; }

Bounds Ball::hitDetector(int playerY, int opponentY, int size) {
  bool xhit = (x <= 0 || x >= maxX_M) ? true : false;
  bool yhit = (y <= 0 || y >= maxY_M) ? true : false;

  if (xhit || yhit) [[unlikely]]  // if we hit either
  {
    // if x and not y - find out if it's left or right
    if (xhit && !yhit) {
      return x <= 0 ? Bounds::LEFT : Bounds::RIGHT;
    }
    // if y and not x - is it top or bottom
    else if (yhit && !xhit) {
      return y <= 0 ? Bounds::TOP : Bounds::BOTTOM;
    }
    // if it's both corners at the same time
    else {
      if (y > 0) {
        return x > 0 ? Bounds::BOTTOMRIGHT : Bounds::BOTTOMLEFT;
      } else {
        return x > 0 ? Bounds::TOPRIGHT : Bounds::TOPLEFT;
      }
    }
  }
  return Bounds::NONE;
}
void Ball::initialiseSteps() {
  int deltax = target.x() - x;
  int deltay = target.y() - y;
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
void Ball::hitHandler(Bounds hitarea) {
  switch (hitarea) {
    case Bounds::TOP:
      ystep *= -1;
      break;
    case Bounds::LEFT:
      xstep *= -1;
      
      printf("Player Conceded\n");
      break;
    case Bounds::BOTTOM:
      ystep *= -1;
      break;
    case Bounds::RIGHT:
      xstep *= -1;
      printf("Opponent Conceded\n");
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

bool playerHit(int xpos, int ypos, int playerX, int playerY, int playerXSize,
               int platerYSize) {
  return false;
}
