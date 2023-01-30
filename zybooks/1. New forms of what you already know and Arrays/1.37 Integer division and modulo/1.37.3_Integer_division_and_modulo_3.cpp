#include <iostream>
using namespace std;

int main() {
  int totalInches;
  int numYards;
  int numFeet;
  int numInches;

  cin >> totalInches;

  numYards = totalInches / 36;
  numFeet = (totalInches % 36) / 12;
  numInches = (totalInches % 36) % 12;

  cout << "Yards: " << numYards << endl;
  cout << "Feet: " << numFeet << endl;
  cout << "Inches: " << numInches << endl;

  return 0;
}
