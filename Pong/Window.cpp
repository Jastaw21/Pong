#include "Window.h"

// state managers
bool Window::load() {
  // success flag
  bool success = true;

  // convert title member variable to const char*
  auto title_l = title_m.c_str();

  // initialise video
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL Video not initialised! SDL_Error: %s\n", SDL_GetError());
    success = false;
    return success;
  }
  // set quality
  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    printf("Linear textuure not working\n");
  }
  // create window
  window_m = SDL_CreateWindow(title_l, SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, width_m, height_m,
                              SDL_WINDOW_SHOWN);

  // see if the window failed - exit early if so
  if (window_m == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    success = false;
    return success;
  }

  // create the renderer
  renderer_m = SDL_CreateRenderer(window_m, -1, SDL_RENDERER_ACCELERATED);
  // check failure
  if (renderer_m == NULL) {
    printf("Renderer didn't start! Error: %s", SDL_GetError());
    success = false;
    return success;
  }
  // init SDL_ttf lib
  if (!fontmgr_m.init()) {
    success = false;
    return success;
  }
  return success;
}

void Window::close() {
  SDL_DestroyRenderer(this->renderer_m);
  SDL_DestroyWindow(this->window_m);
  window_m = nullptr;
  renderer_m = nullptr;
  fontmgr_m.close();
  SDL_Quit();
}
void Window::draw() {
  // clear screen with black
  SDL_SetRenderDrawColor(renderer_m, 55, 55, 55, 0);
  SDL_RenderClear(renderer_m);

  fontmgr_m.draw(renderer_m, player->draw_rect, drawtext1);
  fontmgr_m.draw(renderer_m, opponent->draw_rect, drawtext2);
  player->paddleDraw(renderer_m);
  opponent->paddleDraw(renderer_m);
  // draw the vertical line
  SDL_SetRenderDrawColor(renderer_m, 255, 255, 255, 200);
  for (int i{5}; i < height_m; i += 10) {
    SDL_Rect dot = {static_cast<int>(width_m / 2), i, 4, 4};
    SDL_RenderFillRect(renderer_m, &dot);
  }
  // draw the ball
  SDL_SetRenderDrawColor(renderer_m, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer_m, ball);
  // draw all
  SDL_RenderPresent(renderer_m);
}
void Window::loop() {
  SDL_Event eventM;
  while (run_M) {
    // while running - update ticks every loop
    tick();

    while (SDL_PollEvent(&eventM) != 0) {
      if (eventM.type == SDL_QUIT) {
        // catch a quit and set the run flag to false to end at the next loop
        run_M = false;
      } else if (eventM.type = SDL_KEYDOWN) {
        keypressHandle(eventM.key.keysym.sym);
      }
    }
    ball->move(ticks_m, player->x(), opponent->x(), player->length());
    draw();
  }
  close();
}
void Window::keypressHandle(SDL_Keycode key) {
  switch (key) {
    case SDLK_ESCAPE: {
      run_M = false;
      break;
    }
    case SDLK_UP: {
      player->up(10);
      break;
    }
    case SDLK_DOWN: {
      player->down(10);
      break;
    }
    case SDLK_w: {
      player->up(10);
      break;
    }
    case SDLK_s: {
      player->down(10);
      break;
    }
    default:
      break;
  }
}