#include <iostream>
#include <string>
using namespace std;

int main() {
  string name;
  string message;
  cout << "Enter your name: ";
  getline(cin, name);
  cout << "Enter your message: ";
  getline(cin, message);
  cout << "Thanks, " << name << ", for your message: \"" << message << "\"";
  return 0;
}
