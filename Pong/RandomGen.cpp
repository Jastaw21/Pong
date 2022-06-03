#include "RandomGen.h"

unsigned int RandomGen::xGen() {
  auto gen = xrand(twister);
  return gen < xMidpoint ? 0 : xMidpoint * 2;
}
unsigned int RandomGen::yGen() { return yrand(twister); }
