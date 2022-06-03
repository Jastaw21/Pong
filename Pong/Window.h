// Main Window Implementation

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <stdio.h>

#include <iostream>
#include <string>

#include "EventManager.h"
#include "FontManager.h"
#include "GameObjects.h"
#include "Settings.h"

class Window {
 public:
  Window(WindowGeom wg, GameObjects* objectsP)
      : geom(wg), height_m(wg.HEIGHT), width_m(wg.WIDTH), objects(objectsP) {}

  ~Window() {
    close();
    surf_m = nullptr;
  }

  // getters

  SDL_Window* window() { return window_m; };
  SDL_Renderer* render() { return renderer_m; };

  // setters
  void heightset(pix heightP) { height_m = heightP; };
  void widthset(pix widthP) { width_m = widthP; };

  // state managers
  bool load();
  void close();
  void draw();
  void tick() { ticks_m = SDL_GetTicks(); };
  void loop();

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

  std::string title_m = "PONG";  // window title

  // helper classes
  FontManager fontmgr_m;
  EventManager eventmgr_m{};

  // loop flag
  bool run_M{true};
};
#endif