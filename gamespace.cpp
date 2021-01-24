//
// Created by Karol on 03.12.2020.
//
#include "gamespace.h"
gamespace gs;
//funkcja rysująca plansze z figurami
void gamespace::WhiteShow(){
  blackPieces = whitePieces =0;
  cout<<"╔══A════B════C════D════E════F════G════H══╗"<<endl;
  for(int i=7;i>=0;i--){
    Show(i);
  }
  cout<<"╚══A════B════C════D════E════F════G════H══╝"<<endl;
}

void gamespace::BlackShow(){
  blackPieces = whitePieces =0;
  cout<<"╔══A════B════C════D════E════F════G════H══╗"<<endl;
  for(int i=0;i<8;i++){
    Show(i);
  }
  cout<<"╚══A════B════C════D════E════F════G════H══╝"<<endl;
}
void gamespace::Show(int i) {
  for (int y = 0; y < 3; y++) {
    for (int j = 0; j < 8; j++) {
      for (int x = 0; x < 5; x++) {
        if (j == 0 && x == 0) {
          if (y == 1)
            cout << i + 1;
          else
            cout << "║";
        }
        if (y == 1 && x == 2 && chessboard[i][j] != 0) {
          ShowPiece(chessboard[i][j]);
          if (chessboard[i][j] < 0)
            whitePieces++; // zliczam ilość białych i czarnych figur
          if (chessboard[i][j] > 0)
            blackPieces++;
        } else {
          if ((i + j) % 2 == 0) {
            cout << u8"\u2800";
            if ((j == 7 && x == 4)) {
              if (y == 1)
                cout << i + 1;
              else
                cout << "║";
            }
          } else {
            cout << u8"\u2588";
            if (j == 7 && x == 4) {
              if (y == 1)
                cout << i + 1;
              else
                cout << "║";
            }
          }
        }
      }
    }
    if (y != 2)
      cout << endl;
  }
  cout << endl;
}
//wypisanie figury
void gamespace::ShowPiece(int z) {
  switch (z) {
  case -1:
    cout << "♜";
    break;
  case -2:
    cout << "♞";
    break;
  case -3:
    cout << "♝";
    break;
  case -4:
    cout << "♛";
    break;
  case -5:
    cout << "♚";
    break;
  case -6:
    cout << "♟";
    break;
  case 1:
    cout << "♖";
    break;
  case 2:
    cout << "♘";
    break;
  case 3:
    cout << "♗";
    break;
  case 4:
    cout << "♕";
    break;
  case 5:
    cout << "♔";
    break;
  case 6:
    cout << "♙";
    break;
  }
}
bool gamespace::Save(string filename, bool whitemove) {
  filename ="saves/"+ filename+".txt";
  ofstream file(filename);
  if(!file.is_open())return 1;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      file << chessboard[i][j];
      if(j!=7)
        file << " ";
    }
    file <<"\n";
  }
  file << whitemove<<" "<< moveCounter <<"\n";
  for(int i=1;i<= moveCounter;i+=2){
    file << gameRecord[i-1] << " "<< gameRecord[i];
    if(i< moveCounter -2)file<<"\n";
  }
  file.close();
  return 0;
}
int gamespace::Load(string filename) {
  filename ="saves/"+ filename+".txt";
  ifstream file(filename);
  if(!file.is_open())return 2;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      file>>chessboard[i][j];
    }
  }
  file >> buffer;
  file >> moveCounter;
  for(int i=0;i< moveCounter;i++){
    file >> gameRecord[i];
  }
  for(int i= moveCounter;i<200;i++){
    gameRecord[i]="";
  }
  file.close();
  return buffer;
}
