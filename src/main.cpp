#include <iostream>
#include <SDL2/SDL.h>
#include "common.h"

using namespace Engine;

#pragma region Test App

  class Sandbox : public Application {

    public:

      void Start() override {

      }

      void Update() override {

        if (Input::GetKeyDown(SDLK_ESCAPE))
          SetIsRunning(false);
      
      }

      void OnClose() override {}

      Sandbox() {}
      ~Sandbox() {}

    private:


 
  };

#pragma endregion

int main() {

  Sandbox* _app = new Sandbox();
  _app->Initialize(600,600,"Test",Application::RendererType::SDL);
  _app->Run();

}