//
// Created by Karol on 03.12.2020.
//
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#ifndef UNTITLED_GAMESPACE_H
#define UNTITLED_GAMESPACE_H
class gamespace {
public:
  void WhiteShow();
  void BlackShow();
  int chessboard[8][8] = {-1, -2, -3, -4, -5, -3, -2, -1, // <0 biale bierki >0 czarne bierki
        -6, -6, -6, -6, -6, -6, -6, -6, //1 wieza 2 skoczek 3 goniec 4 krol 5 hetman 6 pion
        0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,
        6,  6,  6,  6,  6,  6,  6,  6,
        1,  2,  3,  4,  5,  3,  2,  1};
  bool Save(string, bool);
  int Load(string);
  int whitePieces=1;
  int blackPieces =1;
  int moveCounter =1;
  string gameRecord[200];
private:
  int buffer;
  void ShowPiece(int);
  void Show(int);
};
extern gamespace gs;
#endif // UNTITLED_GAMESPACE_H
