#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int NUM_GUESSES = 3;
  vector<int> userGuesses(NUM_GUESSES);
  unsigned int i;

  for (i = 0; i < userGuesses.size(); ++i) {
    cin >> userGuesses.at(i);
  }

  for (i = 0; i < userGuesses.size(); ++i) {
    cout << userGuesses.at(i) << " ";
  }
  cout << endl;

  return 0;
}
