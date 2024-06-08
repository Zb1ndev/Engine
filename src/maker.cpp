#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string DIR = "/home/zbinden/Documents/Engine/";

#pragma region Command Line Interaction

  vector<string> commands;

  void RunCMDs() {

    string _buildCMD = "";
    size_t _cmdCount = commands.size();
    for (size_t c = 0; c < _cmdCount; c++) {
      _buildCMD += commands[c];
    }

    system(_buildCMD.c_str());
    system((DIR + "builds/engine").c_str());

  }

  void AddCMD(string _cmd) {
    commands.push_back((_cmd + (char)(0x20)));
  }

  void AddCMD(string _flag, string _args) {
    string _cmd = _flag + (char)(0x20) + _args + (char)(0x20);
    commands.push_back(_cmd);
  }

#pragma endregion

int main() {

  AddCMD("g++");
  AddCMD("-o", DIR + "builds/engine");

  AddCMD(DIR + "src/main.cpp");

  AddCMD(DIR + "src/application/application.cpp");
  AddCMD(DIR + "src/input/input.cpp");
  AddCMD(DIR + "src/math/math.cpp");
  AddCMD(DIR + "src/renderer/renderer.cpp");
  
  AddCMD("-l", "SDL2");
  AddCMD("-ldl");

  RunCMDs();

}