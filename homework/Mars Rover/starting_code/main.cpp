#include "MyString.h"
#include <iostream>

using namespace std;

int main() {
  MyString s = MyString("ld!");
  cout << s << endl;
  cout << s.find("!") << endl;
}
