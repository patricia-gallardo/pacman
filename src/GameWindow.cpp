#include "GameWindow.h"

GameWindow::GameWindow(const Game & game) {
  window = std::unique_ptr<SDL_Window, SDLWindowDeleter>(SDL_CreateWindow(
    "Pacman",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    500,
    500,
    SDL_WINDOW_OPENGL));
}
