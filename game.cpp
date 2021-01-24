//
// Created by Karol on 03.12.2020.
//
#include "game.h"
figures fg;
int game::Start() {
  while (gs.moveCounter <= 200) {
    if (whiteMove)
      cout << gs.moveCounter << ":ruch białych\n";
    if (!whiteMove)
      cout << gs.moveCounter << ":ruch czarnych\n";
    if (!whiteMove && rotate)
      gs.BlackShow();
    else
      gs.WhiteShow();
    if (!gs.whitePieces)
      return 1;
    if (!gs.blackPieces)
      return 0;
    switch (InputHandler(whiteMove)) {
    case 0:
      whiteMove = !whiteMove;
      break;
    case 2:
      cout << "Podaj nazwe pliku (bez rozszerzenia):";
      cin >> fileName;
      if (gs.Save(fileName, whiteMove))
        cout << "Nie udalo sie zapisac\n";
      else
        cout << "zapisano gre\n";
      break;
    case 3:
      cout << "Podaj nawe pliku (bez rozszerzenia):";
      system("ls saves");
      cin >> fileName;
      help = gs.Load(fileName);
      if (help == 2)
        cout << "Nie udalo sie wczytac\n";
      else
        whiteMove = help;
      break;
    case 4:
      cout << "  Białe Czarne" << endl;
      for (int i = 0; i < 50; i += 2) {
        if (!gs.gameRecord[i].empty())
          cout << i / 2 + 1 << ": " << gs.gameRecord[i] << " "
               << gs.gameRecord[i + 1];
        if (!gs.gameRecord[i + 50].empty())
          cout << "  " << i / 2 + 26 << ": " << gs.gameRecord[i + 50] << " "
               << gs.gameRecord[i + 51];
        if (!gs.gameRecord[i + 100].empty())
          cout << "  " << i / 2 + 51 << ": " << gs.gameRecord[i + 100] << " "
               << gs.gameRecord[i + 101];
        if (!gs.gameRecord[i + 150].empty())
          cout << "  " << i / 2 + 76 << ": " << gs.gameRecord[i + 150] << " "
               << gs.gameRecord[i + 151];
        cout << endl;
      }
      cout << "Wciśnij enter żeby wrócić do gry";
      cin.ignore();
      cin.get();
      system("clear");
      break;
    case 5:
      return 2;
    default:
      break;
    }
  }
  return 2;
}
int game::InputCheck(string u, bool wmove) {
  if (CharToInt(u[3]) == 404 || CharToInt(u[2]) == 404 ||
      CharToInt(u[0]) == 404 || CharToInt(u[1]) == 404) return 1; // czy ruch poza zakresem
  if ((wmove == 1 && (gs.chessboard[CharToInt(u[1])][CharToInt(u[0])]) >= 0)
      ||(wmove == 0 && (gs.chessboard[CharToInt(u[1])][CharToInt(u[0])] <= 0))) return 2; // czy gracz próbuje jechać nie swoją figurą
  if ((wmove == 1 && (gs.chessboard[CharToInt(u[3])][CharToInt(u[2])]) < 0)
      ||(wmove == 0 && (gs.chessboard[CharToInt(u[3])][CharToInt(u[2])] > 0))) return 3; // czy gracz próbuje bić swoja figure
  if (fg.UserMove(CharToInt(u[1]), CharToInt(u[0]), CharToInt(u[3]),
                  CharToInt(u[2]), gs.chessboard[CharToInt(u[1])][CharToInt(u[0])])){//wywołuję funkcję która sprawdza poprawność ruchu
    if (abs(gs.chessboard[CharToInt(u[1])][CharToInt(u[0])]) == 6 &&
        (CharToInt(u[3]) == 7||CharToInt(u[3]) == 0)) {//sprawdzam czy pionek nie dojeżdża na koniec szachownicy
      cout << "Na jaką figurę chcesz promować pionka?\n1-wieża\n2-skoczek\n3-goniec\n4-hetman\n5-król\n";
      int promotion{};
      while (promotion >= 6 || promotion < 1) {//gracz musi wpisać poprawną wartość
        cin >> promotion;
      }
      system("clear");
      if (whiteMove)
        promotion = -promotion;//jeżeli jadą białę to zmieniam to na wartość ujemną ponieważ białe w kodzie są wartościami ujemnymi
      gs.chessboard[CharToInt(u[3])][CharToInt(u[2])] = promotion;
    } else
      gs.chessboard[CharToInt(u[3])][CharToInt(u[2])] = gs.chessboard[CharToInt(u[1])][CharToInt(u[0])];
    gs.chessboard[CharToInt(u[1])][CharToInt(u[0])] = 0;
    return 0;
  }
  return 1;
}
int game::CharToInt(char l) {//funkcja która pobiera chara i zmienia go na odpowiedniego inta
  if (97 <= l && l <= 104)
    return int(l) - 97;
  else if (49 <= l && l <= 56)
    return int(l) - 49;
  return 404;
}
int game::InputHandler(bool wmove) {//funkcja do zarządzania danymi wpisanymi przez użytkownika
  cout << "Co chcesz zrobić: ";
  cin >> userInput;
  system("clear");
  if (userInput == "rotation") {
    rotate = !rotate;
    cout << "Zmieniłeś ustawienia obracania szachownicy\n";
    return 1;
  }
  if (userInput == "save")
    return 2;
  if (userInput == "load")
    return 3;
  if (userInput == "record")
    return 4;
  if (userInput == "exit")
    return 5;
  switch (InputCheck(userInput, wmove)) {
  case 0:
    gs.gameRecord[gs.moveCounter++ - 1] = userInput;
    return 0;
  case 1:
    cout << "Niepoprawny ruch albo zła komenda \n";
    break;
  case 2:
    cout << "Wykonaj ruch swoją figurą\n";
    break;
  case 3:
    cout << "Nie mozesz zbić swojej figury\n";
    break;
  }
  return 1;
}

