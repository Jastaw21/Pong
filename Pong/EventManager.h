#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <SDL.h>

class EventManager {
 public:
  void loop(bool& runflag);

 private:
  SDL_Event event_m;
  void keypress(SDL_Keycode keyPressed, bool& runflag);
};

#endif  // !EVENT_MANAGER_H
