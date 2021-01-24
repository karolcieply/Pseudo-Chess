//
// Created by Karol on 30.12.2020.
//
#include <cmath>
#include "gamespace.h"
#ifndef MAIN_CPP_FIGURES_H
#define MAIN_CPP_FIGURES_H
class figures {
public:
  bool UserMove(int,int,int,int,int);
private:
  bool Pawn(int,int,int,int,int);
  bool Knight(int,int,int,int);
  bool King(int,int,int,int);
  bool Rook(int,int,int,int);
  bool Bishop(int,int,int,int);
  bool Queen(int,int,int,int);
};

#endif // MAIN_CPP_FIGURES_H
