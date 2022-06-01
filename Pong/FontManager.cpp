#include "FontManager.h"

bool FontManager::init() {
  if (TTF_Init() == -1) {
    printf("Error Initialising Font System. Error code %s\n", TTF_GetError());
    return false;
  } else {
    if (!loadfont()) {
      return false;
    }
  }
}
bool FontManager::loadfont() {
  font_ptr = TTF_OpenFont("bit5x3.ttf", font_size);
  if (!font_ptr) {
    printf("Couldn't open font: %s\n", TTF_GetError());
    return false;
  } else {
    return true;
  }
}


void FontManager::close() {
  TTF_CloseFont(font_ptr);
  font_ptr = nullptr;
  TTF_Quit();
}

void FontManager::draw(SDL_Renderer* rendererP, SDL_Rect& drawrect,
                       const char* score) {
  fontSurf = TTF_RenderUTF8_Blended(font_ptr, score, font_colour);
  texture = SDL_CreateTextureFromSurface(rendererP, fontSurf);
  SDL_RenderCopy(rendererP, texture, NULL, &drawrect);
  SDL_FreeSurface(fontSurf);
  SDL_DestroyTexture(texture);
}
