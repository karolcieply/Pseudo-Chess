//
// Created by Karol on 03.12.2020.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H
#include "gamespace.h"
#include "figures.h"
#include <fstream>
class game {
public:
  int Start();
  bool whiteMove=true;
private:
  bool rotate=true;
  string userInput;
  int CharToInt(char);
  int InputHandler(bool);
  int InputCheck(string, bool);
  string fileName;
  int help;
};
#endif // UNTITLED_GAME_H
