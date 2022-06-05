#ifndef SETTINGS_H
#define SETTINGS_H

#include "Geometry.h"

struct Settings {
  static const ms MoveInterval = 15;
  static const ms InitalDelay = 1000;
  static const pix MoveStep = 12;
  static const pix PaddleMoveStep = 25;
static const ms OppenentThinkTime = 200;
};

#endif  // !SETTINGS_H
