#include <iostream>
#include <string>
using namespace std;

void MakeSentenceExcited(string &sentenceText) {
  // replace all `.` with `!`
  for (int i = 0; i < sentenceText.size(); ++i) {
    if (sentenceText[i] == '.') {
      sentenceText[i] = '!';
    }
  }
}

int main() {
  string testStr;

  getline(cin, testStr);
  MakeSentenceExcited(testStr);
  cout << testStr;

  return 0;
}
