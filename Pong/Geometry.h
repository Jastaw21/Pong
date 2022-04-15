#pragma once

using ms = uint16_t;
using pix = int16_t;

struct WindowGeom {
  const pix WIDTH = 640;
  const pix HEIGHT = 480;
};
struct Settings {
  static const ms MoveInterval = 25;
  static const ms InitalDelay = 1000;
  static const pix MoveStep = 6;
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