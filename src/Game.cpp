#include "Game.h"

#include <SDL2/SDL.h>
#include <iostream>

const int ROWS = 31;
const int COLUMNS = 28;

// Legend
// 0 - wall
// 1 - pellet
// 2 - nothing
// 3 - door
// 4 - superpower

// 16 pixels per square
// Maze in pixels - width: 448 - height - 496

static const int board[ROWS][COLUMNS] = {
// 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 0
  {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0}, // 1
  {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, // 2
  {0,4,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,4,0}, // 3
  {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, // 4
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, // 5
  {0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0}, // 6
  {0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0}, // 7
  {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0}, // 8
  {0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,1,0,0,0,0,0,0}, // 9
  {0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,1,0,0,0,0,0,0}, // 10
  {0,0,0,0,0,0,1,0,0,2,2,2,2,2,2,2,2,2,2,0,0,1,0,0,0,0,0,0}, // 11
  {0,0,0,0,0,0,1,0,0,2,0,0,0,3,3,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 12
  {0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 13
  {3,2,2,2,2,2,1,2,2,2,0,0,0,0,0,0,0,0,2,2,2,1,2,2,2,2,2,3}, // 14
  {0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 15
  {0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 16
  {0,0,0,0,0,0,1,0,0,2,2,2,2,2,2,2,2,2,2,0,0,1,0,0,0,0,0,0}, // 17
  {0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 18
  {0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 19
  {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0}, // 20
  {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, // 21
  {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, // 22
  {0,4,1,1,0,0,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,0,0,1,1,4,0}, // 23
  {0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0}, // 24
  {0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0}, // 25
  {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0}, // 26
  {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0}, // 27
  {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0}, // 28
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, // 29
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 30
};

Game::Game()
  : window(448*2, 496*2) {
}

void Game::run() {
  InputState inputState;
  while (!inputState.close) {
    processEvents(inputState);
    printInputState(inputState);
    pacMan.update(inputState);
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
