#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <stdio.h>

#include <string>

#include "EventManager.h"
#include "FontManager.h"
#include "GameObjects.h"
#include "Settings.h"

class Window {
 public:
  Window(WindowGeom wg, GameObjects* objectsP)
      : geom(wg),
        height_m(wg.HEIGHT),
        width_m(wg.WIDTH),
        objects(objectsP),
        eventmgr_m(objectsP) {}

  // state managers
  bool load();
  void loop();
  void close();

 private:
  GameObjects* objects = nullptr;
  int ticks_m{};
  WindowGeom geom;
  pix height_m{};
  pix width_m{};

  // pointers to SDL items
  SDL_Window* window_m = NULL;
  SDL_Renderer* renderer_m = NULL;
  SDL_Surface* surf_m = NULL;

  // window title
  std::string title_m = "Pong";

  // helper classes
  FontManager fontmgr_m;
  EventManager eventmgr_m;

  // loop flag
  bool run_M{true};

  void draw();
  void tick() { ticks_m = SDL_GetTicks(); };
  void videoinit(bool& success);
  void qualityinit(bool& success);
  void windowinit(bool& success, const char* title);
  void rendererinit(bool& success);
};
#endif