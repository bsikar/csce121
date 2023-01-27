#include <iostream>
using namespace std;

int main() {
  int numberOfPieces;
  int requiredGroups;
  int invalidGroups;

  cin >> numberOfPieces;
  cin >> requiredGroups;
  cin >> invalidGroups;

  if (numberOfPieces >= 18) {
    requiredGroups -= 3;
  } else {
    invalidGroups -= 1;
  }

  cout << requiredGroups << endl;
  cout << invalidGroups << endl;

  return 0;
}
