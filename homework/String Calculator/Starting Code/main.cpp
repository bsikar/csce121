#include "./string_calculator.h"
#include <iostream>
#include <limits>
#include <string>

using std::cout, std::endl, std::cin;
using std::string;

int main() {
  cout << "String Calculator" << endl;
  cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;

  string ans = "";

  while (true) {
    cout << ">> ";
    string input;

    if (!getline(cin, input) || input == "q" || input == "quit") {
      break;
    }

    if (input.empty()) {
      continue;
    }

    try {
      // if input contains 'ans', replace it with the previous answer (if any)
      if (input.find("ans") != string::npos) {
        if (ans.empty()) {
          cout << "No previous answer" << endl;
          continue;
        }
        // replace all instances of 'ans' with the previous answer
        size_t pos = 0;
        while ((pos = input.find("ans", pos)) != string::npos) {
          input.replace(pos, 3, ans);
          pos += ans.length();
        }
      }

      string result = calculate(input_parser(input));
      ans = result;

      cout << endl << "ans =" << endl << endl;
      cout << "    " << result << endl << endl;
    } catch (const std::exception &e) {
      // if its a number make that the answer
      if (get_token_type(input) == TokenType::OPERAND) {
        ans = input;
        cout << endl << "ans =" << endl << endl;
        cout << "    " << ans << endl << endl;
      } else {
        cout << e.what() << endl;
      }
    }
  }
  cout << endl << "farvel!" << endl;

  return 0;
}
