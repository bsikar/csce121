#include <iostream>
using namespace std;

int main() {
  int numProblems;
  int problemsRemaining;

  cin >> numProblems;

  problemsRemaining = 40 - numProblems;

  cout << problemsRemaining << endl;

  return 0;
}
