#include "./string_calculator.h"
#include <iostream>
#include <sstream>

using std::cout, std::endl;
using std::string;

std::string remove_extra_whitespace(const std::string &input) {
  std::istringstream iss(input);
  std::ostringstream oss;
  std::string token;

  // Read each token from the input string and output it to the output stream
  while (iss >> token) {
    oss << token << " ";
  }

  // Return the modified string with extra whitespace removed
  return oss.str().substr(0, oss.str().size() - 1);
}

std::ostream &operator<<(std::ostream &os, const TokenType &e) {
  switch (e) {
  case TokenType::OPERATOR:
    os << "OPERATOR";
    break;
  case TokenType::OPERAND:
    os << "OPERAND";
    break;
  }
  return os;
}

TokenType get_token_type(const string &s) {
  bool is_neg = false;

  if (s.length() == 0) {
    throw std::invalid_argument("empty string");
  }

  if (s.length() == 1) {
    char c = s[0];

    if (c == '+' || c == '*') {
      return TokenType::OPERATOR;
    }

    if (c >= '0' && c <= '9') {
      return TokenType::OPERAND;
    }

    throw std::invalid_argument("not an operator");
  }

  for (char c : s) {
    if (c == '-' && is_neg) {
      throw std::invalid_argument("more than one negative sign");
    }

    if (c < '0' || c > '9') {
      throw std::invalid_argument("not a operator nor an operand");
    }

    if (c == '-') {
      is_neg = true;
    }
  }

  return TokenType::OPERAND;
}

// user is responsible for freeing the memory allocated for the array
std::string *input_parser(std::string &input, int size) {
  // Trim input for any whitespace
  // input = add_extra_whitespace(input);
  input = remove_extra_whitespace(input);

  // Create a istringstream object from the input string
  std::istringstream iss(input);
  std::string token;

  // Count the number of tokens in the input string
  size = 0;
  while (iss >> token) {
    ++size;
  }

  if (size != 3) {
    throw std::invalid_argument("invalid input");
  }

  // Allocate memory for the array of tokens
  std::string *tokens = new std::string[size];

  // Reset the istringstream object to the beginning of the string
  iss.clear();
  iss.seekg(0, std::ios::beg);

  // Read each token from the istringstream object and store it in the array
  int operands = 0;
  int operators = 0;
  while (iss >> token) {
    try {
      TokenType type = get_token_type(token);

      if (type == TokenType::OPERAND) {
        if (operands == 2) {
          throw std::invalid_argument("too many operands");
        }

        operands += 1;
        tokens[operands] = token;
      } else {
        tokens[0] = token;
        operators += 1;
      }

    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      delete[] tokens;
      throw std::invalid_argument("invalid input");
    }
  }

  if (operands != 2 || operators != 1) {
    delete[] tokens;
    throw std::invalid_argument("invalid input");
  }

  // Return the dynamically allocated array of tokens
  return tokens;
}

string calculate(string *s) { return ""; }

unsigned int digit_to_decimal(char digit) {
  // TODO(student): implement
  return 0;
}

char decimal_to_digit(unsigned int decimal) {
  // TODO(student): implement
  return '\0';
}

string trim_leading_zeros(string num) {
  // TODO(student): implement
  return "";
}

string add(string lhs, string rhs) {
  // TODO(student): implement
  return "";
}

string multiply(string lhs, string rhs) {
  // TODO(student): implement
  return "";
}
