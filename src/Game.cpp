#include "Game.h"

#include <SDL2/SDL.h>
#include <iostream>

Game::Game()
  : window(448*2, 496*2) {
}

void Game::run() {
  InputState inputState;
  while (!inputState.close) {
    processEvents(inputState);
    printInputState(inputState);
    pacMan.update(inputState, board);
    window.update(pacMan);
  }
}

void Game::printInputState(const InputState & inputState) {
  if (inputState.close)
    std::cout << "close\n";
  if (inputState.up)
    std::cout << "up\n";
  if (inputState.down)
    std::cout << "down\n";
  if (inputState.left)
    std::cout << "left\n";
  if (inputState.right)
    std::cout << "right\n";
}

void Game::processEvents(InputState & inputState) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        inputState.close = true;
        break;
      case SDL_KEYDOWN:
        keyToggle(event, inputState, true);
        break;
      case SDL_KEYUP:
        keyToggle(event, inputState, false);
        break;
    }
  }
}

void Game::keyToggle(const SDL_Event & event, InputState & inputState, bool on) {
  switch (event.key.keysym.sym) {
    case SDLK_UP:
      inputState.up = on;
      break;
    case SDLK_DOWN:
      inputState.down = on;
      break;
    case SDLK_LEFT:
      inputState.left = on;
      break;
    case SDLK_RIGHT:
      inputState.right = on;
      break;
  }
}
