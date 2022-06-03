#ifndef RANDOMGEN_H
#define RANDOMGEN_H

#include <chrono>
#include <random>

#include "Geometry.h"

class RandomGen {
 public:
  RandomGen(WindowGeom wg) : xrand{0, wg.WIDTH}, yrand{0, wg.HEIGHT} {}

 private:
  std::mt19937 twister{static_cast<unsigned int>(
      std::chrono::steady_clock::now().time_since_epoch().count())};
  std::uniform_int_distribution<> xrand{};
  std::uniform_int_distribution<> yrand{};
};

#endif  // !RANDOMGEN_H
