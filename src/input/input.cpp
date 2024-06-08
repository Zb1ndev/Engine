#include "./input.h"

#pragma region Constructor / Destructor

  Engine::Input::Input() {}
  Engine::Input::~Input() {}

#pragma endregion
#pragma region Static Members

  bool Engine::Input::PollInput() {
    SDL_PollEvent(&m_event);
    return (m_event.type != SDL_QUIT);
  }

  int Engine::Input::GetKeyCode() {
    return m_event.key.keysym.sym;
  }

  bool Engine::Input::GetKeyDown(int _key) {
    return (m_event.key.keysym.sym == _key);
  }

  bool Engine::Input::GetKeyUp(int _key) {
    if (m_event.type == SDL_KEYUP)
      return (m_event.key.keysym.sym == _key);
    return false;
  }

  SDL_Event Engine::Input::m_event;

#pragma endregion 