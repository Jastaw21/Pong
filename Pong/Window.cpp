#include "Window.h"

// state managers
bool Window::load() {
  bool success = true;
  auto title_l = title_m.c_str();
  videoinit(success);
  qualityinit(success);
  windowinit(success, title_l);
  rendererinit(success);
  fontmgr_m.init(success);
  return success;
}
void Window::close() {
  SDL_DestroyRenderer(this->renderer_m);
  SDL_DestroyWindow(this->window_m);
  window_m = nullptr;
  renderer_m = nullptr;
  objects = nullptr;
  fontmgr_m.close();
  SDL_Quit();
}
void Window::draw() {
  // clear screen with black
  SDL_SetRenderDrawColor(renderer_m, 0, 0, 0, 0);
  SDL_RenderClear(renderer_m);

  // draw the movable objects
  objects->draw(renderer_m, &fontmgr_m);

  // draw the vertical line
  SDL_SetRenderDrawColor(renderer_m, 255, 255, 255, 200);
  for (int i{5}; i < height_m; i += 10) {
    SDL_Rect dot = {static_cast<int>(width_m / 2), i, 4, 4};
    SDL_RenderFillRect(renderer_m, &dot);
  }
  SDL_RenderPresent(renderer_m);
}
void Window::loop() {
  while (run_M) {
    Uint64 start = SDL_GetPerformanceCounter();
    // while running - update ticks every loop
    tick();

    // handle events
    eventmgr_m.loop(run_M);
    // game objects loop
    objects->ball.move(ticks_m, &objects->player, &objects->opponent);
    objects->opponent.opponentMove(objects->ball.y, objects->ball.xstep,
                                   randon_m.scalerGen());

    // render loop
    draw();

    Uint64 end = SDL_GetPerformanceCounter();
    float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
    SDL_Delay(static_cast<Uint32>(floor(16.666f - elapsed)));
  }
  close();
}

// init functions
void Window::videoinit(bool& success) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL Video not initialised! SDL_Error: %s\n", SDL_GetError());
    success = false;
  }
}
void Window::qualityinit(bool& success) {
  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    printf("Linear textuure not working\n");
    success = false;
  }
}
void Window::windowinit(bool& success, const char* title) {
  window_m =
      SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       width_m, height_m, SDL_WINDOW_SHOWN);
  if (window_m == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    success = false;
  }
}
void Window::rendererinit(bool& success) {  // create the renderer
  renderer_m = SDL_CreateRenderer(window_m, -1, SDL_RENDERER_ACCELERATED);
  // check failure
  if (renderer_m == NULL) {
    printf("Renderer didn't start! Error: %s", SDL_GetError());
    success = false;
  }
}
