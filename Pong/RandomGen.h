#ifndef RANDOMGEN_H
#define RANDOMGEN_H

#include <Clamp.h>

#include <chrono>
#include <random>

#include "Geometry.h"

class RandomGen {
 public:
  RandomGen(WindowGeom wg)
      : xrand{0, wg.WIDTH},
        yrand{0, wg.HEIGHT},
        xMidpoint(static_cast<int>(wg.WIDTH / 2)) {}

  unsigned int xGen();
  unsigned int yGen();

 private:
  std::mt19937 twister{static_cast<unsigned int>(
      std::chrono::steady_clock::now().time_since_epoch().count())};
  std::uniform_int_distribution<> xrand{};
  std::uniform_int_distribution<> yrand{};
std::uniform_int_distribution<> reacttime{1,20};
  int xMidpoint{};
};

#endif  // !RANDOMGEN_H
