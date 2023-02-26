#include <iostream>
using namespace std;

void StartsWith(string userText, string userWord) {
  if (userText.find(userWord) == 0) {
    cout << userText << "%" << userWord << endl;
  } else {
    cout << "Not found." << endl;
  }
}

int main() {
  string inputString1;
  string inputString2;

  cin >> inputString1;
  cin >> inputString2;

  StartsWith(inputString1, inputString2);

  return 0;
}
