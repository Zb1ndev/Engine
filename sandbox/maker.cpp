#include <iostream>
#include <vector>
#include <string>

using namespace std;

#pragma region Utilities

  vector<string> commands;

  void RunCMDs() {

    string _buildCMD = "";
    size_t _cmdCount = commands.size();
    for (size_t c = 0; c < _cmdCount; c++) {
      _buildCMD += commands[c];
    }
    cout << "| " + _buildCMD + '\n';
    system(_buildCMD.c_str());

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

  const string DIR = "/home/zbinden/Documents/Engine/";

  AddCMD("g++");
  AddCMD("-o", DIR + "builds/game");

  AddCMD(DIR + "sandbox/main.cpp");
  
  AddCMD("-l", "SDL2");
  AddCMD("-ldl");

  RunCMDs();

}