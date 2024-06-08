#pragma once

namespace Engine {

  #pragma region Vector2

    class Vector2 {
      public:

        float x;
        float y;

      public:

        Vector2();
        Vector2(float _value);
        Vector2(float _x, float _y);
        ~Vector2();

        static Vector2 Add(Vector2 _a, Vector2 _b);
        static Vector2 Sub(Vector2 _a, Vector2 _b);
        static Vector2 Mul(Vector2 _a, Vector2 _b);
        static Vector2 Div(Vector2 _a, Vector2 _b);
        static float Distance(Vector2 _a, Vector2 _b);
        // static float Dot(Vector2 _a, Vector2 _b);

    };

    class Vector2Int {
      public:

        int x;
        int y;

      public:

        Vector2Int();
        Vector2Int(int _value);
        Vector2Int(int _x, int _y);
        ~Vector2Int();

        static Vector2Int Add(Vector2Int _a, Vector2Int _b);
        static Vector2Int Sub(Vector2Int _a, Vector2Int _b);
        static Vector2Int Mul(Vector2Int _a, Vector2Int _b);
        static Vector2Int Div(Vector2Int _a, Vector2Int _b);
        static float Distance(Vector2Int _a, Vector2Int _b);
        // static float Dot(Vector2Int _a, Vector2Int _b);

    };
  
  #pragma endregion

}