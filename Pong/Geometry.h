#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <SDL_ttf.h>
using ms = uint16_t;
using pix = int16_t;

struct WindowGeom {
  const pix WIDTH = 640;
  const pix HEIGHT = 480;
};


enum class Bounds {
  TOP,
  LEFT,
  BOTTOM,
  RIGHT,
  NONE,
  TOPLEFT,
  BOTTOMLEFT,
  TOPRIGHT,
  BOTTOMRIGHT,
  PLAYER,
  OPPONENT
};

#endif