#include "Game.h"
#include "GameWindow.h"

extern "C" int main([[maybe_unused]] int argc, [[maybe_unused]] char * argv[]) {
  Game game;
  GameWindow window(game);
  game.run();
  return 0;
}
