//
// Created by Karol on 30.12.2020.
//

#include "figures.h"
// f-from w-where v-value xy-wspolrzedne
bool figures::UserMove(int fy,int fx, int wy,int wx,int fv){
  switch(abs(fv)){
  case 1:
    return Rook(fy, fx, wy, wx);
  case 2:
    return Knight(fy, fx, wy, wx);
  case 3:
    return Bishop(fy, fx, wy, wx);
  case 4:
    return Queen(fy, fx, wy, wx);
  case 5:
    return King(fy, fx, wy, wx);
  case 6:
    return Pawn(fy, fx, wy, wx, fv);
  default:
    return false;
  }
}
bool figures::Pawn(int fy,int fx, int wy,int wx,int fv){
  return  (fv * (fy - wy) >= 0 && //czy pionek jedzie do przodu bialy pionek to -6 i poruzaja sie np z 2 na 3 (2-3)*6=-1*-6>0 czarny np z 7 na 6 (7-6)*6>0
      (abs(fy - wy) == 1 || (abs(fy - wy) == 2 && (fy == 1 || fy == 6))) &&//abs-wartosc bezwzgledna sprawdzenie czy pole pionowo zmienia sie o 1 czy o 2 a jezeli o 2 to sprawdza czy stoi na polu nr 2/7
      ((fx == wx && gs.chessboard[wy][wx] == 0) || (abs(fy-wy)==1&&(abs(fx - wx) == 1) && gs.chessboard[wy][wx] != 0)));//sprawdzenie czy pion jedzie prosto i czy nic nie stoi na jego drodze albo czy bije po skosie figure
}
bool figures::Knight(int fy, int fx, int wy, int wx) {
  return ((abs(fy - wy)==2 && abs(fx - wx)==1) ||(abs(fy - wy)==1 && abs(fx - wx)==2));
}
bool figures::King(int fy, int fx, int wy, int wx) {
  return (abs(fy - wy)<=1 && abs(fx - wx)<=1);
}
bool figures::Rook(int fy,int fx,int wy,int wx){//pętla która sprawdza czy wieża nie przeskakuje nad inną bierką
    if(fx - wx ==0|| fy - wy ==0){
      while(fy != wy || fx != wx){
        if(fx < wx)
          fx++;
        else if(fx > wx)
          fx--;
        if(fy < wy)
          fy++;
        else if(fy > wy)
          fy--;
        if(wy == fy && wx == fx)return true;
        if(gs.chessboard[fy][fx]!=0) return false;
      }
    }
    return false;
}
bool figures::Bishop(int fy, int fx,int wy, int wx){//tak samo jak z wieżą
  if(abs(fy - wy)==abs(fx - wx)){
    while(fy != wy && fx != wx){
      if(fy < wy)
        fy++;
      else if(fy > wy)
        fy--;
      if(fx < wx)
        fx++;
      else if(fx > wx)
        fx--;
      if(wy == fy && fx == wx)return true;
      if(gs.chessboard[fy][fx]!=0) return false;
    }
  }
  return false;
}
bool figures::Queen(int fy,int fx,int wy,int wx){//hetman może poruszyć się jak wieża ALBO jak goniec
  return (Bishop(fy, fx, wy, wx)|| Rook(fy, fx, wy, wx));
}
