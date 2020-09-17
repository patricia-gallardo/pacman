#include "GameWindow.h"

#include <iostream>

GameWindow::GameWindow(int width, int height) {

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    exitFailure("Failed to initialize the SDL2 library");

  window = std::unique_ptr<SDL_Window, SDLWindowDeleter>(SDL_CreateWindow(
    "Pacman",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    width,
    height,
    SDL_WINDOW_OPENGL));

  if (!window)
    exitFailure("Failed to create window");

  renderer = std::unique_ptr<SDL_Renderer, SDLRendererDeleter>(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

  if (!renderer)
    exitFailure("Failed to create renderer");

  if (SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255) < 0)
    exitFailure("Failed to set renderer color");

  SDL_Surface * window_surface = SDL_GetWindowSurface(window.get());

  if (!window_surface)
    exitFailure("Failed to get the surface from the window");
}

void GameWindow::update() {
  if (SDL_UpdateWindowSurface(window.get()) < 0)
    exitFailure("Failed to update window surface");
}

void GameWindow::exitFailure(const char * message) const {
  std::cout << message << "\n";
  std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
  exit(1);
}
