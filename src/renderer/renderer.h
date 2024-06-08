#pragma once
#include <iostream>
#include <SDL2/SDL.h>

namespace Engine {

  class RendererBase {
    public:

      SDL_Window* window;

      SDL_GLContext glContext;

      SDL_Renderer* sdlRenderer;
      SDL_Surface* screenSurface;

    public:

      RendererBase(){}
      ~RendererBase(){}

      virtual void Clear() { std::cout << "| Not Implemented" << '\n'; }
      virtual void Draw() { std::cout << "| Not Implemented" << '\n'; }
      virtual void SwapBuffer() { std::cout << "| Not Implemented" << '\n'; }

      void Destroy();

  };

  class SDLRenderer : public RendererBase {
    public:

      SDLRenderer(SDL_Renderer* _renderer, SDL_Surface* _surface, SDL_Window* _window) {
        this->sdlRenderer = _renderer;
        this->window = _window;
        this->screenSurface = _surface;
      }
      ~SDLRenderer() {}

      void Clear() override {
        SDL_SetRenderDrawColor(this->sdlRenderer, 20, 20, 20, 255);
        SDL_RenderClear(this->sdlRenderer);
      }
      void Draw() override {

        /* Example of how rendering in SDL works :
          SDL_Rect _rect = {0,0,100,100};
          SDL_SetRenderDrawColor(this->sdlRenderer, 255, 255, 255, 255);
          SDL_RenderDrawRect(this->sdlRenderer, &_rect);
        */        

        

      }
      void SwapBuffer() override {
        SDL_RenderPresent(this->sdlRenderer);
      }


  };

  class OPENGLRenderer : public RendererBase {
    public:

      OPENGLRenderer(SDL_GLContext* _renderer, SDL_Window* _window) {
        this->glContext = _renderer;
        this->window = _window;
      }
      ~OPENGLRenderer() {}

      void Clear() override {
        
      }
      void Draw() override {
        
      }
      void SwapBuffer() override {
        
      }

  };


}