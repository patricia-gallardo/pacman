#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include "GameWindow.h"

class Game {
public:
  Game();
  void run();

private:
  GameWindow window;
  bool processEvents() const;
};

#endif //PACMAN_GAME_H
