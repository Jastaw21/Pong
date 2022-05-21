#ifndef SCOREBOX_H
#define SCOREBOX_H

#include <SDL.h>

#include "Geometry.h"
#include <SDL_ttf.h>

struct GeomInfo {
  static const pix thickness{10};
  static const pix length{40};
};

class ScoreBox : public SDL_Rect {
 public:
  ScoreBox(pix xP, pix yP, pix wP, pix hP) : SDL_Rect{xP, yP, wP, hP} {}

  int testX() { return x; }

 private:
};

#endif