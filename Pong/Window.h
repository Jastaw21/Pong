// Main Window Implementation

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <stdio.h>

#include <iostream>
#include <string>

#include "Ball.h"
#include "FontManager.h"
#include "Geometry.h"
#include "Paddle.h"

// to hold objects in a struct
class GameObjects {
 public:
  GameObjects(WindowGeom wg) : geom(wg), player{wg}, opponent{wg}, ball{wg} {}
  WindowGeom geom;
  Player player;
  Opponent opponent;
  Ball ball;
};

class Window {
  // pass the game objects in as parameters to intialise the window object with
  // pointers to each of them. Default title
 public:
  Window(WindowGeom wg, Player* playerP, Opponent* opponentP, Ball* ballP,
         std::string title = "Main")
      : title_m(title),
        geom(wg),
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
  pix height() { return height_m; };
  pix width() { return width_m; };
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
  bool run_M{true};
  WindowGeom geom;
  pix height_m{};
  pix width_m{};
  SDL_Window* window_m = NULL;
  SDL_Renderer* renderer_m = NULL;
  SDL_Surface* surf_m = NULL;
  std::string title_m;
  FontManager fontmgr_m;
};
#endif