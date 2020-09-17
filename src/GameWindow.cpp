#include "GameWindow.h"

#include <SDL2/SDL_image.h>
#include <iostream>

GameWindow::GameWindow(int width, int height) {
  initSDL();
  createWindow(width, height);
  createRenderer();
  setDrawColor();
  initSDLImage();
  createWindowSurface();
  renderMaze();
}

void GameWindow::renderMaze() const {
  SDL_RenderClear(renderer.get());

  auto surface = std::unique_ptr<SDL_Surface, SDL_Surface_Deleter>(IMG_Load("../../../maze.png"));
  if (!surface)
    exitImgFailure("Failed to load image");

  auto texture = std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>(SDL_CreateTextureFromSurface(renderer.get(), surface.get()));
  if (!texture)
    exitFailure("Failed to create texture from surface");

  if (SDL_RenderCopy(renderer.get(), texture.get(), nullptr, nullptr) < 0)
    exitFailure("Failed to copy texture to renderer");

  SDL_RenderPresent(renderer.get());
}

void GameWindow::createWindowSurface() {
  window_surface = std::unique_ptr<SDL_Surface, SDL_Surface_Deleter>(SDL_GetWindowSurface(window.get()));
  if (!window_surface)
    exitFailure("Failed to get the surface from the window");
}

void GameWindow::initSDLImage() const {
  int img_flags = IMG_INIT_PNG;
  if (!(IMG_Init(img_flags) & img_flags))
    exitImgFailure("Failed to init SDL_Image with png");
}

void GameWindow::initSDL() const {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    exitFailure("Failed to initialize the SDL2 library");
}

void GameWindow::setDrawColor() const {
  if (SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, SDL_ALPHA_OPAQUE) < 0)
    exitFailure("Failed to set renderer color");
}

void GameWindow::createRenderer() {
  renderer = std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter>(SDL_CreateRenderer(
    window.get(),
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

  if (!renderer)
    exitFailure("Failed to create renderer");
}

void GameWindow::createWindow(int width, int height) {
  window = std::unique_ptr<SDL_Window, SDL_Window_Deleter>(SDL_CreateWindow(
    "Pacman",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    width,
    height,
    SDL_WINDOW_OPENGL));

  if (!window)
    exitFailure("Failed to create window");
}

void GameWindow::update() {}

void GameWindow::exitFailure(std::string message) const {
  std::cerr << message << "\n";
  std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
  exit(1);
}

void GameWindow::exitImgFailure(std::string message) const {
  std::cerr << message << "\n";
  std::cerr << "SDL2_Image Error: " << IMG_GetError() << "\n";
  exit(1);
}
