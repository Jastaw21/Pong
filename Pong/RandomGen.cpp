#include "RandomGen.h"

unsigned int RandomGen::xGen() { return xrand(twister); }
unsigned int RandomGen::yGen() { return yrand(twister); }
