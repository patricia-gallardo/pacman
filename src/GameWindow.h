#ifndef PACMAN_GAMEWINDOW_H
#define PACMAN_GAMEWINDOW_H

#include <memory>

#include <SDL2/SDL.h>

struct SDLWindowDeleter {
  void operator()(SDL_Window * window) {
    SDL_DestroyWindow(window);
  }
};

struct SDLRendererDeleter {
  void operator()(SDL_Renderer * renderer) {
    SDL_DestroyRenderer(renderer);
  }
};

class GameWindow {
public:
  explicit GameWindow(int width, int height);
  void update();

private:
  std::unique_ptr<SDL_Window, SDLWindowDeleter> window;
  std::unique_ptr<SDL_Renderer, SDLRendererDeleter> renderer;
  void exitFailure(const char * message) const;
};

#endif //PACMAN_GAMEWINDOW_H
