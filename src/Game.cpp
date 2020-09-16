#include "Game.h"

#include <SDL.h>

Game::Game() {
  SDL_Init(SDL_INIT_EVERYTHING);
}

void Game::run() {
  bool close = false;
  while (!close) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          close = true;
          break;
      }
    }
  }
}
