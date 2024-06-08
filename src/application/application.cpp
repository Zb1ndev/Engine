#include <iostream>
#include <SDL2/SDL.h>

#include "../common.h"

#pragma region Constructor / Destructor

  Engine::Application::Application() {}
  Engine::Application::~Application() {}

#pragma endregion
#pragma region Static Members

  Engine::Application* Engine::Application::instance;

#pragma endregion
#pragma region Public Members

  void Engine::Application::Initialize(size_t _width, size_t _height, const char* _title, RendererType _type) {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      printf("| SDL2 could not initialize \n");
      exit(1);
    }
      
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    window = SDL_CreateWindow(_title,0,0,_width,_height, SDL_WINDOW_OPENGL);
    if (window == nullptr) {
      printf("| Window could not be created \n");
      exit(1);
    }

    SDL_GLContext _glContext = SDL_GL_CreateContext(window);
    if (_glContext == nullptr) {
      printf("| OpenGL Context could not be created \n");
      exit(1);
    }
    SDL_Renderer* _sdlRenderer = SDL_CreateRenderer(window, -1, 0);
    if (_sdlRenderer == nullptr) {
      printf("| Renderer could not be created \n");
      exit(1);
    }
    SDL_Surface* _surface = SDL_GetWindowSurface(window);
    if (_sdlRenderer == nullptr) {
      printf("| Surface could not be created \n");
      exit(1);
    }

    SetRenderer(_type);
    if(_type == RendererType::SDL) {
      renderer = new Engine::SDLRenderer(_sdlRenderer, _surface, window);
    } else if(_type == RendererType::OPENGL) {
      renderer = new Engine::OPENGLRenderer(&_glContext, window);
    }
    
    SDL_SetWindowKeyboardGrab(window, SDL_TRUE);
    Application::instance = this;
    SetIsRunning(true);


  }

  void Engine::Application::Run() {

    this->Start();
    while (IsRunning()) {

      renderer->Clear();
      SetIsRunning(Input::PollInput());
      this->Update();
      renderer->Draw();
      renderer->SwapBuffer();

    }
    Quit();

  }

  void Engine::Application::Quit() {

    this->OnClose();
    renderer->Destroy();
    SDL_DestroyWindow(window);
    SDL_Quit();

  }

#pragma endregion

