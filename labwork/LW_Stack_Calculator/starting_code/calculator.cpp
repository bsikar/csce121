#include "functions.h"
#include <iostream>
#include <sstream>
#include <string>
using std::cin, std::cout, std::endl, std::string, std::istringstream;

int main() {
  // prompt user input
  cout << "Type RPN expression (end with '=')." << endl;
  cout << "> ";

  // rpn calculator
  Stack stack;
  string input;
  // loop until we get '='
  while (cin >> input) {
    if (isdigit(input[0]) || (input[0] == '-' && isdigit(input[1]))) {
      // convert string to int
      istringstream iss(input);
      int number;
      iss >> number;
      push(stack, number);
    } else if (input == "+" || input == "-" || input == "*" || input == "/" ||
               input == "^") {
      int num1 = pop(stack);
      int num2 = pop(stack);

      int result;
      if (input == "+") {
        result = num2 + num1;
      } else if (input == "-") {
        result = num2 - num1;
      } else if (input == "*") {
        result = num2 * num1;
      } else if (input == "/") {
        result = num2 / num1;
      } else {
        // expontenial
        result = 1;
        for (int i = 0; i < num1; i++) {
          result *= num2;
        }
      }
      // push result to stack
      push(stack, result);
    } else if (input == "=") {
      break;
    }
  }

  // print result
  cout << "Ans: " << pop(stack) << endl;
  delete[] stack.numbers;

  return 0;
}
