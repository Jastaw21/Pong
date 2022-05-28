#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include "Paddle.h"
#include "Geometry.h"
#include "Paddle.h"
#include "Ball.h"

class GameObjects {
 public:
  GameObjects(WindowGeom wg) : geom(wg), player{wg}, opponent{wg}, ball{wg} {}
  WindowGeom geom;
  Player player;
  Opponent opponent;
  Ball ball;
};


#endif
