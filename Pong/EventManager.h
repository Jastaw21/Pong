#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <SDL.h>

#include "GameObjects.h"
#include "Settings.h"

class EventManager {
 public:
  EventManager(GameObjects* objects) : objects_m(objects) {}

  void loop(bool& runflag);
  Uint32 get_ticks() { return ticks_elapsed; }

 private:
  SDL_Event event_m{};
  void keypress(SDL_Keycode keyPressed, bool& runflag);
  Uint32 ticks_elapsed{};
  void incrementTick() { ticks_elapsed = SDL_GetTicks(); }
  GameObjects* objects_m = nullptr;
};

#endif  // !EVENT_MANAGER_H
