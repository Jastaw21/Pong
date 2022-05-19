// Main Window Implementation

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <stdio.h>

#include <iostream>
#include <string>

#include "Ball.h"
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
 public:
  Window(WindowGeom wg, Player* playerP, Opponent* opponentP, Ball* ballP,
         std::string title = "Main")
      : title_m(title),
        geom(wg),
        height_m(wg.HEIGHT),
        width_m(wg.WIDTH),
        player(playerP),
        opponent(opponentP),
        ball(ballP) {
  
  }

  ~Window() {
    close();
    surf_m = nullptr;
    player = nullptr;
    opponent = nullptr;
    ball = nullptr;
  }

  // getters
  pix height();
  pix width();
  double ratio();
  SDL_Window* window();
  SDL_Renderer* render();

  // setters
  void heightset(pix heightP);
  void widthset(pix widthP);

  // state managers
  bool load();
  void close();
  void draw();

  // loops
  void tick();
  void loop();

  // handlers
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
};
#endif