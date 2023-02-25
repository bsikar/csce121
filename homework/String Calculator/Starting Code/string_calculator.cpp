#include "./string_calculator.h"
#include <iostream>
#include <sstream>

using std::cout, std::endl;
using std::string;

string add_extra_whitespace(const string &input) {
  string output;
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

string remove_extra_whitespace(const string &input) {
  std::istringstream iss(input);
  std::ostringstream oss;
  string token;

  while (iss >> token) {
    oss << token << " ";
  }

  // return the modified string with extra whitespace removed
  return oss.str().substr(0, oss.str().size() - 1);
}

string clean_input(const string &input) {
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
  bool is_neg = false;

  if (s.length() == 0) {
    throw std::invalid_argument("empty string");
  }

  if (s.length() == 1) {
    char c = s[0];

    if (c == '+' || c == '*' || c == '-') {
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

    if (c == '-') {
      is_neg = true;
    }

    if ((c < '0' || c > '9') && c != '-') {
      throw std::invalid_argument("not a operator nor an operand");
    }
  }

  return TokenType::OPERAND;
}

// user is responsible for freeing the memory allocated for the array
string *input_parser(string &input) {
  input = clean_input(input);

  std::istringstream iss(input);
  string token;

  int size = 0;
  while (iss >> token) {
    ++size;
  }

  if (size != 3) {
    throw std::invalid_argument("invalid input");
  }

  string *tokens = new string[size];

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
      throw std::invalid_argument("Invalid LHS");
    }
  }

  if (operands != 2 || operators != 1) {
    delete[] tokens;
    throw std::invalid_argument("Invalide RHS");
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

  if (opperator == "-") {
    return subtract(operand1, operand2);
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
  if (num.length() == 0) {
    return num;
  }

  bool is_neg = false;
  if (num[0] == '-') {
    is_neg = true;
    num = num.substr(1);
  }

  unsigned int i = 0;
  while (num[i] == '0') {
    ++i;
  }

  if (i == num.length()) {
    return "0";
  }

  string res = num.substr(i, num.length() - i);

  if (is_neg && res != "0") {
    res = "-" + res;
  }

  return res;
}

string subtract(string lhs, string rhs) {
  lhs = trim_leading_zeros(lhs);
  rhs = trim_leading_zeros(rhs);

  if (lhs[0] == '-' && rhs[0] == '-') {
    return subtract(rhs.substr(1), lhs.substr(1));
  }

  if (lhs[0] == '-' && rhs[0] != '-') {
    return "-" + add(lhs.substr(1), rhs);
  }

  if (lhs[0] != '-' && rhs[0] == '-') {
    return add(lhs, rhs.substr(1));
  }

  if (lhs.length() < rhs.length() ||
      (lhs.length() == rhs.length() && lhs < rhs)) {
    return "-" + subtract(rhs, lhs);
  }

  string result;
  int carry = 0;

  for (int i = lhs.length() - 1, j = rhs.length() - 1; i >= 0; --i, --j) {
    int sub = digit_to_decimal(lhs[i]) - carry;

    if (j >= 0) {
      sub -= digit_to_decimal(rhs[j]);
    }

    if (sub < 0) {
      sub += 10;
      carry = 1;
    } else {
      carry = 0;
    }

    result = decimal_to_digit(sub) + result;
  }

  return trim_leading_zeros(result);
}

string add(string lhs, string rhs) {
  lhs = trim_leading_zeros(lhs);
  rhs = trim_leading_zeros(rhs);

  if (lhs[0] == '-' && rhs[0] == '-') {
    return "-" + add(lhs.substr(1), rhs.substr(1));
  }

  if (lhs[0] == '-' && rhs[0] != '-') {
    return subtract(rhs, lhs.substr(1, lhs.length() - 1));
  }

  if (lhs[0] != '-' && rhs[0] == '-') {
    return subtract(lhs, rhs.substr(1, rhs.length() - 1));
  }

  string result = "";
  int carry = 0;

  int i = lhs.length() - 1;
  int j = rhs.length() - 1;

  while (i >= 0 || j >= 0 || carry > 0) {
    int val = carry;

    if (i >= 0) {
      val += digit_to_decimal(lhs[i]);
      i -= 1;
    }

    if (j >= 0) {
      val += digit_to_decimal(rhs[j]);
      j -= 1;
    }

    carry = val / 10;
    val = val % 10;

    result = decimal_to_digit(val) + result;
  }

  return result;
}

string multiply(string lhs, string rhs) {
  lhs = trim_leading_zeros(lhs);
  rhs = trim_leading_zeros(rhs);

  if (lhs == "0" || rhs == "0") {
    return "0";
  }

  bool negative = false;
  if (lhs[0] == '-') {
    negative = !negative;
    lhs = lhs.substr(1);
  }
  if (rhs[0] == '-') {
    negative = !negative;
    rhs = rhs.substr(1);
  }

  string result = "0";

  for (int i = rhs.length() - 1; i >= 0; --i) {
    string temp = "";

    int carry = 0;
    for (int j = rhs.length() - 1; j > i; --j) {
      temp += "0";
    }

    for (int j = lhs.length() - 1; j >= 0; --j) {
      int val = digit_to_decimal(rhs[i]) * digit_to_decimal(lhs[j]) + carry;
      carry = val / 10;
      val = val % 10;

      temp = decimal_to_digit(val) + temp;
    }

    if (carry > 0) {
      temp = decimal_to_digit(carry) + temp;
    }

    result = add(result, temp);
  }

  if (negative) {
    result = '-' + result;
  }

  return result;
}
