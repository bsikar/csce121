#include "./string_calculator.h"
#include <iostream>
#include <sstream>

using std::cout, std::endl;
using std::string;

std::string add_extra_whitespace(const std::string &input) {
  std::string output;
  for (const char c : input) {
    if (c == '+' || c == '*') {
      output.push_back(' ');
      output.push_back(c);
      output.push_back(' ');
    } else {
      output.push_back(c);
    }
  }
  return output;
}

std::string remove_extra_whitespace(const std::string &input) {
  std::istringstream iss(input);
  std::ostringstream oss;
  std::string token;

  while (iss >> token) {
    oss << token << " ";
  }

  // Return the modified string with extra whitespace removed
  return oss.str().substr(0, oss.str().size() - 1);
}

std::string clean_input(const std::string &input) {
  return remove_extra_whitespace(add_extra_whitespace(input));
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
  // TODO: verify that a negative number works (it wont) e.g 12-1 would return
  // true when it should be false
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
std::string *input_parser(std::string &input) {
  input = clean_input(input);

  std::istringstream iss(input);
  std::string token;

  int size = 0;
  while (iss >> token) {
    ++size;
  }

  if (size != 3) {
    throw std::invalid_argument("invalid input");
  }

  std::string *tokens = new std::string[size];

  iss.clear();
  iss.seekg(0, std::ios::beg);

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

  return tokens;
}

string calculate(const string *s) {
  string opperator = s[0];
  string operand1 = trim_leading_zeros(s[1]);
  string operand2 = trim_leading_zeros(s[2]);
  delete[] s;

  if (opperator == "+") {
    return add(operand1, operand2);
  }

  if (opperator == "*") {
    return multiply(operand1, operand2);
  }

  throw std::invalid_argument("invalid operator");
}

unsigned int digit_to_decimal(char digit) {
  if (digit < '0' || digit > '9') {
    throw std::invalid_argument("not a digit");
  }

  return digit - '0';
}

char decimal_to_digit(unsigned int decimal) {
  if (decimal > 9) {
    throw std::invalid_argument("not a decimal");
  }

  return decimal + '0';
}

string trim_leading_zeros(string num) {
  // TODO
  return "";
}

string add(string lhs, string rhs) {
  // TODO
  return "";
}

string multiply(string lhs, string rhs) {
  // TODO
  return "";
}
