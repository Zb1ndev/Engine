#pragma once
#include <SDL2/SDL.h>

namespace Engine {

  class Input {
    public:

      typedef enum KeyCode {

        NONE,
        
        ESCAPE, RETURN, TAB, LEFT_SHIFT, RIGHT_SHIFT, 
        LEFT_CONTROL, RIGHT_CONTROL, LEFT_ALT, RIGHT_ALT, 
        BACKSPACE, SPACE, UP, DOWN, RIGHT, LEFT,

        ALPHA_1, ALPHA_2, ALPHA_3, ALPHA_4, ALPHA_5, 
        ALPHA_6, ALPHA_7, ALPHA_8, ALPHA_9, ALPHA_0,

        A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,
        P,Q,R,S,T,U,V,W,X,Y,Z

      } KeyCode;

    public:

      static bool PollInput();

      static int GetKeyCode();
      static bool GetKeyDown(int _key);
      static bool GetKeyUp(int _key);

      Input();
      ~Input();

    private:

      static SDL_Event m_event;

  };


}