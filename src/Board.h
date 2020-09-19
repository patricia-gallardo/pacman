#ifndef PACMAN_BOARD_H
#define PACMAN_BOARD_H

#include <SDL2/SDL_rect.h>
#include <cstdint>

const uint8_t ROWS = 31;
const uint8_t COLUMNS = 28;

class Board {
public:
  Board();

  [[nodiscard]] bool isWalkable(SDL_Point point) const;

private:
  uint8_t board_state[ROWS][COLUMNS];

  void resetBoardState();
};

#endif //PACMAN_BOARD_H
