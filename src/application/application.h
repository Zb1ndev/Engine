#pragma once
#include <SDL2/SDL.h>

#include "../common.h"

namespace Engine {

  class Application {
    public: 

      static Application* instance;

      typedef enum RendererType {
        SDL, OPENGL
      } RendererType;

      SDL_Window* window;
      RendererBase* renderer;

    public:

      bool IsRunning() { return m_isRunning; }
      void SetIsRunning(bool _value) { m_isRunning = _value; }

      RendererType GetRenderer() { return m_rendererType; }
      void SetRenderer(RendererType _value) { m_rendererType = _value; }
      
      void Initialize(size_t _width, size_t _height, const char* _title, RendererType _type);
      void Run();
      void Quit();

      virtual void Start() {}
      virtual void Update() {}
      virtual void OnClose() {}

      Application();
      ~Application();

    private:

      bool m_isRunning;
      RendererType m_rendererType;
  
  };

}