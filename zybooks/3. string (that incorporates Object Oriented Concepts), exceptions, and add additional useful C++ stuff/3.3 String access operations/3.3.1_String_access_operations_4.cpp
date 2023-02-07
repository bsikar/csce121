#include <iostream>
#include <string>
using namespace std;

int main() {
  string userString;
  string userName;

  getline(cin, userString);
  getline(cin, userName);

  userString += " " + userName + ".";

  cout << userString << endl;

  return 0;
}
