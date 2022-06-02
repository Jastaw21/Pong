#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>

class FontManager {
 public:
  FontManager() {}
  ~FontManager() { close(); }

  bool init();
  bool loadfont();
  void close();
  void draw(SDL_Renderer* rendererP, SDL_Rect& drawrect, const char* score);

  TTF_Font* font_ptr = nullptr;
  SDL_Surface* fontSurf = nullptr;
  SDL_Texture* texture = nullptr;

 private:
  const SDL_Color font_colour{255, 255, 255};
  const int font_size{128};
};

#endif  // !FONT_MANAGER_H
