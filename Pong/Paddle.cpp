#include "Paddle.h"

void Paddle::up(int inc) {
  auto newY = rectangle_m.y - inc;
  rectangle_m.y = newY > 0 ? newY : 0;
}
void Paddle::down(int inc) {
  auto newY = rectangle_m.y + inc;
  rectangle_m.y = (newY + length_m) <= yMax ? newY : (yMax - length_m);
}

// position getters
int Paddle::x() { return rectangle_m.x; }
int Paddle::y() { return rectangle_m.y; }
int Paddle::maxX() { return xMax; }

// size getters
int Paddle::length() { return length_m; }
int Paddle::width() { return width_m; }
void Paddle::deflect(int& ystep, int ypos) {
  int relativeHeight = ypos - rectangle_m.y;
  double scale =
      static_cast<double>(relativeHeight) / static_cast<double>(rectangle_m.h);
  double manip = (scale - 0.5) * 2;
  auto locstep = ystep;
  ystep = static_cast<int>(3.5 * manip);
}

// bounds getters

int Player::maxY() { return (yMax - length_m); }
int Opponent::maxY() { return (yMax - length_m); }

void Opponent::opponentMove(int ypos, int xstep, double reaction) {
  if (ypos < rectangle_m.y) {
    // if we're moving in the same direction - no need for reaction time
    if (lastmoveUP) {
      up(5);
      lastdirectionchangetick = SDL_GetTicks();
      lastmoveUP = true;
      lastmoveDOWN = false;
    }

    // if we're changing directon - add some randomness
    else if (SDL_GetTicks() > lastdirectionchangetick +
                                  (Settings::OppenentThinkTime * reaction)) {
      up(5);
      lastdirectionchangetick = SDL_GetTicks();
      lastmoveUP = true;
      lastmoveDOWN = false;
    } else {
      lastdirectionchangetick = SDL_GetTicks();
      lastmoveUP = true;
      lastmoveDOWN = false;
    }
  }

  else if (ypos > rectangle_m.y + length_m) {
    if (lastmoveDOWN) {
      down(5);
      lastdirectionchangetick = SDL_GetTicks();
      lastmoveUP = false;
      lastmoveDOWN = true;
    }

    else if (SDL_GetTicks() >
             lastdirectionchangetick + (Settings::OppenentThinkTime * reaction))

    {
      down(5);
      lastdirectionchangetick = SDL_GetTicks();
      lastmoveUP = false;
      lastmoveDOWN = true;
    }

    else {
      lastdirectionchangetick = SDL_GetTicks();
      lastmoveUP = false;
      lastmoveDOWN = true;
    }
  }
}

void Paddle::score() { score_m += 1; }

void Paddle::paddleDraw(SDL_Renderer* renderer_P, FontManager* fontmanager) {
  SDL_SetRenderDrawColor(renderer_P, r_m, g_m, b_m, 255);
  SDL_RenderFillRect(renderer_P, &rectangle_m);
  std::string s = std::to_string(score_m);
  const char* sd = s.c_str();
  fontmanager->draw(renderer_P, draw_rect, sd);
}
