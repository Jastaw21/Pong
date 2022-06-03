#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <SDL.h>

#include "Ball.h"
#include "FontManager.h"
#include "Geometry.h"
#include "Paddle.h"

class GameObjects {
 public:
  GameObjects(WindowGeom wg) : player{wg}, opponent{wg}, ball{wg} {}

  Player player;
  Opponent opponent;
  Ball ball;

  void draw(SDL_Renderer* renderer, FontManager* fontmgr);
};

#endif
