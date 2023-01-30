#include <iostream>
using namespace std;

int main() {
  int numRows;
  int numColumns;
  int currentRow;
  char currentRowLetter;
  int currentColumn;
  int currentColumnInteger;

  cin >> numRows;
  cin >> numColumns;

  for (currentRow = 1; currentRow <= numRows; currentRow++) {
    currentRowLetter = 'A' + currentRow - 1;
    for (currentColumn = 1; currentColumn <= numColumns; currentColumn++) {
      currentColumnInteger = currentColumn;
      cout << currentRowLetter << currentColumnInteger << " ";
    }
  }

  cout << endl;

  return 0;
}
