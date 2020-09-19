#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include "GameWindow.h"
#include "PacMan.h"

struct InputState {
  bool close = false;
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;
};

class Game {
public:
  Game();
  void run();

private:
  GameWindow window;
  PacMan pacMan;
  static void processEvents(InputState & inputState) ;
  static void keyToggle(const SDL_Event & event, InputState & inputState, bool on);
  static void printInputState(const InputState & inputState) ;
};

#endif //PACMAN_GAME_H
