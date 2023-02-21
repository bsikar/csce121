#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string player1, player2;
  char luckyLetter;
  int randomNum;

  cout << "Enter the name of player 1: ";
  cin >> player1;
  cout << "Enter the name of player 2: ";
  cin >> player2;

  srand(time(0));
  randomNum = rand() % 26 + 97;
  luckyLetter = randomNum;

  if (player1.find(luckyLetter) != string::npos &&
      player2.find(luckyLetter) == string::npos) {
    cout << "Player 1 wins the game!" << endl;
  } else if (player2.find(luckyLetter) != string::npos &&
             player1.find(luckyLetter) == string::npos) {
    cout << "Player 2 wins the game!" << endl;
  } else {
    cout << "The game is tied!" << endl;
  }

  return 0;
}
