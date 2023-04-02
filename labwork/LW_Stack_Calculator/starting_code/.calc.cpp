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
    // if we get '=' then exit
    if (input == "=") {
      break;
    }

    // if we get a digit then add it to the stack
    if (isdigit(input[0])) {
      // convert string to int
      istringstream iss(input);
      int number;
      iss >> number;
      // push number to stack
      push(stack, number);
    } else {
      // if we get an operator then pop two numbers from the stack
      // and perform the operation
      int num1 = pop(stack);
      int num2 = pop(stack);
      int result;
      switch (input[0]) {
      case '+':
        result = num1 + num2;
        break;
      case '-':
        result = num1 - num2;
        break;
      case '*':
        result = num1 * num2;
        break;
      case '/':
        result = num1 / num2;
        break;
      default:
        cout << "Invalid operator: " << input[0] << endl;
        return 1;
      }
      // push result to stack
      push(stack, result);
    }
  }

  // print result
  cout << "Result: " << pop(stack) << endl;
  delete[] stack.numbers;

  return 0;
}
