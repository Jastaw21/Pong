#include "RandomGen.h"

unsigned int RandomGen::xGen() {
  auto gen = xrand(twister);
  return gen < xMidpoint ? 0 : xMidpoint * 2;
}
unsigned int RandomGen::yGen() { return yrand(twister); }
double RandomGen::scalerGen() {
  auto gen = reacttime(twister);
  double scale = gen / 10.0;
  return clamp(scale, 0.9, 1.1);
}
