#include <iostream>
#include <string>
using namespace std;

int main() {
  string professorName;
  string courseName;

  cin >> professorName;
  getline(cin, courseName);

  cout << professorName << endl;
  cout << courseName << endl;

  return 0;
}
