#ifndef PACMAN_GAMEWINDOW_H
#define PACMAN_GAMEWINDOW_H

#include <memory>

#include <SDL2/SDL.h>

struct SDL_Window_Deleter {
  void operator()(SDL_Window * window) {
    SDL_DestroyWindow(window);
  }
};

struct SDL_Renderer_Deleter {
  void operator()(SDL_Renderer * renderer) {
    SDL_DestroyRenderer(renderer);
  }
};

struct SDL_Surface_Deleter {
  void operator()(SDL_Surface * surface) {
    SDL_FreeSurface(surface);
  }
};

struct SDL_Texture_Deleter {
  void operator()(SDL_Texture * texture) {
    SDL_DestroyTexture(texture);
  }
};

class GameWindow {
public:
  explicit GameWindow(int width, int height);
  void update();

private:
  std::unique_ptr<SDL_Window, SDL_Window_Deleter> window;
  std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter> renderer;
  std::unique_ptr<SDL_Surface, SDL_Surface_Deleter> window_surface;
  void exitFailure(std::string message) const;
  void exitImgFailure(std::string message) const;
};

#endif //PACMAN_GAMEWINDOW_H
