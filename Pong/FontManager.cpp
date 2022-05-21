#include "FontManager.h"

bool FontManager::init() {
  if (TTF_Init() == -1) {
    printf("Error Initialising Fonts. Error code %s\n", TTF_GetError());
    return false;
  } else {
    return true;
  }
}