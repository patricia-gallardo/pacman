#ifndef PACMAN_GAMEWINDOW_H
#define PACMAN_GAMEWINDOW_H

#include "Game.h"
#include <memory>

#include <SDL.h>

struct SDLWindowDeleter {
  void operator()(SDL_Window * window) {
    SDL_DestroyWindow(window);
  }
};

class GameWindow {
public:
  explicit GameWindow(const Game & game);

private:
  std::unique_ptr<SDL_Window, SDLWindowDeleter> window;
};

#endif //PACMAN_GAMEWINDOW_H
