#include "Ball.h"

// set

void Ball::move(int tick, int playerY, int opponentY, int size) {
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
    hitHandler(hitDetector(playerY, opponentY, size));
    lastmovetick = tick;
  }
}

void Ball::retarget(int xP, int yP) {
  target_M.x(clamp(0, maxX_m, xP));
  target_M.y(clamp(0, maxY_m, yP));
}

// get
XY Ball::pos() { return XY(x, y); }
pix Ball::xPos() { return x; }
pix Ball::yPos() { return y; }
pix Ball::size_get() { return w; }
pix Ball::maxX() { return maxX_m; }
pix Ball::maxY() { return maxY_m; }

Bounds Ball::hitDetector(int playerY, int opponentY, int size) {
  bool xhit = (x <= 0 || x >= maxX_m) ? true : false;
  bool yhit = (y <= 0 || y >= maxY_m) ? true : false;

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

