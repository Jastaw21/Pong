#include "EventManager.h"

void EventManager::loop(bool& run) {
  while (SDL_PollEvent(&event_m) != 0) {
    if (event_m.type == SDL_QUIT) {
      run = false;
    } else if (event_m.type == SDL_KEYDOWN) {
      keypress(event_m.key.keysym.sym, run);
    }
  }
}

void EventManager::keypress(SDL_Keycode keyPressed, bool& runflag) {
  switch (keyPressed) {
    case SDLK_ESCAPE: {
      runflag = false;
      break;
    }
    case SDLK_UP:
      objects_m->player.up(Settings::PaddleMoveStep);
      break;
    case SDLK_DOWN:
      objects_m->player.down(Settings::PaddleMoveStep);
      break;
    case SDLK_w:
      objects_m->player.up(Settings::PaddleMoveStep);
      break;
    case SDLK_s:
      objects_m->player.down(Settings::PaddleMoveStep);
      break;
    default:
      break;
  }
}
