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
  Window(WindowGeom wg, Player* playerP, Opponent* opponentP, Ball* ballP)
      : geom(wg),
        height_m(wg.HEIGHT),
        width_m(wg.WIDTH),
        player(playerP),
        opponent(opponentP),
        ball(ballP) {}

  ~Window() {
    close();
    surf_m = nullptr;
    player = nullptr;
    opponent = nullptr;
    ball = nullptr;
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

  // event handlers
  void keypressHandle(SDL_Keycode key);

  // game objects
  Player* player = nullptr;
  Opponent* opponent = nullptr;
  Ball* ball = nullptr;
  int ticks_m{};

 private:
  // dimensions
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