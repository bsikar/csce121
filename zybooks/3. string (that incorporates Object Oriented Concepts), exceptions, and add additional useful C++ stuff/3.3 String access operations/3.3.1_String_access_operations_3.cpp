#include <iostream>
#include <string>
using namespace std;

int main() {
  string userInput1;
  string userInput2;
  string outString;

  getline(cin, userInput1);
  getline(cin, userInput2);

  if (userInput1.length() == userInput2.length()) {
    outString = "Same Length";
  } else if (userInput1.length() > userInput2.length()) {
    outString = userInput1;
  } else {
    outString = userInput2;
  }

  cout << outString << endl;

  return 0;
}
