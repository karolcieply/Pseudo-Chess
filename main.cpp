#include "game.h"
#include <fstream>
#include <unistd.h>
game g;
int main() {
  ifstream animationFile("animation.txt");
  string buffer{}, fileName{};
  if (animationFile.is_open()) {
    while (!animationFile.eof()) {
      system("clear");
      for (int i = 0; i < 5; i++) {
        getline(animationFile, buffer);
        cout << buffer << endl;
      }
      usleep(125000);
    }
    animationFile.close();
  }
  // animacja
  while (true) {
    cout << "Witaj w pseudo szachach co chcesz zrobić?\n\n";
    cout << "╔════════════════════╗";
    cout << "\n║1. Zacznij nową grę ║\n║2. Wczytaj grę      ║\n║3. Jak grać         ║\n║4. Wyjdź z programu ║\n";
    cout << "╚════════════════════╝\n";
    int i = 0;
    while (i > 4 || i < 1) {
      cin >> i;
    }
    // menu i pętla żeby użytkownik wpisał liczbę od 1 do 4
    system("clear");
    switch (i) {
      // case 1 - resetuje licznik ruchów i wczytuje pozycję startową
    case 1:
      g.whiteMove = gs.Load("Start");
      gs.moveCounter = 1;
      break;
    case 3:
      // Chciałem to wczytać z pliku ale nie mogłem tego skompilować?
      cout << "Pseudoszachy to wariant szachów w którym wygyrwa się poprzez zbicie wszystkich bierek przeciwnika\n"
              "Nie istnieje tutaj coś takiego jak szach albo mat a króla można zbić.\n"
              "Jest to gra na 2 osooby które wykonują ruchy na zmianę.\n\n"
              "Jak poruzają się figury?\n"
              "Król-może się poruszać o jedno pole w każdą stronę\n"
              "Wieża-porusza się w kształt + tak daleko jak chce ale nie może \"przeskoczyć\" nad inną figurą\n"
              "Goniec-porusza się w kształt x tak daleko jak chce ale nie może \"przeskoczyć\" nad inną figurą\n"
              "Hetman- porusza się tak jak wieża i goniec\n"
              "Skoczek- porusza się w kształcie L tzn 2 pola w jednym kierunku a potem jedno pole pod kątem prostym\n"
              "Pionek- może jechać tylko do przodu o jedno pole chyba że jest to jego pierwszy ruch wtedy może jechać o 2 pola\n"
              "Pionek- jako jedyna figura bije inaczej niż się porusza ponieważ bije jedno pole po skosie (tylko w przód)\n"
              "Pionek po dojściu na koniec szachownicy zmienia się w inną wybraną przez gracza figurę\n\n"
              "Ruchy wykonuje się poprzez wpisanie litery i numeru pola z którego chcemy sie ruszyć i tego na które chcemy jechać.\n"
              "Wszystko piszemy z małej i bez spacji, np. e2e4\n"
              "Powiadomienia i błędy będą wyświetlać się nad szachownicą\n"
              "Dostępne komendy to:\n"
              "save - zapisuje grę\n"
              "load - wczytuje grę\n"
              "record - pokazuje zapis partii (wykonane ruchy)\n"
              "rotation - włącza i wyłącza obracanie się szachownicy\n"
              "exit - wychodzi do menu głównego\n"
              "Wciśnij enter żeby wrócić do menu głównego\n";
      cin.ignore();
      cin.get();
      system("clear");
      continue;
    case 4:
      cout << "A może jeszcze jedna gra?\n";
      return 0;
    case 2:
      system("ls saves/");
      cout << "Podaj nazwę pliku (bez rozszerzenia)";
      cin >> fileName;
      int help = gs.Load(fileName);
      if (help == 2) {
        cout << "Nie udało się wczytać gry\n";
        continue;
      } else
        g.whiteMove = help;
    }
    switch (g.Start()) {
    case 0:
      cout << "Dziekuje za gre wygraly biale\n";
      break;
    case 1:
      cout << "Dziekuje za gre wygraly czarne\n";
      break;
    case 2:
      continue;
    }
  }
}
