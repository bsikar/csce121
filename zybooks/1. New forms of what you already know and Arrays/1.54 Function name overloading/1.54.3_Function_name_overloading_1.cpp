#include <iostream>
using namespace std;

void PrintGroupSize(string groupSize) {
  cout << "The group needs a room for " << groupSize << "." << endl;
}

void PrintGroupSize(int groupSize) {
  cout << "Number of people attending: " << groupSize << endl;
}

int main() {
  string sizeInWord;
  int sizeOfGroup;

  cin >> sizeInWord;
  cin >> sizeOfGroup;

  PrintGroupSize(sizeInWord);
  PrintGroupSize(sizeOfGroup);

  return 0;
}
