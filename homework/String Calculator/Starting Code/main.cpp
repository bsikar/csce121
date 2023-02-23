#include "./string_calculator.h"
#include <iostream>
#include <limits>
#include <string>

using std::cout, std::endl, std::cin;
using std::string;

int main() {
  cout << "String Calculator" << endl;
  cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;

  while (true) {
    cout << ">> ";
    string input;
    if (!getline(cin, input) || input == "q" || input == "quit") {
      break;
    }
    try {
      string result = calculate(input_parser(input));
      cout << result << endl;
    } catch (const std::exception &e) {
      cout << e.what() << endl;
    }
  }

  return 0;
}
