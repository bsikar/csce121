#include <iostream>
using namespace std;

int main() {
  const int SCORES_SIZE = 4;
  int lowerScores[SCORES_SIZE];
  int i;

  for (i = 0; i < SCORES_SIZE; ++i) {
    cin >> lowerScores[i];
  }

  for (i = 0; i < SCORES_SIZE; ++i) {
    if (lowerScores[i] > 0) {
      lowerScores[i] = lowerScores[i] - 1;
    } else {
      lowerScores[i] = 0;
    }
  }

  for (i = 0; i < SCORES_SIZE; ++i) {
    cout << lowerScores[i] << " ";
  }
  cout << endl;

  return 0;
}
