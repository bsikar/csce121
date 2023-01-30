#include <iostream>
#include <string>
using namespace std;

void PrintSalutation(string personName) {
  cout << "Hello, " << personName << endl;
}

void PrintSalutation(string personName, string customSalutation) {
  cout << customSalutation << ", " << personName << endl;
}

int main() {
  PrintSalutation("Holly", "Welcome");
  PrintSalutation("Sanjiv");

  return 0;
}
