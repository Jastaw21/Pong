#include "GameObjects.h"

void GameObjects::draw(SDL_Renderer* renderer, FontManager* fontmgr) {
  player.paddleDraw(renderer, fontmgr);
  opponent.paddleDraw(renderer, fontmgr);
  ball.ballDraw(renderer);
}
