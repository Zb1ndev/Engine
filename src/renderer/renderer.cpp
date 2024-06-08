#include <iostream>
#include <SDL2/SDL.h>

#include "renderer.h"

void Engine::RendererBase::Destroy() {
  SDL_GL_DeleteContext(this->glContext);
  SDL_DestroyRenderer(this->sdlRenderer);
}