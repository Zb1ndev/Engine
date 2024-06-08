#include "math.h"
#include <cmath>

#pragma region Vector2

  Engine::Vector2::Vector2() {}
  Engine::Vector2::~Vector2() {}

  Engine::Vector2::Vector2(float _value){
    x = _value;
    y = _value;
  }
  Engine::Vector2::Vector2(float _x, float _y) {
    x = _x;
    y = _y;
  }

  Engine::Vector2 Engine::Vector2::Add(Engine::Vector2 _a, Engine::Vector2 _b) {
    return Vector2((_a.x + _b.x), (_a.y + _b.y));
  }
  Engine::Vector2 Engine::Vector2::Sub(Engine::Vector2 _a, Engine::Vector2 _b) {
    return Vector2((_a.x - _b.x), (_a.y - _b.y));
  }
  float Engine::Vector2::Distance(Engine::Vector2 _a, Engine::Vector2 _b) {
    return std::sqrt(((_a.x-_b.x)*(_a.x-_b.x)) + ((_a.y-_b.y)*(_a.y-_b.y)));
  }

#pragma endregion
#pragma region Vector2Int

  Engine::Vector2Int::Vector2Int() {}
  Engine::Vector2Int::~Vector2Int() {}

  Engine::Vector2Int::Vector2Int(int _value){
    x = _value;
    y = _value;
  }
  Engine::Vector2Int::Vector2Int(int _x, int _y) {
    x = _x;
    y = _y;
  }

  Engine::Vector2Int Engine::Vector2Int::Add(Engine::Vector2Int _a, Engine::Vector2Int _b) {
    return Vector2Int((_a.x + _b.x), (_a.y + _b.y));
  }
  Engine::Vector2Int Engine::Vector2Int::Sub(Engine::Vector2Int _a, Engine::Vector2Int _b) {
    return Vector2Int((_a.x - _b.x), (_a.y - _b.y));
  }
  float Engine::Vector2Int::Distance(Engine::Vector2Int _a, Engine::Vector2Int _b) {
    return std::sqrt(((_a.x-_b.x)*(_a.x-_b.x)) + ((_a.y-_b.y)*(_a.y-_b.y)));
  }

#pragma endregion