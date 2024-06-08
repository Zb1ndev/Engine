#pragma once
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "../math/math.h"

namespace Engine {

  /*
    RendererBase will contain virtual utility functions for drawing certain things
    such as [ Rectangles, Textures, Text, Meshes ]. All of which will be "Not Implemented"
    by default. Derived classes will implement them ( if possible ) using their respective APIs 
  */

  typedef struct BitMapFont {
    const char* filePath;
  } BitMapFont;

  typedef struct TTFont {
    const char* filePath;
  } TTFont;

  typedef struct Rect {
    int x, y;
    int w, h;
    int r,g,b,a;
  } Rect;

  typedef struct Texture {
    const char* filePath;
    int x, y;
  } Texture;
  
  typedef struct Mesh {
    std::vector<float> vertices;
    std::vector<uint> indecies;
  } Mesh;

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

      virtual void DrawRectangle(Rect* _rect) { std::cout << "| Not Implemented" << '\n'; }
      virtual void DrawTexture(Texture* _texture) { std::cout << "| Not Implemented" << '\n'; }
      virtual void DrawMesh(Mesh* _mesh) { std::cout << "| Not Implemented" << '\n'; }
      virtual void DrawBitMapText(const char* _text, float _scale, Vector2 _position, BitMapFont* _font) 
      { std::cout << "| Not Implemented" << '\n'; }
      virtual void DrawTTFText(const char* _text, float _scale, Vector2 _position, TTFont* _font) 
      { std::cout << "| Not Implemented" << '\n'; }

      void Destroy();

  };

  class SDLRenderer : public RendererBase {
    public:

      #pragma region Constructor / Destructor

        SDLRenderer(SDL_Renderer* _renderer, SDL_Surface* _surface, SDL_Window* _window) {
          this->sdlRenderer = _renderer;
          this->window = _window;
          this->screenSurface = _surface;
        }
        ~SDLRenderer() {}

      #pragma endregion
      #pragma region Renderer Defenitions

        void Clear() override {
          SDL_SetRenderDrawColor(this->sdlRenderer, 20, 20, 20, 255);
          SDL_RenderClear(this->sdlRenderer);
        }
        void Draw() override {}
        void SwapBuffer() override {
          SDL_RenderPresent(this->sdlRenderer);
        }

      #pragma endregion
      #pragma region Renderer Utilities

        void DrawRectangle(Rect* _rect) override {
          SDL_Rect _sdlRect = {_rect->x,_rect->y,_rect->w,_rect->h};
          SDL_SetRenderDrawColor(this->sdlRenderer, _rect->r, _rect->g, _rect->b, _rect->a);
          SDL_RenderDrawRect(this->sdlRenderer, &_sdlRect);
        }
        void DrawTexture(Texture* _texture) override {}
        void DrawBitMapText(const char* _text, float _scale, Vector2 _position, BitMapFont* _font) override {}

      #pragma endregion

  };

  class OPENGLRenderer : public RendererBase {
    public:
      #pragma region Constructor / Destructor

        OPENGLRenderer(SDL_GLContext* _renderer, SDL_Window* _window) {
          this->glContext = _renderer;
          this->window = _window;
        }
        ~OPENGLRenderer() {}

      #pragma endregion 
      #pragma region Renderer Defenitions

        void Clear() override {}
        void Draw() override {}
        void SwapBuffer() override {}

      #pragma endregion
      #pragma region Renderer Utilities

        void DrawRectangle(Rect* _rect) override {}
        void DrawTexture(Texture* _texture) override {}
        void DrawBitMapText(const char* _text, float _scale, Vector2 _position, BitMapFont* _font) override {}
        void DrawMesh(Mesh* _mesh) override {}
        void DrawTTFText(const char* _text, float _scale, Vector2 _position, TTFont* _font) override {}

      #pragma endregion
 
  };


}