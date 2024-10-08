// pong recreation Jack W Mar 2022

#include <SDL.h>

#include "Geometry.h"
#include "Paddle.h"
#include "Window.h"

WindowGeom wg;
GameObjects objects{wg};
Window window{wg, &objects};

// bit of a stub for now, but useful to extract this into a function for future
inline int init() {
  if (!window.load()) {
    return -1;
  }
  return 0;
}

int main(int argc, char* args[]) {
  if (init() >= 0) {
    window.loop();
  }
  window.close();  // destroy stuff
  return 0;
}