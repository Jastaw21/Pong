#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <SDL.h>

class EventManager {
 public:
  void loop(bool& runflag);
  Uint32 get_ticks() { return ticks_elapsed; }

 private:
  SDL_Event event_m;
  void keypress(SDL_Keycode keyPressed, bool& runflag);
  Uint32 ticks_elapsed{};
  void incrementTick() { ticks_elapsed = SDL_GetTicks(); }
};

#endif  // !EVENT_MANAGER_H
